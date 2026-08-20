#include "mspm0l1306_uart.h"
#include "mspm0_reg_utils.h"

#define UART_RX_BUFFER_SIZE 128
#define UART_TX_BUFFER_SIZE 128


// For UART interrupt ringbuffers
static volatile uint8_t rx_buffer[UART_RX_BUFFER_SIZE];
static volatile uint8_t tx_buffer[UART_TX_BUFFER_SIZE];

static volatile uint32_t rx_read_index  = 0;
static volatile uint32_t rx_write_index = 0;

static volatile uint32_t tx_read_index  = 0;
static volatile uint32_t tx_write_index = 0;

void uart_reset(void){

    UART->GPRCM.RSTCTL = (UART_RSTCTL_KEY_UNLOCK_W | UART_RSTCTL_RESETASSERT);
}

void uart_enable_power(void){

    UART->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | ENABLE );

};

void uart_disable_power(void){

    UART->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | DISABLE );

};

void uart_init(){

    // TODO wrapper fun

}

void uart_set_parity(uart_parity_t parity){
    
    if (parity == UART_PARITY_NONE){
        write_reg_bit(&UART->LCRH, UART_LCRH_PEN_OFS, DISABLE);
        return;
    }

    write_reg_bit(&UART->LCRH, UART_LCRH_PEN_OFS, ENABLE);
    write_reg_bit(&UART->LCRH, UART_LCRH_EPS_OFS, 
                  (parity == UART_PARITY_EVEN) ? ENABLE: DISABLE);
}

void uart_set_data_bits(uart_wlen_t data){
    
    write_reg_field(&UART->LCRH, UART_LCRH_WLEN_OFS, UART_LCRH_WLEN_WIDTH, data);

}

void uart_set_stop_bits(uart_stop_bits_t stop){
    
    write_reg_bit(&UART->LCRH, UART_LCRH_STP2_OFS, stop);

}

void uart_enable(void){

    write_reg_bit(&UART->CTL0, UART_CTL0_ENABLE_OFS, ENABLE);

}

void uart_disable(void){

    write_reg_bit(&UART->CTL0, UART_CTL0_ENABLE_OFS, DISABLE);

}


void uart_write_byte(uint8_t data){

    write_reg_field(&UART->TXDATA,
                     UART_TXDATA_DATA_OFS,
                     UART_TXDATA_DATA_WIDTH,
                     data);

}

uint8_t uart_read_byte(void){

    return read_reg_field(&UART->RXDATA, 
                           UART_RXDATA_DATA_OFS, 
                           UART_RXDATA_DATA_WIDTH);

}

uint32_t uart_is_busy(void){

    return read_reg_bit(&UART->STAT, UART_STAT_BUSY_OFS);
}

uint32_t uart_is_tx_empty(void){
    
    return read_reg_bit(&UART->STAT, UART_STAT_TXFE_OFS);
}

uint32_t uart_is_rx_empty(void){

    return read_reg_bit(&UART->STAT, UART_STAT_RXFE_OFS);
}


void uart_set_clock_config(uart_clock_t clock, uart_clk_div_t divider){

    // Clear previous clock configs if there are any
    write_reg_bit(&UART->CLKSEL, UART_CLKSEL_LFCLK_OFS, DISABLE);
    write_reg_bit(&UART->CLKSEL, UART_CLKSEL_MFCLK_OFS, DISABLE);
    write_reg_bit(&UART->CLKSEL, UART_CLKSEL_BUSCLK_OFS, DISABLE);

    switch (clock){
        case UART_CLKSEL_BUSCLK:
            write_reg_bit(&UART->CLKSEL, UART_CLKSEL_BUSCLK_OFS, ENABLE);
        break;

        case UART_CLKSEL_MFCLK:
            write_reg_bit(&UART->CLKSEL, UART_CLKSEL_MFCLK_OFS, ENABLE);
        break;
        
        case UART_CLKSEL_LFCLK:
        default:    
            write_reg_bit(&UART->CLKSEL, UART_CLKSEL_LFCLK_OFS, ENABLE);
        break;
    }

    write_reg_field(&UART->CLKDIV, UART_CLKDIV_RATIO_OFS, UART_CLKDIV_RATIO_WIDTH, divider);

}

