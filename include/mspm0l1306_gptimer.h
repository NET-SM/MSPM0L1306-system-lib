#ifndef MSPM0L1306_GPTIMER_H
#define MSPM0L1306_GPTIMER_H

#include "mspm0l1306_base.h"


typedef struct{
    __IO uint32_t CTR;                              // (@ 0x00001800) Counter register
    __IO uint32_t CTRCTL;                           // (@ 0x00001804) Counter Control Register
    __IO uint32_t LOAD;                             // (@ 0x00001808) Load register
         uint32_t RESERVED0;
    __IO uint32_t CC_01[2];                         // (@ 0x00001810) Capture or Compare register 0/1
    __IO uint32_t CC_23[2];                         // (@ 0x00001818) Capture or Compare register 2/3
    __IO uint32_t CC_45[2];                         // (@ 0x00001820) he CC_45 register are a registers which can be
                                                    //  used as compare to the current CTR to create an events CC4U, CC4D,
                                                    //  CC5U and CC5D
         uint32_t RESERVED1[2];
    __IO uint32_t CCCTL_01[2];                      // (@ 0x00001830) Capture or Comapre registers 0/1
    __IO uint32_t CCCTL_23[2];                      // (@ 0x00001838) Capture or Comapre registers 2/3
    __IO uint32_t CCCTL_45[2];                      // (@ 0x00001840) Capture or Comapre registers 4/5
         uint32_t RESERVED2[2];
    __IO uint32_t OCTL_01[2];                       // (@ 0x00001850) CCP Output Control Register 0/1
    __IO uint32_t OCTL_23[2];                       // (@ 0x00001858) CCP Output Control Register 2/3
         uint32_t RESERVED3[4];
    __IO uint32_t CCACT_01[2];                      // (@ 0x00001870) Capture or Compare Action Registers 0/1
    __IO uint32_t CCACT_23[2];                      // (@ 0x00001878) Capture or Compare Action Registers 2/3
    __IO uint32_t IFCTL_01[2];                      // (@ 0x00001880) Input Filter Control Register 0/1
    __IO uint32_t IFCTL_23[2];                      // (@ 0x00001888) Input Filter Control Register 2/3
         uint32_t RESERVED4[4];
    __IO uint32_t PL;                               // (@ 0x000018A0) Phase Load Register
    __IO uint32_t DBCTL;                            // (@ 0x000018A4) Dead Band insertion control register
         uint32_t RESERVED5[2];
    __IO uint32_t TSEL;                             // (@ 0x000018B0) Trigger Select Register
    __I  uint32_t RC;                               // (@ 0x000018B4) Repeat counter Register
    __IO uint32_t RCLD;                             // (@ 0x000018B8) Repeat counter load Register
    __I  uint32_t QDIR;                             // (@ 0x000018BC) QEI Count Direction Register
         uint32_t RESERVED6[4];
    __IO uint32_t FCTL;                             // (@ 0x000018D0) Fault Control Register
    __IO uint32_t FIFCTL;                           // (@ 0x000018D4) Fault input Filter control register
} GPTIMER_COUNTERREGS_Regs;

typedef struct{
    __IO uint32_t CCPD;                             // (@ 0x00001100) CCP Direction
    __IO uint32_t ODIS;                             // (@ 0x00001104) Output disable
    __IO uint32_t CCLKCTL;                          // (@ 0x00001108) Counter Clock Control Register
    __IO uint32_t CPS;                              // (@ 0x0000110C) Clock prescale register
    __I  uint32_t CPSV;                             // (@ 0x00001110) Clock prescale count status register
    __IO uint32_t CTTRIGCTL;                        // (@ 0x00001114) Timer Cross Trigger Control Register
         uint32_t RESERVED0;
    __O  uint32_t CTTRIG;                           // (@ 0x0000111C) Timer Cross Trigger Register
    __IO uint32_t FSCTL;                            // (@ 0x00001120) Fault Source Control
    __IO uint32_t GCTL;                             // (@ 0x00001124) Global control register    
} GPTIMER_COMMONREGS_Regs;

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
} GPTIMER_GEN_EVENT1_Regs;

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
} GPTIMER_GEN_EVENT0_Regs;

typedef struct {
    __I  uint32_t IIDX;                             // (@ 0x00001020) Interrupt index
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
} GPTIMER_CPU_INT_Regs;

typedef  struct {
    __IO uint32_t PWREN;                            // (@ 0x00000800) Power enable
    __O  uint32_t RSTCTL;                           // (@ 0x00000804) Reset control
         uint32_t RESERVED0[3];
    __IO uint32_t STAT;                             // (@ 0x00000814) Status register
} GPTIMER_GPRCM_Regs;

