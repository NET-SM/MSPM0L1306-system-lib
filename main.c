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

    uart_enable_rx_interrupt();
    nvic_enable_irq(UART0_INT_IRQn);
    
    
    //uint8_t r1 = uart_tx_buffer_put_str("ovo je moj prvi put da pisem sto ovako ali nikada ranije nisam verovao da cu da pisem nesto ovako veliko i duboko :D sta zn\r\n");
    uint8_t r1 = uart_tx_buffer_put_str("String");
    uint8_t r2 = uart_tx_buffer_put_str("Drugi");

    while(1){
        
        //if(uart_rx_available()){    // RX bufer ima upisane podatke koji nisu procitani
            
            //uart_from_rx_to_tx_copy();

            //length = uart_rx_unused_data();            // Racuna koliko ima novih podataka
            //uart_read_rx_buffer(temp_buffer, length);  // Upisuje podatke iz rx_buf u temp_buf
            //
            //uart_tx_buffer_put_data(temp_buffer, length);           // Upis u tx_buf i sendback
        //}



    }   
}


