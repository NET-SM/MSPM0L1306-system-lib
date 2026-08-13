#ifndef MSPM0L1306_IOMUX_H
#define MSPM0L1306_IOMUX_H

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


/* IOMUX Pin Definitions */

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
 

#define IOMUX_PINCM_PF_OFS                            (0U)
#define IOMUX_PINCM_PF_MASK                           (0x0000003FU)
#define IOMUX_PINCM_PC_OFS                            (7U)
#define IOMUX_PINCM_PC_CONNECTED                      (0x00000080U) 
#define IOMUX_PINCM_PIPID_OFS                         (16U)
#define IOMUX_PINCM_PIPU_OFS                          (17U)
#define IOMUX_PINCM_INENA_OFS                         (18U)


/* IOMUX_PINCM1[PF] Bits */
#define IOMUX_PINCM1_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM1_PF_GPIOA_DIO00                   (0x00000001U)
#define IOMUX_PINCM1_PF_UART1_TX                      (0x00000002U)
#define IOMUX_PINCM1_PF_I2C0_SDA                      (0x00000003U)
#define IOMUX_PINCM1_PF_TIMG1_CCP0                    (0x00000004U)
#define IOMUX_PINCM1_PF_SPI0_CS1_POCI1                (0x00000005U)
#define IOMUX_PINCM1_PF_SYSCTL_FCC_IN                 (0x00000006U)

/* IOMUX_PINCM2[PF] Bits */
#define IOMUX_PINCM2_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM2_PF_GPIOA_DIO01                   (0x00000001U)
#define IOMUX_PINCM2_PF_UART1_RX                      (0x00000002U)
#define IOMUX_PINCM2_PF_I2C0_SCL                      (0x00000003U)
#define IOMUX_PINCM2_PF_TIMG1_CCP1                    (0x00000004U)

/* IOMUX_PINCM3[PF] Bits */
#define IOMUX_PINCM3_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM3_PF_GPIOA_DIO02                   (0x00000001U)
#define IOMUX_PINCM3_PF_TIMG1_CCP1                    (0x00000002U)
#define IOMUX_PINCM3_PF_SPI0_CS0                      (0x00000003U)

/* IOMUX_PINCM4[PF] Bits */
#define IOMUX_PINCM4_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM4_PF_GPIOA_DIO03                   (0x00000001U)
#define IOMUX_PINCM4_PF_TIMG2_CCP0                    (0x00000002U)
#define IOMUX_PINCM4_PF_SPI0_CS1_POCI1                (0x00000003U)
#define IOMUX_PINCM4_PF_UART1_CTS                     (0x00000004U)
#define IOMUX_PINCM4_PF_COMP0_OUT                     (0x00000005U)
#define IOMUX_PINCM4_PF_I2C1_SDA                      (0x00000006U)

/* IOMUX_PINCM5[PF] Bits */
#define IOMUX_PINCM5_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM5_PF_GPIOA_DIO04                   (0x00000001U)
#define IOMUX_PINCM5_PF_TIMG2_CCP1                    (0x00000002U)
#define IOMUX_PINCM5_PF_SPI0_POCI                     (0x00000003U)
#define IOMUX_PINCM5_PF_UART1_RTS                     (0x00000004U)
#define IOMUX_PINCM5_PF_I2C1_SCL                      (0x00000005U)

/* IOMUX_PINCM6[PF] Bits */
#define IOMUX_PINCM6_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM6_PF_GPIOA_DIO05                   (0x00000001U)
#define IOMUX_PINCM6_PF_TIMG0_CCP0                    (0x00000002U)
#define IOMUX_PINCM6_PF_SPI0_PICO                     (0x00000003U)
#define IOMUX_PINCM6_PF_SYSCTL_FCC_IN                 (0x00000004U)

/* IOMUX_PINCM7[PF] Bits */
#define IOMUX_PINCM7_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM7_PF_GPIOA_DIO06                   (0x00000001U)
#define IOMUX_PINCM7_PF_TIMG0_CCP1                    (0x00000002U)
#define IOMUX_PINCM7_PF_SPI0_SCLK                     (0x00000003U)

/* IOMUX_PINCM8[PF] Bits */
#define IOMUX_PINCM8_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM8_PF_GPIOA_DIO07                   (0x00000001U)
#define IOMUX_PINCM8_PF_COMP0_OUT                     (0x00000002U)
#define IOMUX_PINCM8_PF_SYSCTL_CLK_OUT                (0x00000003U)
#define IOMUX_PINCM8_PF_TIMG1_CCP0                    (0x00000004U)

/* IOMUX_PINCM9[PF] Bits */
#define IOMUX_PINCM9_PF_UNCONNECTED                   (0x00000000U)
#define IOMUX_PINCM9_PF_GPIOA_DIO08                   (0x00000001U)
#define IOMUX_PINCM9_PF_UART0_TX                      (0x00000002U)
#define IOMUX_PINCM9_PF_SPI0_CS0                      (0x00000003U)
#define IOMUX_PINCM9_PF_UART1_RTS                     (0x00000004U)
#define IOMUX_PINCM9_PF_TIMG2_CCP0                    (0x00000005U)

