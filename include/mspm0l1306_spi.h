#ifndef MSPM0L1306_SPI_H
#define MSPM0L1306_SPI_H

#include "mspm0l1306_base.h"

// ============================================================================
// SPI0 base 0x40468000U
// ============================================================================

typedef struct {
    __I  uint32_t IIDX;                     // (@ 0x00001080) Interrupt index register
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
} SPI_DMA_TRIG_TX_Regs;

typedef struct {
    __I  uint32_t IIDX;                     // (@ 0x00001050) Interrupt index register
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
} SPI_DMA_TRIG_RX_Regs;

typedef struct{
    __I  uint32_t IIDX;                     // (@ 0x00001020) Interrupt index register
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
} SPI_CPU_INT_Regs;

typedef struct{
    __IO uint32_t PWREN;                    // (@ 0x00000800) Power enable
    __O  uint32_t RSTCTL;                   // (@ 0x00000804) Reset control
    __IO uint32_t CLKCFG;                   // (@ 0x00000808) Peripheral clock configuration register
         uint32_t RESERVED0[2];
    __I  uint32_t STAT;                     // (@ 0x00000814) Status register
} SPI_GPRCM_Regs;

typedef struct{
         uint32_t RESERVED0[512];
    SPI_GPRCM_Regs GPRCM;                   // (@ 0x00000800) 
         uint32_t RESERVED1[506];
    __IO uint32_t CLKDIV;                   // (@ 0x00001000) Clock Divider
    __IO uint32_t CLKSEL;                   // (@ 0x00001004) Clock Select for Ultra Low Power Peripherals
         uint32_t RESERVED2[4];
    __IO uint32_t PDBGCTL;                  // (@ 0x00001018) Peripheral Debug Control
         uint32_t RESERVED3;
    SPI_CPU_INT_Regs CPU_INT;               // (@ 0x00001020)
         uint32_t RESERVED4;
    SPI_DMA_TRIG_RX_Regs DMA_TRIG_RX;       // (@ 0x00001050)
         uint32_t RESERVED5;
    SPI_DMA_TRIG_TX_Regs DMA_TRIG_TX;       // (@ 0x00001080)
         uint32_t RESERVED6[13];
    __IO uint32_t EVT_MODE;                 // (@ 0x000010E0) Event mode
    __IO uint32_t INTCTL;                   // (@ 0x000010E4) Interrupt Control register
         uint32_t RESERVED7[6];
    __IO uint32_t CTL0;                     // (@ 0x00001100) SPI Control register 0
    __IO uint32_t CTL1;                     // (@ 0x00001104) SPI Control register 1
    __IO uint32_t CLKCTL;                   // (@ 0x00001108) Clock prescaler and divider register
    __IO uint32_t IFLS;                     // (@ 0x0000110C) Interrupt FIFO Level Select Register
    __I  uint32_t STAT;                     // (@ 0x00001110) Status register
         uint32_t RESERVED8[7];
    __I  uint32_t RXDATA;                   // (@ 0x00001130) RXDATA Register
         uint32_t RESERVED9[3];
    __IO uint32_t TXDATA;                   // (@ 0x00001140) TXDATA Register
} SPI_Regs;

#define SPI ((SPI_Regs *) SPI0_BASE) 

#endif // MSPM0L1306_SPI_H