#ifndef MSP_MINIMAL_H
#define MSP_MINIMAL_H

#include <stdint.h>

// CMSIS - style access qualifies

#define __IO volatile
#define __I volatile const
#define __O volatile 

// Base:

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

// ============================================================================
// SYSCTL modul (0x400AF000)
// ============================================================================

typedef struct {
       uint32_t RESERVED0[8];
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) SYSCTL interrupt index */
       uint32_t RESERVED1;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001028) SYSCTL interrupt mask */
       uint32_t RESERVED2;
  __I  uint32_t RIS;                               /* !< (@ 0x00001030) SYSCTL raw interrupt status */
       uint32_t RESERVED3;
  __I  uint32_t MIS;                               /* !< (@ 0x00001038) SYSCTL masked interrupt status */
       uint32_t RESERVED4;
  __O  uint32_t ISET;                              /* !< (@ 0x00001040) SYSCTL interrupt set */
       uint32_t RESERVED5;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001048) SYSCTL interrupt clear */
       uint32_t RESERVED6;
  __I  uint32_t NMIIIDX;                           /* !< (@ 0x00001050) NMI interrupt index */
       uint32_t RESERVED7[3];
  __I  uint32_t NMIRIS;                            /* !< (@ 0x00001060) NMI raw interrupt status */
       uint32_t RESERVED8[3];
  __O  uint32_t NMIISET;                           /* !< (@ 0x00001070) NMI interrupt set */
       uint32_t RESERVED9;
  __O  uint32_t NMIICLR;                           /* !< (@ 0x00001078) NMI interrupt clear */
       uint32_t RESERVED10[33];
  __IO uint32_t SYSOSCCFG;                         /* !< (@ 0x00001100) SYSOSC configuration */
  __IO uint32_t MCLKCFG;                           /* !< (@ 0x00001104) Main clock (MCLK) configuration */
       uint32_t RESERVED11[12];
  __IO uint32_t GENCLKCFG;                         /* !< (@ 0x00001138) General clock configuration */
  __IO uint32_t GENCLKEN;                          /* !< (@ 0x0000113C) General clock enable control */
  __IO uint32_t PMODECFG;                          /* !< (@ 0x00001140) Power mode configuration */
       uint32_t RESERVED12[3];
  __I  uint32_t FCC;                               /* !< (@ 0x00001150) Frequency clock counter (FCC) count */
       uint32_t RESERVED13[7];
  __IO uint32_t SYSOSCTRIMUSER;                    /* !< (@ 0x00001170) SYSOSC user-specified trim */
       uint32_t RESERVED14;
  __IO uint32_t SRAMBOUNDARY;                      /* !< (@ 0x00001178) SRAM Write Boundary */
       uint32_t RESERVED15;
  __IO uint32_t SYSTEMCFG;                         /* !< (@ 0x00001180) System configuration */
       uint32_t RESERVED16[31];
  __IO uint32_t WRITELOCK;                         /* !< (@ 0x00001200) SYSCTL register write lockout */
  __I  uint32_t CLKSTATUS;                         /* !< (@ 0x00001204) Clock module (CKM) status */
  __I  uint32_t SYSSTATUS;                         /* !< (@ 0x00001208) System status information */
       uint32_t RESERVED17[5];
  __I  uint32_t RSTCAUSE;                          /* !< (@ 0x00001220) Reset cause */
       uint32_t RESERVED18[55];
  __IO uint32_t RESETLEVEL;                        /* !< (@ 0x00001300) Reset level for application-triggered reset command */
  __O  uint32_t RESETCMD;                          /* !< (@ 0x00001304) Execute an application-triggered reset command */
  __IO uint32_t BORTHRESHOLD;                      /* !< (@ 0x00001308) BOR threshold selection */
  __O  uint32_t BORCLRCMD;                         /* !< (@ 0x0000130C) Set the BOR threshold */
  __O  uint32_t SYSOSCFCLCTL;                      /* !< (@ 0x00001310) SYSOSC frequency correction loop (FCL) ROSC enable */
       uint32_t RESERVED19[2];
  __O  uint32_t SHDNIOREL;                         /* !< (@ 0x0000131C) SHUTDOWN IO release control */
  __O  uint32_t EXRSTPIN;                          /* !< (@ 0x00001320) Disable the reset function of the NRST pin */
  __O  uint32_t SYSSTATUSCLR;                      /* !< (@ 0x00001324) Clear sticky bits of SYSSTATUS */
  __O  uint32_t SWDCFG;                            /* !< (@ 0x00001328) Disable the SWD function on the SWD pins */
  __O  uint32_t FCCCMD;                            /* !< (@ 0x0000132C) Frequency clock counter start capture */
       uint32_t RESERVED20[20];
  __IO uint32_t PMUOPAMP;                          /* !< (@ 0x00001380) GPAMP control */
       uint32_t RESERVED21[31];
  __IO uint32_t SHUTDNSTORE0;                      /* !< (@ 0x00001400) Shutdown storage memory (byte 0) */
  __IO uint32_t SHUTDNSTORE1;                      /* !< (@ 0x00001404) Shutdown storage memory (byte 1) */
  __IO uint32_t SHUTDNSTORE2;                      /* !< (@ 0x00001408) Shutdown storage memory (byte 2) */
  __IO uint32_t SHUTDNSTORE3;                      /* !< (@ 0x0000140C) Shutdown storage memory (byte 3) */
} SYSCTL_SOCLOCK_Regs;

