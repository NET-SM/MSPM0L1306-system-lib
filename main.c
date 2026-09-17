#include "system.h"

#define EEPROM_ADDR 0x50


int main(void) {

    // I2C IOMUX Config
    iomux_configure_pin(IOMUX_PINCM1, IOMUX_PINCM1_PF_I2C0_SDA, ENABLE, IOMUX_PULL_UP);
    iomux_configure_pin(IOMUX_PINCM2, IOMUX_PINCM2_PF_I2C0_SCL, ENABLE, IOMUX_PULL_UP); 
    iomux_configure_pin(IOMUX_PINCM25, IOMUX_PINCM25_PF_GPIOA_DIO24, ENABLE, IOMUX_PULL_NONE);

    // Setting up GPIO for WP
    gpio_enable_power();
    gpio_enable_output(PA24);
    gpio_write(PA24, 0); // Set to low

    i2c_reset();
    i2c_power_enable();

    i2c_set_clock_configuration(I2C_CLKSEL_BUSCLK, I2C_CLKDIV_NO_DIV);
    i2c_set_baudrate(32000000, 100000); // 32MHz; 100kbps
    
    i2c_set_addressing_mode(I2C_ADDR_MODE_7BIT);

    i2c_enable();

    
    
    //uint8_t lb_write = i2c_write_byte(0x50, 0xAB, 1, 1);
    //uint8_t lb_err1  = i2c_had_error();
    //uint8_t lb_adack1= i2c_address_acked();
    //uint8_t lb_read  = i2c_read_byte(0x50, 0, 1, 1);
    //uint8_t lb_err2  = i2c_had_error();
    //uint8_t lb_adack2= i2c_address_acked();


    uint8_t word_addr = 0x10;
    uint8_t write_val = 0x77;

    
    i2c_set_target(EEPROM_ADDR);
    
    i2c_send_byte(word_addr, write_val, 1, 1);
    delay_ms(6);
    uint8_t result;
    temp_func(word_addr, ENABLE, ENABLE);
    i2c_receive_byte(0, ENABLE, ENABLE, &result);
    

    //i2c_set_target(EEPROM_ADDR, I2C_DIR_TRANSMIT);
    //i2c_send_byte(word_addr, 1, 0);
    //i2c_set_target(EEPROM_ADDR, I2C_DIR_RECEIVE);
    //uint8_t result;
    //i2c_receive_byte(0, ENABLE, ENABLE, &result);

    while (1) {
        
    }
}

