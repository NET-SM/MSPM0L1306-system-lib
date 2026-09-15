#ifndef MSPM0L1306_I2C_H
#define MSPM0L1306_I2C_H

#include "mspm0l1306_base.h"

// ============================================================================
// I2C0 base 0x400F0000U
// ============================================================================

typedef struct{
    __IO uint32_t SOAR;                             // (@ 0x00001250) I2C Target Own Address
    __IO uint32_t SOAR2;                            // (@ 0x00001254) I2C Target Own Address 2
    __IO uint32_t SCTR;                             // (@ 0x00001258) I2C Target Control Register
    __I  uint32_t SSR;                              // (@ 0x0000125C) I2C Target Status Register
    __I  uint32_t SRXDATA;                          // (@ 0x00001260) I2C Target RXData
    __IO uint32_t STXDATA;                          // (@ 0x00001264) I2C Target TXData
    __IO uint32_t SACKCTL;                          // (@ 0x00001268) I2C Target ACK Control
    __IO uint32_t SFIFOCTL;                         // (@ 0x0000126C) I2C Target FIFO Control
    __I  uint32_t SFIFOSR;                          // (@ 0x00001270) I2C Target FIFO Status Register
    __IO uint32_t TARGET_PECCTL;                    // (@ 0x00001274) I2C Target PEC Control Register
    __I  uint32_t TARGET_PECSR;                     // (@ 0x00001278) I2C Target PEC Status Register
} I2C_SLAVE_Regs;


typedef struct{
    __IO uint32_t MSA;                             // (@ 0x00001210) I2C Controller Own Address
    __IO uint32_t MCTR;                            // (@ 0x00001214) I2C Controller Control Register
    __IO uint32_t MSR;                             // (@ 0x00001218) I2C Controller Status Register
    __I  uint32_t MRXDATA;                         // (@ 0x0000121C) I2C Controller RXData 
    __IO uint32_t MTXDATA;                         // (@ 0x00001220) I2C Controller TXData 
    __IO uint32_t MTPR;                            // (@ 0x00001224) I2C Controller Timer Period
    __IO uint32_t MCR;                             // (@ 0x00001228) I2C Controller Configuration
         uint32_t RESERVED0[2];
    __I  uint32_t MBMON;                           // (@ 0x00001234) I2C Controller Bus Monitor
    __IO uint32_t MFIFOCTL;                        // (@ 0x00001238) I2C Controller FIFO Control register
    __I  uint32_t MFIFOSR;                         // (@ 0x0000123C) I2C Controller FIFO Status register
    __IO uint32_t CONTROLLER_I2CPECCTL;            // (@ 0x00001240) I2C Controller PEC Control register                   
    __I  uint32_t CONTROLLER_PECSR;                // (@ 0x00001244) I2C Controller PEC Status register
} I2C_MASTER_Regs;

typedef struct{
    __I  uint32_t IIDX;                             // (@ 0x00001080) Interrupt index
         uint32_t RESERVED0;
    __IO uint32_t IMASK;                            // (@ 0x00001088) Interrupt mask                    
         uint32_t RESERVED1;
    __I  uint32_t RIS;                              // (@ 0x00001090) Raw interrupt status
         uint32_t RESERVED2;
    __I  uint32_t MIS;                              // (@ 0x00001098) Masked interrupt status
         uint32_t RESERVED3;
    __O  uint32_t ISET;                             // (@ 0x000010A0) Interrupt set
         uint32_t RESERVED4;
    __O  uint32_t ICLR;                             // (@ 0x000010A8) Interrupt clear
} I2C_DMA_TRIG0_Regs;

typedef struct{
    __I  uint32_t IIDX;                             // (@ 0x00001050) Interrupt index
         uint32_t RESERVED0;
    __IO uint32_t IMASK;                            // (@ 0x00001058) Interrupt mask                    
         uint32_t RESERVED1;
    __I  uint32_t RIS;                              // (@ 0x00001060) Raw interrupt status
         uint32_t RESERVED2;
    __I  uint32_t MIS;                              // (@ 0x00001068) Masked interrupt status
         uint32_t RESERVED3;
    __O  uint32_t ISET;                             // (@ 0x00001070) Interrupt set
         uint32_t RESERVED4;
    __O  uint32_t ICLR;                             // (@ 0x00001078) Interrupt clear
} I2C_DMA_TRIG1_Regs;

typedef struct{
    __I  uint32_t IIDX;                             // (@ 0x00001020) Interrupt index register
         uint32_t RESERVED0;
    __IO uint32_t IMASK;                            // (@ 0x00001028) Interrupt mask
         uint32_t RESERVED1;
    __I  uint32_t RIS;                              // (@ 0x00001030) Raw interrupt status
         uint32_t RESERVED2;
    __I  uint32_t MIS;                              // (@ 0x00001038) Masked interrupt status
         uint32_t RESERVED3;
    __O  uint32_t ISET;                             // (@ 0x00001040) Interrupt set
         uint32_t RESERVED4;
    __O  uint32_t ICLR;                             // (@ 0x00001048) Interrupt clear
} I2C_CPU_INT_Regs;

typedef struct{
    __IO uint32_t PWREN;                    // (@ 0x00000800) Power enable
    __O  uint32_t RSTCTL;                   // (@ 0x00000804) Reset control
    __IO uint32_t CLKCFG;                   // (@ 0x00000808) Peripheral clock configuration register
         uint32_t RESERVED0[2];
    __I  uint32_t STAT;                     // (@ 0x00000814) Status register
} I2C_GPRCM_Regs;

typedef struct {
         uint32_t RESERVED0[512];
    I2C_GPRCM_Regs GPRCM;                   // (@ 0x00000800)
         uint32_t RESERVED1[506];
    __IO uint32_t CLKDIV;                   // (@ 0x00001000) Clock Divider
    __IO uint32_t CLKSEL;                   // (@ 0x00001004) Clock Select for Ultra Low Power Peripherals
         uint32_t RESERVED2[4];
    __IO uint32_t PDBGCTL;                  // (@ 0x00001018) Peripheral Debug Control
         uint32_t RESERVED3;
    I2C_CPU_INT_Regs CPU_INT;               // (@ 0x00001020)
         uint32_t RESERVED4;
    I2C_DMA_TRIG1_Regs DMA_TRIG1;           // (@ 0x00001050)
         uint32_t RESERVED5;
    I2C_DMA_TRIG0_Regs DMA_TRIG0;           // (@ 0x00001080)
         uint32_t RESERVED6[13];
    __IO uint32_t EVT_MODE;                 // (@ 0x000010E0) Event Mode
    __IO uint32_t INTCTL;                   // (@ 0x000010E4) Interrupt control register
         uint32_t RESERVED7[5];
    __I  uint32_t DESC;                     // (@ 0x000010FC) Module Description
         uint32_t RESERVED8[64];
    __IO uint32_t GFCTL;                    // (@ 0x00001200) I2C Glitch Filter Control
    __IO uint32_t TIMEOUT_CTL;              // (@ 0x00001204) I2C Timeout Count Control Register
    __I  uint32_t TIMEOUT_CNT;              // (@ 0x00001208) I2C Timeout Count Register
         uint32_t RESERVED9;
    I2C_MASTER_Regs MASTER;                 // (@ 0x00001210)
         uint32_t RESERVED10[2];
    I2C_SLAVE_Regs SLAVE;                   // (@ 0x00001250)
} I2C_Regs;



#endif //MSPM0L1306_I2C_H