/* IOMUX_PINCM10[PF] Bits */
#define IOMUX_PINCM10_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM10_PF_GPIOA_DIO09                  (0x00000001U)
#define IOMUX_PINCM10_PF_UART0_RX                     (0x00000002U)
#define IOMUX_PINCM10_PF_SPI0_PICO                    (0x00000003U)
#define IOMUX_PINCM10_PF_UART1_CTS                    (0x00000004U)
#define IOMUX_PINCM10_PF_TIMG2_CCP1                   (0x00000005U)
#define IOMUX_PINCM10_PF_SYSCTL_CLK_OUT               (0x00000006U)

/* IOMUX_PINCM11[PF] Bits */
#define IOMUX_PINCM11_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM11_PF_GPIOA_DIO10                  (0x00000001U)
#define IOMUX_PINCM11_PF_UART1_TX                     (0x00000002U)
#define IOMUX_PINCM11_PF_SPI0_POCI                    (0x00000003U)
#define IOMUX_PINCM11_PF_I2C0_SDA                     (0x00000004U)
#define IOMUX_PINCM11_PF_TIMG4_CCP0                   (0x00000005U)
#define IOMUX_PINCM11_PF_SYSCTL_CLK_OUT               (0x00000006U)

/* IOMUX_PINCM12[PF] Bits */
#define IOMUX_PINCM12_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM12_PF_GPIOA_DIO11                  (0x00000001U)
#define IOMUX_PINCM12_PF_UART1_RX                     (0x00000002U)
#define IOMUX_PINCM12_PF_SPI0_SCLK                    (0x00000003U)
#define IOMUX_PINCM12_PF_I2C0_SCL                     (0x00000004U)
#define IOMUX_PINCM12_PF_TIMG4_CCP1                   (0x00000005U)
#define IOMUX_PINCM12_PF_COMP0_OUT                    (0x00000006U)

/* IOMUX_PINCM13[PF] Bits */
#define IOMUX_PINCM13_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM13_PF_GPIOA_DIO12                  (0x00000001U)
#define IOMUX_PINCM13_PF_UART0_CTS                    (0x00000002U)
#define IOMUX_PINCM13_PF_TIMG0_CCP0                   (0x00000003U)
#define IOMUX_PINCM13_PF_SYSCTL_FCC_IN                (0x00000004U)

/* IOMUX_PINCM14[PF] Bits */
#define IOMUX_PINCM14_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM14_PF_GPIOA_DIO13                  (0x00000001U)
#define IOMUX_PINCM14_PF_UART0_RTS                    (0x00000002U)
#define IOMUX_PINCM14_PF_TIMG0_CCP1                   (0x00000003U)
#define IOMUX_PINCM14_PF_UART1_RX                     (0x00000004U)

/* IOMUX_PINCM15[PF] Bits */
#define IOMUX_PINCM15_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM15_PF_GPIOA_DIO14                  (0x00000001U)
#define IOMUX_PINCM15_PF_UART1_CTS                    (0x00000002U)
#define IOMUX_PINCM15_PF_SYSCTL_CLK_OUT               (0x00000003U)
#define IOMUX_PINCM15_PF_UART1_TX                     (0x00000004U)
#define IOMUX_PINCM15_PF_TIMG1_CCP0                   (0x00000005U)

/* IOMUX_PINCM16[PF] Bits */
#define IOMUX_PINCM16_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM16_PF_GPIOA_DIO15                  (0x00000001U)
#define IOMUX_PINCM16_PF_UART1_RTS                    (0x00000002U)
#define IOMUX_PINCM16_PF_I2C1_SCL                     (0x00000003U)
#define IOMUX_PINCM16_PF_SPI0_CS2_POCI2               (0x00000004U)
#define IOMUX_PINCM16_PF_TIMG4_CCP1                   (0x00000005U)

/* IOMUX_PINCM17[PF] Bits */
#define IOMUX_PINCM17_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM17_PF_GPIOA_DIO16                  (0x00000001U)
#define IOMUX_PINCM17_PF_COMP0_OUT                    (0x00000002U)
#define IOMUX_PINCM17_PF_I2C1_SDA                     (0x00000003U)
#define IOMUX_PINCM17_PF_SPI0_POCI                    (0x00000004U)
#define IOMUX_PINCM17_PF_TIMG0_CCP0                   (0x00000005U)
#define IOMUX_PINCM17_PF_SYSCTL_FCC_IN                (0x00000006U)

/* IOMUX_PINCM18[PF] Bits */
#define IOMUX_PINCM18_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM18_PF_GPIOA_DIO17                  (0x00000001U)
#define IOMUX_PINCM18_PF_UART0_TX                     (0x00000002U)
#define IOMUX_PINCM18_PF_I2C1_SCL                     (0x00000003U)
#define IOMUX_PINCM18_PF_SPI0_SCLK                    (0x00000004U)
#define IOMUX_PINCM18_PF_TIMG4_CCP0                   (0x00000005U)
#define IOMUX_PINCM18_PF_SPI0_CS1_POCI1               (0x00000006U)

