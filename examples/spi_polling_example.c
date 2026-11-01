#include "system.h"

int main(void) {

    // Configure IOMUX 
    iomux_configure_pin(IOMUX_PINCM24, IOMUX_PINCM24_PF_GPIOA_DIO23, ENABLE, IOMUX_PULL_NONE);
    iomux_configure_pin(IOMUX_PINCM7, IOMUX_PINCM7_PF_SPI0_SCLK, ENABLE, IOMUX_PULL_NONE);
    iomux_configure_pin(IOMUX_PINCM5, IOMUX_PINCM5_PF_SPI0_POCI, ENABLE, IOMUX_PULL_NONE);
    iomux_configure_pin(IOMUX_PINCM6, IOMUX_PINCM6_PF_SPI0_PICO, ENABLE, IOMUX_PULL_NONE);
    
    // GPIO needs to be powered for software controlled CS
    gpio_enable_power();
    gpio_enable_output(PA23);
    gpio_write(PA23, 1);

    // spi_reset also clears PWRCM
    spi_reset();
    spi_enable_power();
    
    // Clock configuration
    spi_set_clock_configuration(SPI_CLKSEL_SYSCLK, SPI_CLKDIV_NO_DIV);
    spi_set_clock_prescaler(0);

    // Select mode
    spi_set_mode(SPI_CONTROLLER_MODE);
    
    // Select Frame Format
    spi_set_frame_format(SPI_FRF_MOTOROLA_4WIRE);
    
    // Select SPI Mode
    spi_set_transfer_mode(SPI_MODE_0);
    
    // Data size & order
    spi_set_data_size(SPI_DSS_8B);
    spi_set_bit_order(SPI_BIT_ORDER_MSB_FIRST);

    spi_enable();

    uint8_t SRAM_CLICK_WRITE_CMD = 0x02;
    uint8_t SRAM_CLICK_READ_CMD  = 0x03;

    uint8_t write_data[4] = {0x11, 0x22, 0x33, 0x44};  // {'T', 'e', 's', 't'}
    spi_cs_enable(PA23);
    spi_write_buffer(0x000000, write_data, 4, SRAM_CLICK_WRITE_CMD);
    spi_cs_disable(PA23);

    uint8_t read_data[4];
    spi_cs_enable(PA23);
    spi_read_buffer(0x000000, read_data, 4, SRAM_CLICK_READ_CMD);
    spi_cs_disable(PA23);
    
    spi_disable();
    
    while (1) {

    }
}


