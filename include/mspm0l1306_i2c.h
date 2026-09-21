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

#define I2C ((I2C_Regs *) I2C0_BASE)

// CLKDIV enum

typedef enum{
     I2C_CLKDIV_NO_DIV = 0U,
     I2C_CLKDIV_2_DIV  = 1U,
     I2C_CLKDIV_3_DIV  = 2U,
     I2C_CLKDIV_4_DIV  = 3U,
     I2C_CLKDIV_5_DIV  = 4U,
     I2C_CLKDIV_6_DIV  = 5U,
     I2C_CLKDIV_7_DIV  = 6U,
     I2C_CLKDIV_8_DIV  = 7U,
} i2c_clock_div_t;


// CLKSEL enum

typedef enum{
     I2C_CLKSEL_MFCLK  = 2U,
     I2C_CLKSEL_BUSCLK = 3U,
} i2c_clock_t;

typedef enum{
     I2C_DIR_TRANSMIT = 0U,
     I2C_DIR_RECEIVE  = 1U,
} i2c_direction_t;

typedef enum{
     I2C_ADDR_MODE_7BIT  = 0U,
     I2C_ADDR_MODE_10BIT = 1U,
} i2c_addr_mode_t;

// RSTCTL Macros

#define I2C_RSTCTL_KEY_UNLOCK_W         (0xB1000000U)
#define I2C_RSTCTL_RESETASSERT          (1U)

// CLKSEL Macros

#define I2C_CLKSEL_BUSCLK_SEL_OFS       (3U)
#define I2C_CLKSEL_MFCLK_SEL_OFS        (2U)

// CLKDIV Macros

#define I2C_CLKDIV_RATIO_OFS            (0U)
#define I2C_CLKDIV_RATIO_WIDTH          (3U)

// CSA Macros

#define I2C_CSA_DIR_OFS                 (0U)
#define I2C_CSA_TADDR_OFS               (1U)
#define I2C_CSA_TADDR_WIDTH             (10U)
#define I2C_CSA_CMODE_OFS               (15U)

// CCTR Macros

#define I2C_CCTR_BURSTRUN_OFS           (0U)
#define I2C_CCTR_START_OFS              (1U)
#define I2C_CCTR_STOP_OFS               (2U)
#define I2C_CCTR_ACK_OFS                (3U)
#define I2C_CCTR_CACKOEN_OFS            (4U)
#define I2C_CCTR_RD_ON_TXEMPTY_OFS      (5U)
#define I2C_CCTR_CBLEN_OFS              (16U)
#define I2C_CCTR_CBLEN_WIDTH            (12U)

// CSR Macros

#define I2C_CSR_BUSY_OFS                (0U)
#define I2C_CSR_ERR_OFS                 (1U)
#define I2C_CSR_ADRACK_OFS              (2U)
#define I2C_CSR_DATACK_OFS              (3U)
#define I2C_CSR_ARBLST_OFS              (4U)
#define I2C_CSR_IDLE_OFS                (5U)
#define I2C_CSR_BUSBSY_OFS              (6U)
#define I2C_CSR_CBCNT_OFS               (16U)
#define I2C_CSR_CBCNT_WIDTH             (12U)

// MRXDATA Macros

#define I2C_MRXDATA_VALUE_OFS           (0U)
#define I2C_MRXDATA_VALUE_WIDTH         (8U)

// MTXDATA Macros

#define I2C_MTXDATA_VALUE_OFS           (0U)
#define I2C_MTXDATA_VALUE_WIDTH         (8U)

// CTPR Macros

#define I2C_CTRP_TPR_OFS                (0U)
#define I2C_CTRP_TPR_WIDTH              (7U)

// CPR Macros

#define I2C_CCR_ACTIVE_OFS              (0U)
#define I2C_CCR_MCTL_OFS                (1U)
#define I2C_CCR_CLKSTRETCH_OFS          (2U)
#define I2C_CCR_LPBK_OFS                (8U)

// CFIFOSR Macros

#define I2C_CFIFOSR_TXFIFOCNT_OFS       (8U)
#define I2C_CFIFOSR_TXFIFOCNT_WIDTH     (4U)
#define I2C_CFIFOSR_RXFIFOCNT_OFS       (0U)
#define I2C_CFIFOSR_RXFIFOCNT_WIDTH     (4U)

//=======================================Configuration Functions==================================

void i2c_reset                               (void);
void i2c_power_enable                        (void);
void i2c_power_disable                       (void);

void i2c_enable                              (void);
void i2c_disable                             (void);

void i2c_set_clock_configuration             (i2c_clock_t clock, i2c_clock_div_t divider);
void i2c_set_baudrate                        (uint32_t clock_freq, uint32_t target_freq);

void i2c_set_addressing_mode                 (i2c_addr_mode_t addr_mode);
void i2c_set_target                          (uint32_t address);
void i2c_set_direction                       (i2c_direction_t direction);

uint8_t i2c_send_byte                        (uint8_t data_addr, uint8_t data, uint8_t send_start, uint8_t send_stop);
uint8_t set_start_addr                       (uint8_t data, uint8_t send_start, uint8_t send_stop);
uint8_t i2c_receive_byte                     (uint8_t ack, uint8_t send_start, uint8_t send_stop, uint8_t *out);
uint8_t i2c_read_buffer                      (uint8_t mem_addr, uint8_t *data, uint32_t length);
uint8_t i2c_write_buffer                     (uint8_t mem_addr, const uint8_t *data, uint32_t length);

uint8_t i2c_bus_is_busy                      (void);
uint8_t i2c_is_busy                          (void);
uint8_t i2c_had_error                        (void);
uint8_t i2c_address_acked                    (void);
#endif //MSPM0L1306_I2C_H