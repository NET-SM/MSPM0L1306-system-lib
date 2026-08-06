#ifndef MSPM0L1306_GPIO_H

#include "mspm0l1306_base.h"

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

#define GPIOA  ((GPIO_Regs *) GPIOA_BASE)

#endif // MSPM0L1306_GPIO_H
