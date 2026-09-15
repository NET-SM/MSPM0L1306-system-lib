#include "mspm0l1306_uart.h"
#include "mspm0_reg_utils.h"

#define UART_RX_BUFFER_SIZE 6
#define UART_TX_BUFFER_SIZE 6


// For UART interrupt ringbuffers
static volatile uint8_t rx_buffer[UART_RX_BUFFER_SIZE];
static volatile uint8_t tx_buffer[UART_TX_BUFFER_SIZE];

static volatile uint32_t rx_read_index  = 0;
static volatile uint32_t rx_write_index = 0;
static volatile uint8_t  rx_overflow    = 0;

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

void uart_enable_rx_interrupt(void){

    write_reg_bit(&UART->CPU_INT.IMASK, UART_CPU_INT_IMASK_RXINT_OFS, ENABLE);
}

void uart_enable_tx_interrupt(void){

    write_reg_bit(&UART->CPU_INT.IMASK, UART_CPU_INT_IMASK_TXINT_OFS, ENABLE);
}

void uart_disable_tx_interrupt(void){

    write_reg_bit(&UART->CPU_INT.IMASK, UART_CPU_INT_IMASK_TXINT_OFS, DISABLE);
}

void uart_disable_rx_interrupt(void){

    write_reg_bit(&UART->CPU_INT.IMASK, UART_CPU_INT_IMASK_RXINT_OFS, DISABLE);
}


void uart_rx_interrupt_handler(void){

    uint8_t data = uart_read_byte();

    uint32_t next = rx_write_index + 1;
    if(next >= UART_RX_BUFFER_SIZE){
        next = 0;
    }

    // Overflow occured
    if(next = rx_read_index){
        rx_overflow = 1;
        return;
    }

    rx_buffer[rx_write_index] = data;
    rx_write_index = next;
}

// Reads a byte from RX Ring buffer
uint8_t uart_read_byte_interrupt(uint8_t *out){

    if(rx_read_index == rx_write_index) return 0; // Extra safety

    *out =  rx_buffer[rx_read_index];
    rx_read_index++;
    if (rx_read_index >= UART_RX_BUFFER_SIZE){
        rx_read_index = 0;
    }
    return 1;
}

uint8_t uart_rx_overflow_occured(void){
    return rx_overflow;
}

void uart_rx_clear_overflow(void){
    rx_overflow = 0;
}

uint8_t uart_rx_available(void){
    if(rx_read_index == rx_write_index) return 0;    // No new data
    else return 1;                                   // New data
}


// Calculates how many open slots are left in the RX buffer
// Greska ovde potencijalno, -1 je okej ali se koristi kada zelimo da postoji jedan open slot u bufferu za
// signaliziranje kraja
uint32_t uart_rx_free_space(void){

    uint32_t free_space = (rx_read_index - rx_write_index - 1 + UART_RX_BUFFER_SIZE) % UART_RX_BUFFER_SIZE;
    return free_space;

}

uint32_t uart_rx_unused_data(void){

    uint32_t free_space = uart_rx_free_space();
    uint32_t unread_data = (UART_RX_BUFFER_SIZE - 1) - free_space;
    return unread_data;
}



uint32_t uart_read_rx_buffer(char *buffer, uint32_t length){

    if( length == 0 || length > UART_RX_BUFFER_SIZE) return 0;

    uint32_t available = uart_rx_unused_data();
    uint32_t to_copy   = length - 1;

    if(to_copy > available){
        to_copy = available;
    }

    for(uint32_t i = 0; i < to_copy; i++){
       
        buffer[i] = rx_buffer[rx_read_index];

        rx_read_index++;

        if(rx_read_index >= UART_RX_BUFFER_SIZE) rx_read_index = 0;
    }

    buffer[to_copy] = '\0';
    
    return to_copy;
}

// TO DELETE
void uart_test_inject_rx(const uint8_t *data, uint32_t len){

    for(uint32_t i = 0; i < len; i++){

        uint32_t next = rx_write_index + 1;
        if(next >= UART_RX_BUFFER_SIZE){
            next = 0;
        }

        if(next == rx_read_index){
            rx_overflow = 1;
            return;                 // Stop, refuse the rest
        }

        rx_buffer[rx_write_index] = data[i];
        rx_write_index = next;
    }
}

// TX INTERRUPT FUN

uint8_t uart_is_tx_buffer_empty(void){

    return tx_read_index == tx_write_index;
}

uint8_t uart_tx_buffer_put_byte(uint8_t byte){

    uint32_t next = tx_write_index + 1;
    if(next >= UART_TX_BUFFER_SIZE){
        next = 0;
    }

    if( next == tx_read_index){           // Buffer je pun
        return 0;
    }

    tx_buffer[tx_write_index] = byte;
    tx_write_index = next;

    uart_enable_tx_interrupt();

    return 1;
}

void uart_tx_interrupt_handler(void){

    if(tx_read_index == tx_write_index){
        uart_disable_tx_interrupt();
        return;
    }

    uart_write_byte(tx_buffer[tx_read_index]);
    
    tx_read_index++;
    if(tx_read_index >= UART_TX_BUFFER_SIZE){
        tx_read_index = 0;
    }

}