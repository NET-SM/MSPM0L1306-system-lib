#ifndef MSPM0L1306_BASE_H
#define MSPM0L1306_BASE_H

#include <stdint.h>

// ============================================================================
// CMSIS-style access qualifiers
// ============================================================================

#define __IO volatile           /* read-write */
#define __I  volatile const     /* read-only  */
#define __O  volatile           /* write-only */

#define ENABLE  1U
#define DISABLE 0U

// ============================================================================
// Interrupt Definitions 
// ============================================================================

typedef enum IRQn
{
  NonMaskableInt_IRQn         = -14,    /* 2  Non Maskable Interrupt */
  HardFault_IRQn              = -13,    /* 3  Hard Fault Interrupt */
  SVCall_IRQn                 = -5,     /* 11 SV Call Interrupt */
  PendSV_IRQn                 = -2,     /* 14 Pend SV Interrupt */
  SysTick_IRQn                = -1,     /* 15 System Tick Interrupt */
  FLASHCTL_INT_IRQn           = 0,      /* 16 FLASHCTL_INT Interrupt */
  WWDT0_INT_IRQn              = 0,      /* 16 WWDT0_INT Interrupt */
  DEBUGSS_INT_IRQn            = 0,      /* 16 DEBUGSS_INT Interrupt */
  SYSCTL_INT_IRQn             = 0,      /* 16 SYSCTL_INT Interrupt */
  GPIOA_INT_IRQn              = 1,      /* 17 GPIOA_INT Interrupt */
  COMP0_INT_IRQn              = 1,      /* 17 COMP0_INT Interrupt */
  TIMG1_INT_IRQn              = 2,      /* 18 TIMG1_INT Interrupt */
  ADC0_INT_IRQn               = 4,      /* 19 ADC0_INT Interrupt */
  SPI0_INT_IRQn               = 9,      /* 25 SPI0_INT Interrupt */
  UART1_INT_IRQn              = 13,     /* 29 UART1_INT Interrupt */
  UART0_INT_IRQn              = 15,     /* 31 UART0_INT Interrupt */
  TIMG0_INT_IRQn              = 16,     /* 32 TIMG0_INT Interrupt */
  TIMG2_INT_IRQn              = 18,     /* 34 TIMG2_INT Interrupt */
  TIMG4_INT_IRQn              = 20,     /* 36 TIMG4_INT Interrupt */
  I2C0_INT_IRQn               = 24,     /* 40 I2C0_INT Interrupt */
  I2C1_INT_IRQn               = 25,     /* 41 I2C1_INT Interrupt */
  DMA_INT_IRQn                = 31,     /* 47 DMA_INT Interrupt */
} IRQn_Type;

// ============================================================================
// Base adrese svih perifernih modula (MSPM0L1306)
// ============================================================================

#define UART0_BASE                     (0x40108000U)     /*!< Base address of module UART0 */
#define FLASHCTL_BASE                  (0x400CD000U)     /*!< Base address of module FLASHCTL */
#define SPI0_BASE                      (0x40468000U)     /*!< Base address of module SPI0 */
#define I2C0_BASE                      (0x400F0000U)     /*!< Base address of module I2C0 */
#define CPUSS_BASE                     (0x40400000U)     /*!< Base address of module CPUSS */
#define GPIOA_BASE                     (0x400A0000U)     /*!< Base address of module GPIOA */
#define UART1_BASE                     (0x40100000U)     /*!< Base address of module UART10 */
#define WWDT0_BASE                     (0x40080000U)     /*!< Base address of module WWDT0 */
#define DEBUGSS_BASE                   (0x400C7000U)     /*!< Base address of module DEBUGSS */
#define VREF_BASE                      (0x40030000U)     /*!< Base address of module VREF */
#define CRC_BASE                       (0x40440000U)     /*!< Base address of module CRC */
#define OPA0_BASE                      (0x40020000U)     /*!< Base address of module OPAMP0 */
#define TIMG1_BASE                     (0x40086000U)     /*!< Base address of module TIMG1 */
#define DMA_BASE                       (0x4042A000U)     /*!< Base address of module DMA */
#define COMP0_BASE                     (0x40008000U)     /*!< Base address of module COMP0 */
#define SYSCTL_BASE                    (0x400AF000U)     /*!< Base address of module SYSCTL */
#define OPA1_BASE                      (0x40022000U)     /*!< Base address of module OPAMP1 */
#define I2C1_BASE                      (0x400F2000U)     /*!< Base address of module I2C1 */
#define TIMG0_BASE                     (0x40084000U)     /*!< Base address of module TIMG0 */
#define IOMUX_BASE                     (0x40428000U)     /*!< Base address of module IOMUX */
#define TIMG2_BASE                     (0x40088000U)     /*!< Base address of module TIMG2 */
#define TIMG4_BASE                     (0x4008C000U)     /*!< Base address of module TIMG4 */
#define ADC0_BASE                      (0x40004000U)     /*!< Base address of module ADC0 */
#define ADC0_PERIPHERALREGIONSVT_BASE  (0x4055A000U)     /*!< Base address of module ADC0_PERIPHERALREGIONSVT */
#define WUC_BASE                       (0x40424000U)     /*!< Base address of module WUC */
#define FACTORYREGION_BASE             (0x41C40000U)     /*!< Base address of module FACTORYREGION */


// PWREN Reg

#define PWREN_KEY_UNLOCK_W             (0x26000000U)



#endif