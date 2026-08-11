#ifndef MSPM0L1306_IOMUX_H

#include "mspm0l1306_base.h"

// ============================================================================
// IOMUX (0x40428000U)
// ============================================================================

typedef struct {
       uint32_t RESERVED0;
  __IO uint32_t PINCM[251];                        /* !< (@ 0x00000004) Pin Control Management Register in SECCFG region */
} IOMUX_SECCFG_Regs;

typedef struct {
  IOMUX_SECCFG_Regs  SECCFG;                       /* !< (@ 0x00000000) SECCFG register region */
} IOMUX_Regs;

#define IOMUX ((IOMUX_Regs *) IOMUX_BASE)

typedef enum IOMUX_PINCM
{
  IOMUX_PINCM1         = (0),
  IOMUX_PINCM2         = (1),
  IOMUX_PINCM3         = (2),
  IOMUX_PINCM4         = (3),
  IOMUX_PINCM5         = (4),
  IOMUX_PINCM6         = (5),
  IOMUX_PINCM7         = (6),
  IOMUX_PINCM8         = (7),
  IOMUX_PINCM9         = (8),
  IOMUX_PINCM10        = (9),
  IOMUX_PINCM11        = (10),
  IOMUX_PINCM12        = (11),
  IOMUX_PINCM13        = (12),
  IOMUX_PINCM14        = (13),
  IOMUX_PINCM15        = (14),
  IOMUX_PINCM16        = (15),
  IOMUX_PINCM17        = (16),
  IOMUX_PINCM18        = (17),
  IOMUX_PINCM19        = (18),
  IOMUX_PINCM20        = (19),
  IOMUX_PINCM21        = (20),
  IOMUX_PINCM22        = (21),
  IOMUX_PINCM23        = (22),
  IOMUX_PINCM24        = (23),
  IOMUX_PINCM25        = (24),
  IOMUX_PINCM26        = (25),
  IOMUX_PINCM27        = (26),
  IOMUX_PINCM28        = (27),
} IOMUX_PINCM;
 
// ============================================================================
// PINCM zajednička bit polja (važe za sve PINCMn registre)
// ============================================================================
 
#define IOMUX_PINCM_PF_OFS                  (0)
#define IOMUX_PINCM_PF_MASK                 ((uint32_t)0x0000003FU)
#define IOMUX_PINCM_PC_CONNECTED            (0x00000080U)  // bit 7 = "Peripheral Connected"

// ============================================================================
// PINCM8 -> PA7 (indeks u PINCM[] nizu je 7, 0-indeksirano!)
// ============================================================================

/* IOMUX_PINCM8[PF] Bits */
#define IOMUX_PINCM8_PF_UNCONNECTED                   ((uint32_t)0X00000000)
#define IOMUX_PINCM8_PF_GPIOA_DIO07                   ((uint32_t)0X00000001)
#define IOMUX_PINCM8_PF_COMP0_OUT                     ((uint32_t)0X00000002)
#define IOMUX_PINCM8_PF_SYSCTL_CLK_OUT                ((uint32_t)0X00000003)
#define IOMUX_PINCM8_PF_TIMG1_CCP0                    ((uint32_t)0X00000004)


// ============================================================================
// PINCM27 -> PA26 (indeks u PINCM[] nizu je 26, 0-indeksirano!)
// ============================================================================

/* IOMUX_PINCM27[PF] Bits */
#define IOMUX_PINCM27_PF_UNCONNECTED                  ((uint32_t)0X00000000)
#define IOMUX_PINCM27_PF_GPIOA_DIO26                  ((uint32_t)0X00000001)
#define IOMUX_PINCM27_PF_TIMG1_CCP0                   ((uint32_t)0X00000002)
#define IOMUX_PINCM27_PF_UART0_RX                     ((uint32_t)0X00000003)
#define IOMUX_PINCM27_PF_SPI0_POCI                    ((uint32_t)0X00000004)


#endif // MSPM0L1306_IOMUX_H