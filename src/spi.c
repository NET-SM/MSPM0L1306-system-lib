#include "mspm0l1306_spi.h"
#include "mspm0_reg_utils.h"
#include "mspm0l1306_gpio.h"

void spi_reset(void){

    SPI->GPRCM.RSTCTL = (SPI_RSTCTL_KEY_UNLOCK_W | SPI_RSTCTL_RESETASSERT);
}

void spi_enable_power (void){

    SPI->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | ENABLE);    
}

void spi_disable_power (void){

    SPI->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | DISABLE);
}

void spi_enable(void){
    
    write_reg_bit(&SPI->CTL1, SPI_CTL1_ENABLE_OFS, ENABLE);
}

void spi_disable(void){

    write_reg_bit(&SPI->CTL1, SPI_CTL1_ENABLE_OFS, DISABLE);
}

void spi_set_clock_configuration (spi_clock_t clock, spi_clock_div_t divider){

    // Disable previous clock configs if there are any
    write_reg_bit(&SPI->CLKSEL, SPI_CLKSEL_LFCLK_OFS, DISABLE);
    write_reg_bit(&SPI->CLKSEL, SPI_CLKSEL_MFCLK_OFS, DISABLE);
    write_reg_bit(&SPI->CLKSEL, SPI_CLKSEL_SYSCLK_OFS, DISABLE);

    switch(clock){
        case SPI_CLKSEL_SYSCLK:
            write_reg_bit(&SPI->CLKSEL, SPI_CLKSEL_SYSCLK_OFS, ENABLE);
        break;

        case SPI_CLKSEL_MFCLK:
            write_reg_bit(&SPI->CLKSEL, SPI_CLKSEL_MFCLK_OFS, ENABLE);
        break;

        case SPI_CLKSEL_LFCLK:
        default:
            write_reg_bit(&SPI->CLKSEL, SPI_CLKSEL_LFCLK_OFS, ENABLE);
        break;
    }

    write_reg_field(&SPI->CLKDIV, SPI_CLKDIV_RATIO_OFS, SPI_CLKDIV_RATIO_WIDTH, divider);
}

void spi_set_clock_prescaler(uint32_t scr){

    if(scr > 0x3FF){
        scr = 0x3FF;
    }

    write_reg_field(&SPI->CLKCTL, SPI_CLKCTL_SCR_OFS, SPI_CLKCTL_SCR_WIDTH, scr);

}


void spi_set_mode (spi_mode_t mode){

    if(mode == SPI_CONTROLLER_MODE){
        write_reg_bit(&SPI->CTL1, SPI_CTL1_CP_OFS, ENABLE);
    }
    if(mode == SPI_PERIPHERAL_MODE){
        write_reg_bit(&SPI->CTL1, SPI_CTL1_CP_OFS, DISABLE); 
    }

}

void spi_set_transfer_mode(spi_transfer_mode_t transfer_mode){

    uint32_t current_frf = read_reg_field(&SPI->CTL0, SPI_CTL0_FRF_OFS, SPI_CTL0_FRF_WIDTH);

    // SPO and SPH cant be configured outside of Motorola FRF
    if(current_frf != SPI_FRF_MOTOROLA_3WIRE && 
        current_frf != SPI_FRF_MOTOROLA_4WIRE){
            return; 
        }

    uint32_t spo = (transfer_mode >> 1) & 0x1;
    uint32_t sph = transfer_mode & 0x1; 
    
    write_reg_bit(&SPI->CTL0, SPI_CTL0_SPO_OFS, spo);
    write_reg_bit(&SPI->CTL0, SPI_CTL0_SPH_OFS, sph);
}

void spi_set_frame_format(spi_frame_format_t frame_format){
    write_reg_field(&SPI->CTL0, SPI_CTL0_FRF_OFS, SPI_CTL0_FRF_WIDTH, frame_format);
}


void spi_set_data_size(spi_data_size_t size){
    write_reg_field(&SPI->CTL0, SPI_CTL0_DSS_OFS, SPI_CTL0_DSS_WIDTH, size);
}

void spi_set_bit_order(spi_bit_order_t order){
    write_reg_bit(&SPI->CTL1, SPI_CTL1_MSB_OFS, order);
}

void spi_set_cs_line(spi_cs_line_t line){
    write_reg_field(&SPI->CTL0,  SPI_CTL0_CSSEL_OFS, SPI_CTL0_CSSEL_WIDTH, line);
}

void spi_cs_enable(uint32_t pin){
    gpio_write(pin, 0);
}

void spi_cs_disable(uint32_t pin){
    gpio_write(pin, 1);
}


uint8_t spi_transfer_byte(uint8_t data){

    // 1. Wait until TX FIFO isnt full
    while(read_reg_bit(&SPI->STAT, SPI_STAT_TNF_OFS)== 0) { }

    write_reg_field(&SPI->TXDATA, 0, 8, data);

    // 2. Wait until RX FIFO empties out
    while(read_reg_bit(&SPI->STAT, SPI_STAT_RFE_OFS)== 1) { }

    uint8_t received = (uint8_t) read_reg_field(&SPI->RXDATA, 0, 8);

    return received;
}

void spi_write_buffer(uint32_t address, const uint8_t *data, uint32_t length, uint8_t WRITE_CMD){
    
    spi_transfer_byte(WRITE_CMD);
    spi_transfer_byte((address >> 16) & 0xFF);
    spi_transfer_byte((address >> 8)  & 0xFF);
    spi_transfer_byte(address & 0xFF);

    for(uint32_t i = 0; i < length; i++){
        spi_transfer_byte(data[i]);
    }

}
void spi_read_buffer(uint32_t address, uint8_t *data, uint32_t length, uint8_t READ_CMD){

    spi_transfer_byte(READ_CMD);
    spi_transfer_byte((address >> 16) & 0xFF);
    spi_transfer_byte((address >> 8)  & 0xFF);
    spi_transfer_byte(address & 0xFF);

    for(uint32_t i = 0; i < length; i++){
        data[i] = spi_transfer_byte(0xFF);
    }

}