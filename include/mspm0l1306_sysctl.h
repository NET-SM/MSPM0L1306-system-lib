#ifndef MSPM0L1306_SYSCTL_H

#include "mspm0l1306_base.h"

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

#define SYSCTL ((SYSCTL_Regs *) SYSCTL_BASE)

// ============================================================================
// SYSCTL SYSOSCCFG registar (0x400AF000)
// ============================================================================

#define SYSCTL_SYSOSCCFG_FREQ_MASK          (0x00000003U)
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCBASE    (0x00000000U)  // 32 MHz
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSC4M      (0x00000001U)  // 4 MHz
#define SYSCTL_SYSOSCCFG_FREQ_SYSOSCUSER    (0x00000002U)  // 16/24 MHz

// ============================================================================
// SYSCTL MCLKCFG registar (0x400AF004)
// ============================================================================

#define SYSCTL_MCLKCFG_MDIV_MASK            (0x0000000FU)
#define SYSCTL_MCLKCFG_MDIV_1               (0x00000000U)  // /1 (no divider)
#define SYSCTL_MCLKCFG_MDIV_2               (0x00000001U)  // /2
#define SYSCTL_MCLKCFG_MDIV_16              (0x0000000FU)  // /16

// ============================================================================
// SYSCTL CLKSTATUS registar (offset 0x1204) - read-only
// ============================================================================

#define SYSCTL_CLKSTATUS_SYSOSCFREQ_MASK    (0x00000003U) 

// ============================================================================
// SYSCTL SYSOSCTRIMUSER registar (offset 0x1170) 
// ============================================================================

#define SYSCTL_SYSOSCTRIMUSER_FREQ_OFS            (0)
#define SYSCTL_SYSOSCTRIMUSER_FREQ_MASK           (0x00000003U)

#define SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC16M      (0x00000001U)
#define SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC24M      (0x00000002U)

#define SYSCTL_SYSOSCTRIMUSER_CAP_OFS             (4)
#define SYSCTL_SYSOSCTRIMUSER_CAP_MASK            (0x00000070U)

#define SYSCTL_SYSOSCTRIMUSER_RESCOARSE_OFS       (8)
#define SYSCTL_SYSOSCTRIMUSER_RESCOARSE_MASK      (0x00003F00U)

#define SYSCTL_SYSOSCTRIMUSER_RESFINE_OFS         (16)
#define SYSCTL_SYSOSCTRIMUSER_RESFINE_MASK        (0x000F0000U)

#define SYSCTL_SYSOSCTRIMUSER_RDIV_OFS            (20)
#define SYSCTL_SYSOSCTRIMUSER_RDIV_MASK           (0x1FF00000U)

// ============================================================================
// SYSCTL GENCLKCFG registar (offset 0x1138) 
// ============================================================================

#define SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS           (24)
#define SYSCTL_GENCLKCFG_FCCTRIGCNT_MASK          (0x1F000000U)


#define SYSCTL_GENCLKCFG_ANACPUMPCCFG_OFS         (22)
#define SYSCTL_GENCLKCFG_ANACPUMPCCFG_MASK        (0x00C00000U)

#define SYSCTL_GENCLKCFG_ANACPUMPCCFG_ONDEMAND    (0x00000000U)
#define SYSCTL_GENCLKCFG_ANACPUMPCCFG_ONACTIVE    (0x00400000U)
#define SYSCTL_GENCLKCFG_ANACPUMPCCFG_ONALWAYS    (0x00800000U)


#define SYSCTL_GENCLKCFG_FCCLVLTRIG_OFS           (21)
#define SYSCTL_GENCLKCFG_FCCLVLTRIG_MASK          (0x00200000U)

#define SYSCTL_GENCLKCFG_FCCLVLTRIG_RISE2RISE     (0x00000000U)
#define SYSCTL_GENCLKCFG_FCCLVLTRIG_LEVEL         (0x00200000U) 


#define SYSCTL_GENCLKCFG_FCCTRIGSRC_OFS           (20)
#define SYSCTL_GENCLKCFG_FCCTRIGSRC_MASK          (0x00100000U)

#define SYSCTL_GENCLKCFG_FCCTRIGSRC_EXTPIN        (0x00000000U)         
#define SYSCTL_GENCLKCFG_FCCTRIGSRC_LFCLK         (0x00100000U)         


#define SYSCTL_GENCLKCFG_FCCSELCLK_OFS            (16)
#define SYSCTL_GENCLKCFG_FCCSELCLK_MASK           (0x000F0000U)

#define SYSCTL_GENCLKCFG_FCCSELCLK_MCLK           (0x00000000U)            
#define SYSCTL_GENCLKCFG_FCCSELCLK_SYSOSC         (0x00010000U)            
#define SYSCTL_GENCLKCFG_FCCSELCLK_EXTCLK         (0x00030000U)        
#define SYSCTL_GENCLKCFG_FCCSELCLK_FCCIN          (0x00070000U)

#define SYSCTL_GENCLKCFG_EXCLKDIVEN_OFS           (7)
#define SYSCTL_GENCLKCFG_EXCLKDIVEN_MASK          (0x00000080U)

#define SYSCTL_GENCLKCFG_EXCLKDIVEN_PASSTHRU      (0x00000000U)
#define SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE        (0x00000080U)


#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_OFS          (4)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_MASK         (0x00000070U)

#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV2         (0x00000000U)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV4         (0x00000010U)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV6         (0x00000020U)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV8         (0x00000030U)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV10        (0x00000040U)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV12        (0x00000050U)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV14        (0x00000060U)
#define SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV16        (0x00000070U)


#define SYSCTL_GENCLKCFG_EXCLKSRC_OFS             (0)
#define SYSCTL_GENCLKCFG_EXCLKSRC_MASK            (0x00000007U)

#define SYSCTL_GENCLKCFG_EXCLKSRC_SYSOSC          (0x00000000U)
#define SYSCTL_GENCLKCFG_EXCLKSRC_UPCLK           (0x00000001U)
#define SYSCTL_GENCLKCFG_EXCLKSRC_LFCLK           (0x00000002U)
#define SYSCTL_GENCLKCFG_EXCLKSRC_MFPCLK          (0x00000003U)

// ============================================================================
// SYSCTL GENCLKEN registar (offset 0x113C) 
// ============================================================================

#define SYSCTL_GENCLKEN_MFPCLKEN_OFS              (4)
#define SYSCTL_GENCLKEN_MFPCLKEN_MASK             (0x00000010U)

#define SYSCTL_GENCLKEN_MFPCLKEN_DISABLE          (0x00000000U)
#define SYSCTL_GENCLKEN_MFPCLKEN_ENABLE           (0x00000010U)

#define SYSCTL_GENCLKEN_EXCLKEN_OFS               (0)
#define SYSCTL_GENCLKEN_EXCLKEN_MASK              (0x00000001U)

#define SYSCTL_GENCLKEN_EXCLKEN_DISABLE           (0x00000000U)
#define SYSCTL_GENCLKEN_EXCLKEN_ENABLE            (0x00000001U)

#endif // MSPM0L1306_SYSCTL_H