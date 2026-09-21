#include "mspm0l1306_i2c.h"
#include "mspm0_reg_utils.h"

void i2c_reset(void){
    I2C->GPRCM.RSTCTL = (I2C_RSTCTL_KEY_UNLOCK_W | I2C_RSTCTL_RESETASSERT);
}

void i2c_power_enable(void){
    I2C->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | ENABLE);
}

void i2c_power_disable(void){
    I2C->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | DISABLE);
}

void i2c_set_clock_configuration(i2c_clock_t clock, i2c_clock_div_t divider){

    // Disable previous clock configs if there are any
    write_reg_bit(&I2C->CLKSEL, I2C_CLKSEL_BUSCLK_SEL_OFS, DISABLE);
    write_reg_bit(&I2C->CLKSEL, I2C_CLKSEL_MFCLK_SEL_OFS, DISABLE);

    switch (clock){
        case I2C_CLKSEL_BUSCLK:
            write_reg_bit(&I2C->CLKSEL, I2C_CLKSEL_BUSCLK_SEL_OFS, ENABLE);
        break;

        case I2C_CLKSEL_MFCLK:
        default:
            write_reg_bit(&I2C->CLKSEL, I2C_CLKSEL_MFCLK_SEL_OFS, ENABLE);
        break;
    }

    write_reg_field(&I2C->CLKDIV, I2C_CLKDIV_RATIO_OFS, I2C_CLKDIV_RATIO_WIDTH, divider);
}

static void i2c_set_scl_clk_speed(uint32_t clk_speed){

    if(clk_speed > 0x7F){
        clk_speed = 0x7F;
    }
    
    write_reg_field(&I2C->MASTER.MTPR, I2C_CTRP_TPR_OFS, I2C_CTRP_TPR_WIDTH, clk_speed);    
}

void i2c_set_baudrate(uint32_t clock_freq, uint32_t target_freq){

    if(target_freq == 0){
        return;
    }

    uint32_t tpr = (clock_freq / (target_freq * 10U)) - 1U;

    i2c_set_scl_clk_speed(tpr);
}

void i2c_set_addressing_mode(i2c_addr_mode_t addr_mode){

    write_reg_bit(&I2C->MASTER.MSA, I2C_CSA_CMODE_OFS, addr_mode);
}

void i2c_set_target(uint32_t address){

    write_reg_field(&I2C->MASTER.MSA, I2C_CSA_TADDR_OFS, I2C_CSA_TADDR_WIDTH, address);
}

void i2c_set_direction(i2c_direction_t direction){
    write_reg_bit(&I2C->MASTER.MSA, I2C_CSA_DIR_OFS, direction);
}

void i2c_send_controller_tx(uint8_t data){
    write_reg_field(&I2C->MASTER.MTXDATA, I2C_MTXDATA_VALUE_OFS, I2C_MTXDATA_VALUE_WIDTH, data);
}

uint8_t i2c_bus_is_busy(void){

    return read_reg_bit(&I2C->MASTER.MSR, I2C_CSR_BUSBSY_OFS);
}

uint8_t i2c_is_busy(void){

    return read_reg_bit(&I2C->MASTER.MSR, I2C_CSR_BUSY_OFS);
}

uint8_t i2c_had_error(void){

    return read_reg_bit(&I2C->MASTER.MSR, I2C_CSR_ERR_OFS);
}

uint8_t i2c_address_acked(void){

    return read_reg_bit(&I2C->MASTER.MSR, I2C_CSR_ADRACK_OFS) == 0;
}

static void i2c_trigger_transaction(uint32_t length, uint8_t ack, uint8_t stop, uint8_t start){

    write_reg_field(&I2C->MASTER.MCTR, I2C_CCTR_CBLEN_OFS, I2C_CCTR_CBLEN_WIDTH, length);
    write_reg_bit(&I2C->MASTER.MCTR, I2C_CCTR_ACK_OFS, ack);
    write_reg_bit(&I2C->MASTER.MCTR, I2C_CCTR_STOP_OFS, stop);
    write_reg_bit(&I2C->MASTER.MCTR, I2C_CCTR_START_OFS, start);

    write_reg_bit(&I2C->MASTER.MCTR, I2C_CCTR_BURSTRUN_OFS, ENABLE);
}