/* IOMUX_PINCM19[PF] Bits */
#define IOMUX_PINCM19_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM19_PF_GPIOA_DIO18                  (0x00000001U)
#define IOMUX_PINCM19_PF_UART0_RX                     (0x00000002U)
#define IOMUX_PINCM19_PF_SPI0_PICO                    (0x00000003U)
#define IOMUX_PINCM19_PF_I2C1_SDA                     (0x00000004U)
#define IOMUX_PINCM19_PF_TIMG4_CCP1                   (0x00000005U)

/* IOMUX_PINCM20[PF] Bits */
#define IOMUX_PINCM20_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM20_PF_GPIOA_DIO19                  (0x00000001U)
#define IOMUX_PINCM20_PF_DEBUGSS_SWDIO                (0x00000002U)
#define IOMUX_PINCM20_PF_I2C1_SDA                     (0x00000003U)
#define IOMUX_PINCM20_PF_SPI0_POCI                    (0x00000004U)

/* IOMUX_PINCM21[PF] Bits */
#define IOMUX_PINCM21_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM21_PF_GPIOA_DIO20                  (0x00000001U)
#define IOMUX_PINCM21_PF_DEBUGSS_SWCLK                (0x00000002U)
#define IOMUX_PINCM21_PF_I2C1_SCL                     (0x00000003U)
#define IOMUX_PINCM21_PF_TIMG4_CCP0                   (0x00000004U)

/* IOMUX_PINCM22[PF] Bits */
#define IOMUX_PINCM22_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM22_PF_GPIOA_DIO21                  (0x00000001U)
#define IOMUX_PINCM22_PF_TIMG2_CCP0                   (0x00000002U)
#define IOMUX_PINCM22_PF_UART0_CTS                    (0x00000003U)
#define IOMUX_PINCM22_PF_UART0_TX                     (0x00000004U)

/* IOMUX_PINCM23[PF] Bits */
#define IOMUX_PINCM23_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM23_PF_GPIOA_DIO22                  (0x00000001U)
#define IOMUX_PINCM23_PF_UART0_RX                     (0x00000002U)
#define IOMUX_PINCM23_PF_TIMG2_CCP1                   (0x00000003U)
#define IOMUX_PINCM23_PF_UART0_RTS                    (0x00000004U)
#define IOMUX_PINCM23_PF_SYSCTL_CLK_OUT               (0x00000005U)
#define IOMUX_PINCM23_PF_UART1_RX                     (0x00000006U)

/* IOMUX_PINCM24[PF] Bits */
#define IOMUX_PINCM24_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM24_PF_GPIOA_DIO23                  (0x00000001U)
#define IOMUX_PINCM24_PF_UART0_TX                     (0x00000002U)
#define IOMUX_PINCM24_PF_SPI0_CS3_CD_POCI3            (0x00000003U)
#define IOMUX_PINCM24_PF_TIMG0_CCP0                   (0x00000004U)
#define IOMUX_PINCM24_PF_UART0_CTS                    (0x00000005U)
#define IOMUX_PINCM24_PF_UART1_TX                     (0x00000006U)

/* IOMUX_PINCM25[PF] Bits */
#define IOMUX_PINCM25_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM25_PF_GPIOA_DIO24                  (0x00000001U)
#define IOMUX_PINCM25_PF_SPI0_CS2_POCI2               (0x00000002U)
#define IOMUX_PINCM25_PF_TIMG0_CCP1                   (0x00000003U)
#define IOMUX_PINCM25_PF_UART0_RTS                    (0x00000004U)

/* IOMUX_PINCM26[PF] Bits */
#define IOMUX_PINCM26_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM26_PF_GPIOA_DIO25                  (0x00000001U)
#define IOMUX_PINCM26_PF_TIMG4_CCP1                   (0x00000002U)
#define IOMUX_PINCM26_PF_UART0_TX                     (0x00000003U)
#define IOMUX_PINCM26_PF_SPI0_PICO                    (0x00000004U)

/* IOMUX_PINCM27[PF] Bits */
#define IOMUX_PINCM27_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM27_PF_GPIOA_DIO26                  (0x00000001U)
#define IOMUX_PINCM27_PF_TIMG1_CCP0                   (0x00000002U)
#define IOMUX_PINCM27_PF_UART0_RX                     (0x00000003U)
#define IOMUX_PINCM27_PF_SPI0_POCI                    (0x00000004U)

/* IOMUX_PINCM28[PF] Bits */
#define IOMUX_PINCM28_PF_UNCONNECTED                  (0x00000000U)
#define IOMUX_PINCM28_PF_GPIOA_DIO27                  (0x00000001U)
#define IOMUX_PINCM28_PF_TIMG1_CCP1                   (0x00000002U)
#define IOMUX_PINCM28_PF_SPI0_CS3_CD_POCI3            (0x00000003U)

// Prototip generičke funkcije
void iomux_configure_pin(uint32_t pincm, uint32_t pf, uint32_t input_enable);

#endif // MSPM0L1306_IOMUX_H