typedef struct {
          uint32_t RESERVED0[256];                      
     __IO uint32_t FSUB_0;                          // (@ 0x00000400) Subscriber port 0                               
     __IO uint32_t FSUB_1;                          // (@ 0x00000404) Subscriber port 1
          uint32_t RESERVED1[15];
     __IO uint32_t FPUB_0;                          // (@ 0x00000444) Publisher port 0
     __IO uint32_t FPUB_1;                          // (@ 0x00000448) Publisher port 1
          uint32_t RESERVED2[237];
     GPTIMER_GPRCM_Regs GPRCM;                      // (@ 0x00000800)
          uint32_t RESERVED3[506];
     __IO uint32_t CLKDIV;                          // (@ 0x00001000) Clock Divider
          uint32_t RESERVED4;
     __IO uint32_t CLKSEL;                          // (@ 0x00001008) Clock Select for Ultra Low Power peripheral
          uint32_t RESERVED5[3];
     __IO uint32_t PDBGCTL;                         // (@ 0x00001018) Peripheral Debug Control
          uint32_t RESERVED6;
     GPTIMER_CPU_INT_Regs CPU_INT;                  // (@ 0x00001020)
          uint32_t RESERVED7;
     GPTIMER_GEN_EVENT0_Regs GEN_EVENT0;            // (@ 0x00001050)
          uint32_t RESERVED8;
     GPTIMER_GEN_EVENT1_Regs GEN_EVENT1;            // (@ 0x00001080)
          uint32_t RESERVED9[13];
     __IO uint32_t EVT_MODE;                        // (@ 0x000010E0) Event mode
          uint32_t RESERVED10[6];
     __I  uint32_t DESC;                            // (@ 0x000010FC) Module Description
     GPTIMER_COMMONREGS_Regs COMMONREGS;            // (@ 0x00001100)
          uint32_t RESERVED11[438];
     GPTIMER_COUNTERREGS_Regs COUNTERREGS;          // (@ 0x00001800)

} GPTIMER_Regs;

#define GPTIMER ((GPTIMER_Regs *) TIMG0_BASE)


// CLKDIV enum

typedef enum{
     GPTimer_CLKDIV_NO_DIV = 0U,
     GPTimer_CLKDIV_2_DIV  = 1U,
     GPTimer_CLKDIV_3_DIV  = 2U,
     GPTimer_CLKDIV_4_DIV  = 3U,
     GPTimer_CLKDIV_5_DIV  = 4U,
     GPTimer_CLKDIV_6_DIV  = 5U,
     GPTimer_CLKDIV_7_DIV  = 6U,
     GPTimer_CLKDIV_8_DIV  = 7U,
} gptimer_clock_div_t;

// CLKSEL enum

typedef enum{
     GPTimer_CLKSEL_LFCLK  = 1U,
     GPTimer_CLKSEL_MFCLK  = 2U,
     GPTimer_CLKSEL_BUSCLK = 3U,
} gptimer_clock_t;

// CTRCTL.CM enum
typedef enum{
     GPTimer_CM_DOWN          = 0U,
     GPTimer_CM_UP_DOWN       = 1U,
     GPTimer_CM_UP            = 2U,
} gptimer_count_mode_t;

// CTRCTL.CVAE enum
typedef enum{
     GPTimer_LOAD_VALUE       = 0U,
     GPTimer_UNCHANGED_VALUE  = 1U,
     GPTimer_ZERO_VALUE       = 2U,
} gptimer_cvae_t;

// CTRCTL.REPEAT enum
typedef enum{
     GPTimer_REPEAT_ONE_SHOT            = 0U,
     GPTimer_REPEAT_CONTINUE            = 1U,
     GPTimer_REPEAT_CONTINUE_DEBUG_STOP = 3U,
} gptimer_repeat_t;

// CCCTL.COC enum
typedef enum{
     GPTimer_COC_MODE_COMPARE           = 0U,
     GPTimer_COC_MODE_CAPTURE           = 1U,
} gptimer_coc_mode_t;

// CCPD enum
typedef enum{
     GPTimer_CCPD_DIR_INPUT             = 0U,
     GPTimer_CCPD_DIR_OUTPUT            = 1U,
} gptimer_ccpd_direction_t;

// CCACT enum for CCP
typedef enum{
     GPTimer_ACTION_DISABLED            = 0U,
     GPTimer_ACTION_SET_HIGH            = 1U,
     GPTimer_ACTION_SET_LOW             = 2U,
     GPTimer_ACTION_TOGGLE              = 3U,
} gptimer_ccp_action_t;

