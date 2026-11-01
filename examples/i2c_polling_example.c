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

    uint8_t word_addr = 0x10;
    uint8_t write_val = 0x77;

    uint8_t data[4] = {0x11, 0x22, 0x33, 0x44};
    uint8_t got_data[4];

    i2c_set_target(EEPROM_ADDR);
    
    i2c_write_buffer(word_addr, data, 4);
    delay_ms(10);
    i2c_read_buffer(word_addr, got_data, 4);
      
    while (1) {
        
    }
}


