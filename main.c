#include "system.h"


int main(){

    // Confgigure RX and TX pin using iomux registers:
    iomux_configure_pin(IOMUX_PINCM9, IOMUX_PINCM9_PF_UART0_TX, DISABLE, IOMUX_PULL_NONE);
    iomux_configure_pin(IOMUX_PINCM10, IOMUX_PINCM10_PF_UART0_RX, ENABLE, IOMUX_PULL_NONE);

    // Reset the peripheral using UARTx.RSTCTL register
    uart_reset();

    // Enable the power to UART peripheral using the UARTx.PWREN register
    uart_enable_power();
    //write_reg_bit(&UART->CTL0, UART_CTL0_LBE_OFS, ENABLE);
    

    // Select the UART function clock source and divide options using UART.CLKSEL and UART.CLKDIV
    // registers.
    uart_set_clock_config(UART_CLKSEL_BUSCLK, UART_CLKDIV_NO_DIV);

    // Disable the UART by clearing the UART.CTL0.ENABLE bit.
    uart_disable();

    // Use the baud-rate equation in Section 21.2.3.4 to calculate the UARTx.IBRD and UARTx.FBRD registers
    uart_set_baudrate(SystemCoreClock, 115200);

    // Write the desired serial parameters to the UART.LCRH register

    uart_set_data_bits(UART_LCRH_WLEN_8B);
    uart_set_parity(UART_PARITY_NONE);
    uart_set_stop_bits(UART_LCRH_STP2_1SB);

    // Enable the UART by setting the UART.CTL0.ENABLE bit
    uart_enable();

    // Enables RX Interrupt 
    uart_enable_rx_interrupt();
    nvic_enable_irq(UART0_INT_IRQn);
    
    
    char test_data[] = "1234567890";
    uart_test_inject_rx((uint8_t*)test_data, sizeof(test_data) - 1);
    uart_write_string("Overflow: ");
    uart_write_string(uart_rx_overflow_occured() ? "DA\r\n" : "NE\r\n");
    
    char buf[10];
    uint32_t got = uart_read_rx_buffer(buf, sizeof(buf));

    uart_write_string("Read #1 (predugacak length) got=");
    uart_send_blocking((uint8_t)('0' + got));
    uart_write_string("\r\n");

    char buf2[4];
    uint32_t got1 = uart_read_rx_buffer(buf2, sizeof(buf2));   // traži 4, ima manje (5 kapacitet, deo možda overflow-ovan)
    uart_write_string("Read #2 got=");
    uart_send_blocking((uint8_t)('0' + got1));
    uart_write_string(" sadrzaj=");
    uart_write_string(buf2);
    uart_write_string("\r\n");


    while(1){
        
    }   
}


