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


 
// ============================================================================
// PINCM zajednička bit polja (važe za sve PINCMn registre)
// ============================================================================
 
#define IOMUX_PINCM_PF_OFS                  (0)
#define IOMUX_PINCM_PF_MASK                 ((uint32_t)0x0000003FU)
#define IOMUX_PINCM_PC_CONNECTED            (0x00000080U)  // bit 7 = "Peripheral Connected"

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