typedef struct {
       uint32_t RESERVED0[1024];
  SYSCTL_SOCLOCK_Regs  SOCLOCK;                    /* @ 0x1000 */
} SYSCTL_Regs;

#define SYSCTL  ((SYSCTL_Regs *) SYSCTL_BASE)

// ============================================================================
// SYSCTL SYSOSCCFG registar (0x400AF000)
// ============================================================================

#define SYSCTL_SYSOSCCFG_FREQ_MASK          (0x00000003U)
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCBASE    (0x00000000U)  // 32 MHz
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSC4M      (0x00000001U)  // 4 MHz
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCUSER    (0x00000002U)  // 16/24 MHz
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCTURBO   (0x00000003U)  // 48 MHz

// ============================================================================
// SYSCTL MCLKCFG registar (0x400AF004)
// ============================================================================

#define SYSCTL_MCLKCFG_MDIV_MASK            (0x0000000FU)
#define SYSCTL_MCLKCFG_MDIV_1               (0x00000000U)  // /1 (no divider)
#define SYSCTL_MCLKCFG_MDIV_2               (0x00000001U)  // /2
#define SYSCTL_MCLKCFG_MDIV_16              (0x0000000FU)  // /16


// ============================================================================
// IOMUX (0x40428000U)
// ============================================================================

/* IOMUX_PINCM27[PF] Bits */
#define IOMUX_PINCM27_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM27_PF_GPIOA_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM27_PF_TIMG1_CCP0                   ((uint32_t)0X00000002)
#define IOMUX_PINCM27_PF_UART0_RX                     ((uint32_t)0X00000003)
#define IOMUX_PINCM27_PF_SPI0_POCI                    ((uint32_t)0X00000004)

#define IOMUX_PINCM_PC_CONNECTED                      ((uint32_t)0x00000080U) 

typedef struct {
       uint32_t RESERVED0;
  __IO uint32_t PINCM[251];                        /* !< (@ 0x00000004) Pin Control Management Register in SECCFG region */
} IOMUX_SECCFG_Regs;

typedef struct {
  IOMUX_SECCFG_Regs  SECCFG;                       /* !< (@ 0x00000000) SECCFG register region */
} IOMUX_Regs;

#define IOMUX ((IOMUX_Regs * )IOMUX_BASE)


// ============================================================================
// GPIOA modul (0x400A0000U)
// ============================================================================

#define GPIO_PWREN_ENABLE_ENABLE   (0x00000001U)
#define GPIO_PWREN_KEY_UNLOCK_W    (0x26000000U)
#define LED2_PIN                   (1U << 26) 

typedef struct{
    __IO uint32_t PWREN;   /*(0x00000800) Power enable*/
         uint32_t RESERVED[5]; 
    // TODO: dodati RSTCTL - Reset control,  STAT- Status Register kasnije

} GPIO_GPRCM_Regs;

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;
  __IO uint32_t FSUB_1;
       uint32_t RESERVED1[15];
  __IO uint32_t FPUB_0;
  __IO uint32_t FPUB_1;
       uint32_t RESERVED2[237];
  GPIO_GPRCM_Regs GPRCM;                  /* @ 0x00000800 */
       uint32_t RESERVED3[510];
  __IO uint32_t CLKOVR;
       uint32_t RESERVED4;
  __IO uint32_t PDBGCTL;
       uint32_t RESERVED5;
       uint32_t RESERVED_CPU_INT[11];      /* @ 0x0000 1020*/
       uint32_t RESERVED6;
       uint32_t RESERVED_GEN_EVENT0[11];    /* @ 0x0000 1050*/
       uint32_t RESERVED7;
       uint32_t RESERVED_GEN_EVENT1[11];    /* @ 0x0000 1080*/
       uint32_t RESERVED8[13];
  __IO uint32_t EVT_MODE;                   /* @ 0x0000 10E0*/
       uint32_t RESERVED9[6];
  __I  uint32_t DESC;
       uint32_t RESERVED10[64];
  __O  uint32_t DOUT3_0;
  __O  uint32_t DOUT7_4;
  __O  uint32_t DOUT11_8;
  __O  uint32_t DOUT15_12;
  __O  uint32_t DOUT19_16;
  __O  uint32_t DOUT23_20;
  __O  uint32_t DOUT27_24;
  __O  uint32_t DOUT31_28;
       uint32_t RESERVED11[24];
  __IO uint32_t DOUT31_0;                 /* @ 0x00001280 */
       uint32_t RESERVED12[3];
  __O  uint32_t DOUTSET31_0;              /* @ 0x00001290 */
       uint32_t RESERVED13[3];
  __O  uint32_t DOUTCLR31_0;              /* @ 0x000012A0 */
       uint32_t RESERVED14[3];
  __O  uint32_t DOUTTGL31_0;              /* @ 0x000012B0 */
       uint32_t RESERVED15[3];
  __IO uint32_t DOE31_0;                  /* @ 0x000012C0 */
} GPIO_Regs;

#define GPIOA ((GPIO_Regs * ) GPIOA_BASE)



#endif