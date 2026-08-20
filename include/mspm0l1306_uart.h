#ifndef MSPM0L1306_UART_H
#define MSPM0L1306_UART_H

#include "mspm0l1306_base.h"

// ============================================================================
// UART0 base 0x40108000U
// ============================================================================

typedef struct{
    __I  uint32_t IIDX;                     // (@ 0x00001080) Interrupt index
         uint32_t RESERVED0;
    __IO uint32_t IMASK;                    // (@ 0x00001088) Interrupt mask
         uint32_t RESERVED1;
    __I  uint32_t RIS;                      // (@ 0x00001090) Raw interrupt status
         uint32_t RESERVED2;
    __I  uint32_t MIS;                      // (@ 0x00001098) Masked interrupt status
         uint32_t RESERVED3;
    __O  uint32_t ISET;                     // (@ 0x000010A0) Interrupt set
         uint32_t RESERVED4;
    __O  uint32_t ICLR;                     // (@ 0x000010A8) Interrupt clear
} UART_DMA_TRIG_TX_Regs;

typedef struct{
    __I  uint32_t IIDX;                     // (@ 0x00001050) Interrupt index
         uint32_t RESERVED0;
    __IO uint32_t IMASK;                    // (@ 0x00001058) Interrupt mask
         uint32_t RESERVED1;
    __I  uint32_t RIS;                      // (@ 0x00001060) Raw interrupt status
         uint32_t RESERVED2;
    __I  uint32_t MIS;                      // (@ 0x00001068) Masked interrupt status
         uint32_t RESERVED3;
    __O  uint32_t ISET;                     // (@ 0x00001070) Interrupt set
         uint32_t RESERVED4;
    __O  uint32_t ICLR;                     // (@ 0x00001078) Interrupt clear
} UART_DMA_TRIG_RX_Regs;

typedef struct{
    __I  uint32_t IIDX;                     // (@ 0x00001020) Interrupt index
         uint32_t RESERVED0;
    __IO uint32_t IMASK;                    // (@ 0x00001028) Interrupt mask
         uint32_t RESERVED1;
    __I  uint32_t RIS;                      // (@ 0x00001030) Raw interrupt status
         uint32_t RESERVED2;
    __I  uint32_t MIS;                      // (@ 0x00001038) Masked interrupt status
         uint32_t RESERVED3;
    __O  uint32_t ISET;                     // (@ 0x00001040) Interrupt set
         uint32_t RESERVED4;
    __O  uint32_t ICLR;                     // (@ 0x00001048) Interrupt clear
} UART_CPU_INT_Regs;


typedef struct{
    __IO uint32_t PWREN;                    // (@ 0x00000800) Power enable
    __O  uint32_t RSTCTL;                   // (@ 0x00000804) Reset control
    __IO uint32_t CLKCFG;                   // (@ 0x00000808) Peripheral clock configuration register 
         uint32_t RESERVED0[2];
    __I  uint32_t STAT;                     // (@ 0x00000814) Status register
} UART_GPRCM_Regs;