void uart_set_baudrate_divisor(uint32_t integer_div, uint32_t fractional_div){

    write_reg_field(&UART->IBRD, UART_IBRD_DIVINT_OFS, UART_IBRD_DIVINT_WIDTH, integer_div);
    write_reg_field(&UART->FBRD, UART_FBRD_DIVFRAC_OFS, UART_FBRD_DIVFRAC_WIDTH, fractional_div);

    // When updating baud-rate divisor, LCRH register must also be written to
    // (any bit in LCRH can be written to for updating baud-rate divisor)

    uint32_t lchr_current_brk = read_reg_bit(&UART->LCRH, UART_LCRH_BRK_OFS);
    write_reg_bit(&UART->LCRH, UART_LCRH_BRK_OFS, lchr_current_brk);

}

void uart_set_oversampling(uart_oversampling_t oversampling){

    write_reg_field(&UART->CTL0, UART_CTL0_HSE_OFS, UART_CTL0_HSE_WIDTH, oversampling);

}

void uart_set_baudrate(uint32_t clock_freq, uint32_t baudrate){

    uint32_t divisor;

    /*
        The baud rate divisor, brd, is calculated with the following formula:
        brd = ibrd.fbrd = clockOutput / (OVS* baudRate)
        ibrd - integer brd, fbrd - fractional brd
        Since fbrd is 6 bits, multiply brd by 64:
            64 * brd = (clockOutput * 64) / (16 * baudRate)
                     = (clockOutput * 4) / baudRate
        add 1/2 to round the LSB of fbrd:
            64 * brd + 1/2 = (clockOutput * 8) / (2* baudRate) + 1/2
            divisor = 64*brd+1/2 = [(clockOutput * 8) / baudRate + 1] / 2

        The lower 6 bits is fbrd, upper part is ibrd
        Note: If ibrd is 0, FBRD will be ignored and no data will
        be transferred
    */

    if((baudrate * (uint32_t) 8) > clock_freq){

        uart_set_oversampling(UART_CTL0_HSE_3X);

        divisor = ((clock_freq * (uint32_t) 64) / (baudrate * (uint32_t) 3)) +
                  ((uint32_t) 1 / (uint32_t) 2);
    
    } else if ((baudrate * (uint32_t) 16) > clock_freq){

        uart_set_oversampling(UART_CTL0_HSE_8X);
        baudrate = baudrate / (uint32_t) 2;
        
        divisor = (((clock_freq * (uint32_t) 8) / baudrate) + (uint32_t) 1 ) /
                  (uint32_t) 2;
    
    } else {

        uart_set_oversampling(UART_CTL0_HSE_16X);

        divisor = (((clock_freq * (uint32_t) 8) / baudrate) + (uint32_t) 1 ) /
                  (uint32_t) 2;

    }

    uart_set_baudrate_divisor(divisor >> (uint32_t) 6, divisor & (uint32_t) 0x3F);

}

void uart_send_blocking(uint32_t data){
    while(!uart_is_tx_empty()) { }
    uart_write_byte(data);
}

uint8_t uart_receive_blocking(void){
    while(uart_is_rx_empty()) { }
    return uart_read_byte();
}

void uart_write_string(const char *str){
    
    while(*str != '\0'){
        uart_send_blocking(*str);
        str++;
    }

}

void uart_read_string(char *buffer, uint32_t size){

    uint32_t i = 0;

    while (i < size - 1){
        char c = uart_receive_blocking();

        if(c == '\r' || c== '\n'){
            break;
        }

        buffer[i++] = c;

    }

    buffer[i] = '\0';

}

// ===================================================== UART INTERRUPT FUNCTIONS =====================================

void uart_enable_tx_interrupt(){

    UART->CPU_INT.IMASK = reg_write_bit(UART->CPU_INT.IMASK, UART_CPU_INT_IMASK_DMA_TXINT_OFS, ENABLE);

}

void uart_rx_interrupt_handler(void){

    uint8_t data = uart_read_byte();

    rx_buffer[rx_write_index] = data;
    
    rx_write_index++;

    if(rx_write_index >= UART_RX_BUFFER_SIZE){
        rx_write_index = 0;
    }

}

void uart_tx_interrupt_handler(void){

    if( tx_read_index == tx_write_index){
        // No more data to be sent
        // Turn off TX interrupt
        return;
    }
    
    uart_write_byte(tx_buffer[tx_read_index]);

    tx_read_index++;

    if(tx_read_index >= UART_TX_BUFFER_SIZE){
        tx_read_index = 0;
    }

}

uint8_t uart_write_byte_interrupt(uint8_t data){

    uint32_t next_index = tx_write_index + 1;

    if (next_index >= UART_TX_BUFFER_SIZE) {
        next_index = 0;
    }

    // Buffer is full
    if (next_index == tx_read_index){
        return 0;
    }

    tx_buffer[tx_write_index] = data;
    tx_write_index = next_index;

    uart_enable_tx_interrupt();



}

void uart_write_string_interrupt(const char *str);