// OCTL enum
typedef enum{
     GPTimer_CCPO_SIGNAL_GEN            = 0U,
     GPTimer_CCPO_LOAD_EVENT            = 1U,
     GPTimer_CCPO_CCU_CCD_EVENT         = 2U,
     GPTimer_CCPO_ZERO_EVENT            = 4U,
     GPTimer_CCPO_CAPTURE_EVENT         = 5U,
     GPTimer_CCPO_FAULT_CONDITION       = 6U,
     GPTimer_CCPO_MIRROR_CCP_FIRST      = 8U,
     GPTimer_CCPO_MIRROR_CCP_SECOND     = 9U,
     GPTimer_CCPO_SIGNAL_GEN_AFTER_DEADBAND_INSERTION = 12U,
     GPTimer_CCPO_COUNTER_DIRECTION     = 13U,
} gptimer_ccpo_source_t;

// CLKDIV Macros

#define GPTIMER_CLKDIV_RATIO_OFS             (0U)
#define GPTIMER_CLKDIV_RATIO_WIDTH           (3U)

// CLKSEL Macros

#define GPTIMER_CLKSEL_LFCLK_OFS             (1U)
#define GPTIMER_CLKSEL_MFCLK_OFS             (2U)
#define GPTIMER_CLKSEL_BUSCLK_OFS            (3U)

// RSTCTL Macros

#define GPTIMER_RSTCTL_KEY_UNLOCK_W          (0xB1000000U)
#define GPTIMER_RSTCTL_RESETASSERT           (1U)

// CCPD Macros
#define GPTIMER_CCPD_C0CCP0_OFS              (0U)
#define GPTIMER_CCPD_C0CCP1_OFS              (1U)
#define GPTIMER_CCPD_C0CCP2_OFS              (2U)

// ODIS Macros
#define GPTIMER_ODIS_C0CCP0_OFS              (0U)
#define GPTIMER_ODIS_C0CCP1_OFS              (1U)
#define GPTIMER_ODIS_C0CCP2_OFS              (2U)
#define GPTIMER_ODIS_C0CCP3_OFS              (3U)

// CTRCTL Macros
#define GPTIMER_CTRCTL_EN_OFS                (0U)
#define GPTIMER_CTRCTL_REPEAT_OFS            (1U)
#define GPTIMER_CTRCTL_CM_OFS                (4U)
#define GPTIMER_CTRCTL_CLC_OFS               (7U)
#define GPTIMER_CTRCTL_CAC_OFS               (10U)
#define GPTIMER_CTRCTL_CZC_OFS               (13U)
#define GPTIMER_CTRCTL_DRB_OFS               (17U)
#define GPTIMER_CTRCTL_FB_OFS                (18U)
#define GPTIMER_CTRCTL_FRB_OFS               (19U)
#define GPTIMER_CTRCTL_SLZERCNEZ_OFS         (23U)
#define GPTIMER_CTRCTL_PLEN_OFS              (24U)
#define GPTIMER_CTRCTL_CVAE_OFS              (28U)

#define GPTIMER_CTRCTL_REPEAT_WIDTH          (3U)
#define GPTIMER_CTRCTL_CM_WIDTH              (2U)
#define GPTIMER_CTRCTL_CLC_WIDTH             (3U)
#define GPTIMER_CTRCTL_CAC_WIDTH             (3U)
#define GPTIMER_CTRCTL_CZC_WIDTH             (3U)
#define GPTIMER_CTRCTL_CVAE_WIDTH            (2U)

// LOAD Macros
#define GPTIMER_LOAD_LD_OFS                  (0U)
#define GPTIMER_LOAD_LD_WIDTH                (16U)

// CC_01 Macros
#define GPTIMER_CC01_CCVAL_OFS               (0U)
#define GPTIMER_CC01_CCVAL_WIDTH             (16U)

// CCCTL_01 Macros
#define GPTIMER_CCCTL01_COC_OFS              (17U)

// OCTL_01 Macros
#define GPTIMER_OCTL01_CCPO_OFS              (0U)
#define GPTIMER_OCTL01_CCPO_WIDTH            (4U)
#define GPTIMER_OCTL01_CCPOINV_OFS           (4U)
#define GPTIMER_OCTL01_CCPIV_OFS             (5U)

// CCACT_01 Macros
#define GPTIMER_CCACT01_ZACT_OFS             (0U)
#define GPTIMER_CCACT01_ZACT_WIDTH           (2U)
#define GPTIMER_CCACT01_CUACT_OFS            (9U)
#define GPTIMER_CCACT01_CUACT_WIDTH          (2U)



#endif // MSPM0L1306_GPTIMER_H