typedef struct{
         uint32_t RESERVED0[512];
    UART_GPRCM_Regs GPRCM;                  // (@ 0x00000800)
         uint32_t RESERVED1[506];
    __IO uint32_t CLKDIV;                   // (@ 0x00001000) Clock divider
         uint32_t RESERVED2;
    __IO uint32_t CLKSEL;                   // (@ 0x00001008) Clock select for ultra low power peripherals
         uint32_t RESERVED3[3];
    __IO uint32_t PDBGCTL;                  // (@ 0x00001018) Peripheral debug control 
         uint32_t RESERVED4;
    UART_CPU_INT_Regs CPU_INT;              // (@ 0x00001020) CPU_INT
         uint32_t RESERVED5;
    UART_DMA_TRIG_RX_Regs DMA_TRIG_RX;      // (@ 0x00001050) DMA_TRIG_RX
         uint32_t RESERVED6;
    UART_DMA_TRIG_TX_Regs DMA_TRIG_TX;      // (@ 0x00001080) DMA_TRIG_TX
         uint32_t RESERVED7[13];
    __IO uint32_t EVT_MODE;                 // (@ 0x000010E0) Event mode
    __IO uint32_t INTCTL;                   // (@ 0x000010E4) Interrupt control register
         uint32_t RESERVED8[6];
    __IO uint32_t CTL0;                     // (@ 0x00001100) UART Control register 0
    __IO uint32_t LCRH;                     // (@ 0x00001104) UART Line control register
    __I  uint32_t STAT;                     // (@ 0x00001108) UART Status register
    __IO uint32_t IFLS;                     // (@ 0x0000110C) UART Interrupt FIFO level select register
    __IO uint32_t IBRD;                     // (@ 0x00001110) UART Integer baud-rate divisor register
    __IO uint32_t FBRD;                     // (@ 0x00001114) UART Fractional baud-rate divisor register
    __IO uint32_t GFCTL;                    // (@ 0x00001118) Glitch filter control
         uint32_t RESERVED9;
    __IO uint32_t TXDATA;                   // (@ 0x00001120) UART Transmit data register 
    __I  uint32_t RXDATA;                   // (@ 0x00001124) UART Receive data register
         uint32_t RESERVED10[2];
    __IO uint32_t LINCNT;                   // (@ 0x00001130) UART Lin mode counter register
    __IO uint32_t LINCTL;                   // (@ 0x00001134) UART Lin mode control register
    __IO uint32_t LINC0;                    // (@ 0x00001138) UART Lin mode capture 0 register
    __IO uint32_t LINC1;                    // (@ 0x0000113C) UART Lin mode capture 1 register
    __IO uint32_t IRCTL;                    // (@ 0x00001140) eUSCI_Ax IrDA Control word register
         uint32_t RESERVED11;
    __IO uint32_t AMASK;                    // (@ 0x00001148) Self address mask register
    __IO uint32_t ADDR;                     // (@ 0x0000114C) Self address register
         uint32_t RESERVED12[4];
    __IO uint32_t CLKDIV2;                  // (@ 0x00001160) Clock divider 
} UART_Regs;

#define UART ((UART_Regs *) UART0_BASE) 


// CLKDIV enum

typedef enum{
     UART_CLKDIV_NO_DIV =  0U,
     UART_CLKDIV_2_DIV  =  1U,
     UART_CLKDIV_3_DIV  =  2U,
     UART_CLKDIV_4_DIV  =  3U,
     UART_CLKDIV_5_DIV  =  4U,
     UART_CLKDIV_6_DIV  =  5U,
     UART_CLKDIV_7_DIV  =  6U,
     UART_CLKDIV_8_DIV  =  7U,    
} uart_clk_div_t;

// CLKSEL enum

typedef enum{
     UART_CLKSEL_LFCLK  = 1,
     UART_CLKSEL_MFCLK  = 2,
     UART_CLKSEL_BUSCLK = 3,
} uart_clock_t;

// CTL0 enum

typedef enum{
     UART_CTL0_HSE_16X  = 0U,
     UART_CTL0_HSE_8X   = 1U,
     UART_CTL0_HSE_3X   = 2U,
} uart_oversampling_t;

// LCRH enum

typedef enum{
     UART_PARITY_NONE = 0U,
     UART_PARITY_ODD  = 1U,
     UART_PARITY_EVEN = 2U,
} uart_parity_t;

typedef enum{
     UART_LCRH_STP2_1SB = 0U,          // 1 Stop bit
     UART_LCRH_STP2_2SB = 1U,          // 2 Stop bits
} uart_stop_bits_t;

typedef enum{
     UART_LCRH_WLEN_5B  = 0U,          // 5 data bits trasmitted or recieved in frame
     UART_LCRH_WLEN_6B  = 1U,          // 6 data bits trasmitted or recieved in frame
     UART_LCRH_WLEN_7B  = 2U,          // 7 data bits trasmitted or recieved in frame
     UART_LCRH_WLEN_8B  = 3U,          // 8 data bits trasmitted or recieved in frame
} uart_wlen_t;

// IIDX Macros for interrupts

