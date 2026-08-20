#include "system.h"

#define UART_CTL0_LBE_OFS  (2U)
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


    char buffer[36];
    uart_read_string(buffer, sizeof(buffer));

    while (1)
    {
        uart_write_string("Buffer je sada pun\n");
        delay_ms(1000);
        uart_write_string("Buffer ce sada biti procitan:\n");
        delay_ms(1000);
        for(int i = 0; i < sizeof(buffer); i++){
            uart_send_blocking(buffer[i]);
        }
        uart_send_blocking('\n');
        uart_write_string("Kraj loopa");
        delay_ms(10000);
    }
    




}