static uint8_t i2c_read_data(void){

    return read_reg_field(&I2C->MASTER.MRXDATA, I2C_MRXDATA_VALUE_OFS, I2C_MRXDATA_VALUE_WIDTH);
}

uint8_t i2c_send_byte(uint8_t data_addr, uint8_t data, uint8_t send_start, uint8_t send_stop){

    i2c_set_direction(I2C_DIR_TRANSMIT);
    i2c_send_controller_tx(data_addr);
    i2c_send_controller_tx(data);
    i2c_trigger_transaction(2, 0, send_stop, send_start);

    while(i2c_is_busy()) { }

    if(i2c_had_error()){
        return 0;
    }

    return 1;

}

uint8_t i2c_receive_byte(uint8_t ack, uint8_t send_start, uint8_t send_stop, uint8_t *out){

    i2c_set_direction(I2C_DIR_RECEIVE);
    i2c_trigger_transaction(1, ack, send_stop, send_start);


    while(i2c_is_busy()) { }

    if(i2c_had_error()){
        return 0;
    }

    *out = i2c_read_data();
    return 1;
}

void i2c_set_start(uint8_t value){
    write_reg_bit(&I2C->MASTER.MCTR, I2C_CCTR_START_OFS, value);
}   

void i2c_set_stop(uint8_t value){
    write_reg_bit(&I2C->MASTER.MCTR, I2C_CCTR_STOP_OFS, value);
}

void i2c_enable(void){
    write_reg_bit(&I2C->MASTER.MCR, I2C_CCR_ACTIVE_OFS, ENABLE);
}
void i2c_disable(void){
    write_reg_bit(&I2C->MASTER.MCR, I2C_CCR_ACTIVE_OFS, DISABLE);
}

uint8_t i2c_write_buffer(uint8_t mem_addr, const uint8_t *data, uint32_t length){

    i2c_set_direction(I2C_DIR_TRANSMIT);
    
    while(read_reg_field(&I2C->MASTER.MFIFOSR, I2C_CFIFOSR_TXFIFOCNT_OFS, I2C_CFIFOSR_TXFIFOCNT_WIDTH) == 0) { }
    i2c_send_controller_tx(mem_addr);

    for(uint32_t i = 0; i < length ; i++){
        while(read_reg_field(&I2C->MASTER.MFIFOSR, I2C_CFIFOSR_TXFIFOCNT_OFS, I2C_CFIFOSR_TXFIFOCNT_WIDTH) == 0) { }
        i2c_send_controller_tx(data[i]);
    }

    i2c_trigger_transaction(length + 1, 0, 1, 1);
    
    while(i2c_is_busy()){ }

    return !i2c_had_error();

}

uint8_t i2c_read_buffer(uint8_t mem_addr, uint8_t *data, uint32_t length){

    i2c_set_direction(I2C_DIR_TRANSMIT);

    while(read_reg_field(&I2C->MASTER.MFIFOSR, I2C_CFIFOSR_TXFIFOCNT_OFS, I2C_CFIFOSR_TXFIFOCNT_WIDTH) == 0) { }
    i2c_send_controller_tx(mem_addr);

    i2c_trigger_transaction(1, 0, 1, 1);

    while(i2c_is_busy()) { }

    if(i2c_is_busy()) { }

    if(i2c_had_error()) {
        return 0;
    }


    i2c_set_direction(I2C_DIR_RECEIVE);
    i2c_trigger_transaction(length, 0, 1, 1);

    for(uint32_t i = 0; i < length; i++){
        while(read_reg_field(&I2C->MASTER.MFIFOSR, I2C_CFIFOSR_RXFIFOCNT_OFS, I2C_CFIFOSR_RXFIFOCNT_WIDTH) == 0) { }
        data[i] = i2c_read_data();
    }

    while(i2c_is_busy()){ }

    return !i2c_had_error();
}