#define UART_CPU_INT_IIDX_STAT_NO_INTR  (0x00000000U)       // No pending interrupt
#define UART_CPU_INT_IIDX_STAT_RTFG     (0x00000001U)       /* UART recieve time-out interrupt; Interrupt flag: RT;
                                                               Interrupt priority highest */
#define UART_CPU_INT_IIDX_STAT_FEFG     (0x00000002U)       /* UART framing error interrupt;
                                                               Interrupt flag: FE  */
#define UART_CPU_INT_IIDX_STAT_PEFG     (0x00000003U)       /* UART parity error interrupt;
                                                               Interrupt flag: PE  */
#define UART_CPU_INT_IIDX_STAT_BEFG     (0x00000004U)       /* UART break error interrupt;
                                                               Interrupt flag: BE  */
#define UART_CPU_INT_IIDX_STAT_OEFG     (0x00000005U)       /* UART recieve overrun error interrupt;
                                                               Interrupt flag: OE  */
#define UART_CPU_INT_IIDX_STAT_RXNE     (0x00000006U)       /* Negative edge on UARTxRXD
                                                               interrupt; Interrupt Flag: RXNE */
#define UART_CPU_INT_IIDX_STAT_RXPE     (0x00000007U)       /* Positive edge on UARTxRXD
                                                               interrupt; Interrupt Flag: RXPE */
#define UART_CPU_INT_IIDX_STAT_LINC0    (0x00000008U)       /* LIN capture 0 / match interrupt;
                                                               Interrupt Flag: LINC0 */
#define UART_CPU_INT_IIDX_STAT_LINC1    (0x00000009U)       /* LIN capture 1 interrupt; Interrupt
                                                               Flag: LINC1 */
#define UART_CPU_INT_IIDX_STAT_LINOVF   (0x0000000AU)       /* LIN hardware counter overflow
                                                               interrupt; Interrupt Flag: LINOVF */
#define UART_CPU_INT_IIDX_STAT_RXIFG    (0x0000000BU)       /* UART receive interrupt; Interrupt
                                                               Flag: RX */
#define UART_CPU_INT_IIDX_STAT_TXIFG    (0x0000000CU)       /* UART transmit interrupt; Interrupt
                                                               Flag: TX */
#define UART_CPU_INT_IIDX_STAT_EOT      (0x0000000DU)       /* UART end of transmission interrupt
                                                               (transmit serializer empty);
                                                               Interrupt Flag: EOT */
#define UART_CPU_INT_IIDX_STAT_MODE_9B  (0x0000000EU)       /* 9-bit mode address match interrupt;
                                                               Interrupt Flag: MODE_9B */
#define UART_CPU_INT_IIDX_STAT_CTS      (0x0000000FU)       /* UART Clear to Send Modem interrupt;
                                                               Interrupt Flag: CTS */
          
// IMASK Macros

#define UART_CPU_INT_IMASK_NERR_OFS           (17U)
#define UART_CPU_INT_IMASK_DMA_DONE_TX_OFS    (16U)
#define UART_CPU_INT_IMASK_DMA_DONE_RX_OFS    (15U)
#define UART_CPU_INT_IMASK_DMA_CTS_OFS        (14U)
#define UART_CPU_INT_IMASK_DMA_ADDR_MATCH_OFS (13U)
#define UART_CPU_INT_IMASK_DMA_EOT_OFS        (12U)
#define UART_CPU_INT_IMASK_DMA_TXINT_OFS      (11U)
#define UART_CPU_INT_IMASK_DMA_RXINT_OFS      (10U)
#define UART_CPU_INT_IMASK_LINOVF_OFS         (9U)
#define UART_CPU_INT_IMASK_LINC1_OFS          (8U)
#define UART_CPU_INT_IMASK_LINC0_OFS          (7U)
#define UART_CPU_INT_IMASK_RXPE_OFS           (6U)
#define UART_CPU_INT_IMASK_RXNE_OFS           (5U)
#define UART_CPU_INT_IMASK_OVRERR_OFS         (4U)
#define UART_CPU_INT_IMASK_BRKERR_OFS         (3U)
#define UART_CPU_INT_IMASK_PARERR_OFS         (2U)
#define UART_CPU_INT_IMASK_FRMERR_OFS         (1U)
#define UART_CPU_INT_IMASK_RTOUT_OFS          (0U)

// RSTCTL Macros

#define UART_RSTCTL_KEY_UNLOCK_W       (0xB1000000U)
#define UART_RSTCTL_RESETASSERT        (1U)

// CLKCFG Macros

#define UART_CLKCFG_KEY_UNLOCK_W       (0xA9000000U)

// CLKDIV Macros

#define UART_CLKDIV_RATIO_OFS          (0U)
#define UART_CLKDIV_RATIO_WIDTH        (3U)

// CLKSEL Macros

#define UART_CLKSEL_LFCLK_OFS          (1U)
#define UART_CLKSEL_MFCLK_OFS          (2U)
#define UART_CLKSEL_BUSCLK_OFS         (3U)

// CTL0 Macros
#define UART_CTL0_HSE_OFS              (15U)
#define UART_CTL0_HSE_WIDTH            (2U)
#define UART_CTL0_ENABLE_OFS           (0U)

// LCRH Macros
#define UART_LCRH_WLEN_OFS             (4U)
#define UART_LCRH_WLEN_WIDTH           (2U)
#define UART_LCRH_STP2_OFS             (3U)
#define UART_LCRH_EPS_OFS              (2U)
#define UART_LCRH_PEN_OFS              (1U)
#define UART_LCRH_BRK_OFS              (0U)

// IBRD Macros
#define UART_IBRD_DIVINT_OFS           (0U)
#define UART_IBRD_DIVINT_WIDTH         (16U)

// FBRD Macros
#define UART_FBRD_DIVFRAC_OFS          (0U)
#define UART_FBRD_DIVFRAC_WIDTH        (6U)

// TXDATA Macros
#define UART_TXDATA_DATA_OFS           (0U)
#define UART_TXDATA_DATA_WIDTH         (8U)

// RXDATA Macros
#define UART_RXDATA_DATA_OFS           (0U)
#define UART_RXDATA_DATA_WIDTH         (8U)

// STAT Macros
#define UART_STAT_TXFE_OFS             (6U)
#define UART_STAT_RXFE_OFS             (2U)
#define UART_STAT_BUSY_OFS             (0U)


// ========================================= CONFIGURATION FUNCTIONS  ======================================================
void uart_reset                    (void);
void uart_enable_power             (void);
void uart_disable_power            (void);
void uart_set_clock_config         (uart_clock_t clock, uart_clk_div_t divider);
void uart_set_baudrate             (uint32_t clock_freq, uint32_t baudrate);
void uart_set_baudrate_divisor     (uint32_t integer_div, uint32_t fractional_div);
void uart_set_oversampling         (uart_oversampling_t oversampling);
void uart_set_data_bits            (uart_wlen_t data);
void uart_set_parity               (uart_parity_t parity);
void uart_set_stop_bits            (uart_stop_bits_t stop);
void uart_enable                   (void);
void uart_disable                  (void);

// ========================================= WRITE/READ UART FUNCTIONS ===================================================
void     uart_write_byte       (uint8_t data);
uint8_t  uart_read_byte        (void);
uint32_t uart_is_tx_empty      (void);
uint32_t uart_is_rx_empty      (void);
uint32_t uart_is_busy          (void);               // TODO Not sure if i even use this tbh could just remove it ltr on
void     uart_send_blocking    (uint32_t data);
uint8_t  uart_receive_blocking (void);

void     uart_write_string     (const char *str);
void     uart_read_string      (char *buffer, uint32_t size);

// Novo ig

void uart_enable_rx_interrupt(void);
void uart_disable_rx_interrupt(void);

uint32_t uart_read(uint8_t *data);

void uart_rx_interrupt_handler(void);
void uart_tx_interrupt_handler(void);

void uart_enable_tx_interrupt(void);

void uart_write_byte_interrupt(uint8_t data);
void uart_write_string_interrupt(const char *str);
#endif // MSPM0L1306_UART_H