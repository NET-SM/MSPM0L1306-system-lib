#ifndef MSPM0L1306_ADC12_H
#define MSPM0L1306_ADC12_H

#include "mspm0l1306_base.h"

// ============================================================================
// ADC0 base (0x40004000U)
// ============================================================================

typedef struct {

         uint32_t RESERVED0[88];
    __I  uint32_t FIFODATA;              // (@ 0x00000160) FIFO Data Register
         uint32_t RESERVED1[71];
    __I  uint32_t MEMRES[24];            // (@ 0x00000280) Memory Result Register  

} ADC12_SVTMEM_Regs;

typedef struct {

    ADC12_SVTMEM_Regs SVTMEM;            // (@ 0x00000000) 

} ADC12_PERIPHERALREGIONSVT_Regs;


typedef struct {
    
    __I  uint32_t IIDX;                  // (@ 0x00001080) Interrupt index
         uint32_t RESERVED0; 
    __IO uint32_t IMASK;                 // (@ 0x00001088) Interrupt mask extenstion
         uint32_t RESERVED1; 
    __I  uint32_t RIS;                   // (@ 0x00001090) Raw interrupt status extension
         uint32_t RESERVED2; 
    __I  uint32_t MIS;                   // (@ 0x00001098) Masked interrupt status extension
         uint32_t RESERVED3; 
    __O  uint32_t ISET;                  // (@ 0x000010A0) Interrupt set extension
         uint32_t RESERVED4; 
    __O  uint32_t ICLR;                  // (@ 0x000010A8) Interrupt clear exntension

} ADC12_DMA_TRIG_Regs;


typedef struct {
    
    __I  uint32_t IIDX;                  // (@ 0x00001050) Interrupt Index
         uint32_t RESERVED0; 
    __IO uint32_t IMASK;                 // (@ 0x00001058) Interrupt mask extension
         uint32_t RESERVED1;             
    __I  uint32_t RIS;                   // (@ 0x00001060) Raw interrupt status extension
         uint32_t RESERVED2; 
    __I  uint32_t MIS;                   // (@ 0x00001068) Masked interrupt status extension
         uint32_t RESERVED3; 
    __O  uint32_t ISET;                  // (@ 0x00001070) Interrupt set extension
         uint32_t RESERVED4; 
    __O  uint32_t ICLR;                  // (@ 0x00001078) Interrupt clear extension

} ADC12_GEN_EVENT_Regs;

typedef struct {
    
    __I  uint32_t IIDX;                  // (@ 0x00001020) Interrupt Index
         uint32_t RESERVED0; 
    __IO uint32_t IMASK;                 // (@ 0x00001028) Interrupt mask extension
         uint32_t RESERVED1;             
    __I  uint32_t RIS;                   // (@ 0x00001030) Raw interrupt status extension
         uint32_t RESERVED2; 
    __I  uint32_t MIS;                   // (@ 0x00001038) Masked interrupt status extension
         uint32_t RESERVED3; 
    __O  uint32_t ISET;                  // (@ 0x00001040) Interrupt set extension
         uint32_t RESERVED4; 
    __O  uint32_t ICLR;                  // (@ 0x00001048) Interrupt clear extension

} ADC12_CPU_INT_Regs;

typedef struct {
    
    __IO uint32_t PWREN;                // (@ 0x00000800) Power enable
    __O  uint32_t RSTCTL;               // (@ 0x00000804) Reset control
    __IO uint32_t CLKCFG;               // (@ 0x00000808) ADC Clock configuration register
         uint32_t RESERVED0[2]; 
    __I  uint32_t STAT;                 // (@ 0x00000814) Status Register

} ADC12_GPRCM_Regs;


typedef struct {

         uint32_t RESERVED0[256];      
    __IO uint32_t FSUB_0;               // (@ 0x00000400)  Subscriber Configuration Register
         uint32_t RESERVED1[16];     
    __IO uint32_t FPUB_1;               // (@ 0x00000444)  Publisher Configuration Register
         uint32_t RESERVED2[238]; 
    ADC12_GPRCM_Regs GPRCM;             // (@ 0x00000800)
         uint32_t RESERVED3[514]; 
    ADC12_CPU_INT_Regs CPU_INT;         // (@ 0x00001020)
         uint32_t RESERVED4; 
    ADC12_GEN_EVENT_Regs GEN_EVENT;     // (@ 0x00001050)
         uint32_t RESERVED5;  
    ADC12_DMA_TRIG_Regs DMA_TRIG;       // (@ 0x00001080)
         uint32_t RESERVED6[13]; 
    __I  uint32_t EVT_MODE;             // (@ 0x000010E0) Event mode
         uint32_t RESERVED7[6]; 
    __I  uint32_t DESC;                 // (@ 0x000010FC) Module description
    __IO uint32_t CTL0;                 // (@ 0x00001100) Control register 0
    __IO uint32_t CTL1;                 // (@ 0x00001104) Control register 1
    __IO uint32_t CTL2;                 // (@ 0x00001108) Control register 2
         uint32_t RESERVED8; 
    __IO uint32_t CLKFREQ;              // (@ 0x00001110) Sample clock frequency range register
    __IO uint32_t SCOMP0;               // (@ 0x00001114) Sample time compare 0 register
    __IO uint32_t SCOMP1;               // (@ 0x00001118) Sample time compare 1 register
         uint32_t RESERVED9[11]; 
    __IO uint32_t WCLOW;                // (@ 0x00001148) Window comparator low threshold register
         uint32_t RESERVED10; 
    __IO uint32_t WCHIGH;               // (@ 0x00001150) Window comparator high threshold register
         uint32_t RESERVED11[3]; 
    __I  uint32_t FIFODATA;             // (@ 0x00001160) FIFO data register
         uint32_t RESERVED12[7]; 
    __IO uint32_t MEMCTL[24];           // (@ 0x00001180) Conversion memory control register
         uint32_t RESERVED13[40]; 
    __I  uint32_t MEMRES[24];           // (@ 0x00001280) Memory result register
         uint32_t RESERVED14[24]; 
    __I  uint32_t STATUS;               // (@ 0x00001340) Status register

} ADC12_ULLEM_Regs;

typedef struct{
    
    ADC12_ULLEM_Regs ULLEM;

} ADC12_Regs;

#define ADC12 ((ADC12_Regs *) ADC0_BASE) 

// CLKCFG Enums

typedef enum {
    ADC_ULPCLK = 0,
    ADC_SYSOSC = 1,
    ADC_HFCLK  = 2,
} adc_clksrc_t;

// CTL0 Enums

typedef enum{
     ADC_SCKLDIV_NO_DIV  = 0U,
     ADC_SCKLDIV_2_DIV   = 1U,
     ADC_SCKLDIV_4_DIV   = 2U,
     ADC_SCKLDIV_8_DIV   = 3U,
     ADC_SCKLDIV_16_DIV  = 4U,
     ADC_SCKLDIV_24_DIV  = 5U,
     ADC_SCKLDIV_32_DIV  = 6U,
     ADC_SCKLDIV_48_DIV  = 7U,
} adc_sclkdiv_sel_t;

// CLT1 Enums

typedef enum{
     ADC_AUTO   = 0U,
     ADC_MANUAL = 1U,
}adc_samp_mode_sel_t;

typedef enum{
     ADC_SINGLE          = 0U,
     ADC_SEQUENCE        = 1U,
     ADC_REPEATSINGLE    = 2U,
     ADC__REPEATSEQUENCE = 3U,
}adc_repeat_mode_t;

typedef enum{
     ADC_SW_TRIGGER  = 0U,
     ADC_HWE_TRIGGER = 1U,
}adc_trig_sel_t;

// CTL2 Enums

typedef enum{
     ADC_12BIT = 0,
     ADC_10BIT = 1,
     ADC_8BIT  = 2,
}adc_res_t;

// CLKFREQ Enums

typedef enum{
     ADC_FRANGE_1_4MHZ =   0U,
     ADC_FRANGE_4_8MHZ =   1U,
     ADC_FRANGE_8_16MHZ =  2U,
     ADC_FRANGE_16_20MHZ = 3U,
     ADC_FRANGE_20_24MHZ = 4U,
     ADC_FRANGE_24_32MHZ = 5U,
     // ADC_FRANGE_32_40MHZ = 6U, // MSPML1306 not compatible
     // ADC_FRANGE_40_48MHZ = 7U, // MSPML1306 not compatible
} adc_frange_sel_t;

// MEMCTLx Enums

typedef enum{
     ADC_CHANNEL_PA25 = 2U, // ADC0.2
     ADC_CHANNEL_PA21 = 5U, // ADC0.5
     ADC_CHANNEL_PA18 = 7U, // ADC0.7
     ADC_CHANNEL_PA16 = 8U, // ADC0.8
     ADC_CHANNEL_PA15 = 9U, // ADC0.9
}adc_channel_t;

typedef enum{
     ADC_VREF_VDDA_VSSA    = 0U,        // VDDA Reference
     ADC_VREF_EXTREF_VREFM = 1U,        // External reference from pin      
     ADC_VREF_INTREF_VSSA  = 2U,        // Internal reference
     ADC_VREF_VDDA_VREFM   = 3U,        // VDDA and VREFM connected to  VREF+ and VREF- of ADC
     ADC_VREF_INTERF_VREFM = 4U,        // INTREF and VREFM connected to VREF+ and VREF- of ADC
} adc_vref_t;

typedef enum{
     ADC_STIME_SCOMP0 = 0U,
     ADC_STIME_SCOMP1 = 1U,
} adc_stime_sel_t;


// CLKCFG Macros
#define ADC_CLKCFG_KEY_UNLOCK_W       (0xA9000000U)

#define ADC_CLKCFG_SAMPCLK_ULPCLK     (0x00000000U)
#define ADC_CLKCFG_SAMPCLK_SYSOSC     (0x00000001U)
#define ADC_CLKCFG_SAMPCLK_HFCLK      (0x00000002U)

// CTL0 Macros
#define ADC_CTL0_SCLKDIV_OFS          (24U)
#define ADC_CTL0_SCLKDIV_WIDTH        (3U)
#define ADC_CTL0_ENC_OFS              (0U)

// CTL1 Macros

#define ADC_CTL1_SAMPMODE_OFS         (20U)
#define ADC_CTL1_CONSEQ_OFS           (16U)
#define ADC_CTL1_SC_OFS               (8U)
#define ADC_CTL1_CONSEQ_WIDTH         (2U)
#define ADC_CTL1_TRIGSRC_OFS          (0U)




// CTL2 Macros
#define ADC_CTL2_ENDADD_OFS           (24U)
#define ADC_CTL2_ENDADD_WIDTH         (5U)
#define ADC_CTL2_STARTADD_OFS         (16U)
#define ADC_CTL2_STARTADD_WIDTH       (5U)

#define ADC_CTL2_RES_OFS              (1U)
#define ADC_CTL2_RES_WIDTH            (2U)

// CLKFREQ
#define ADC_CLKFREQ_FRANGE_OFS        (0U)
#define ADC_CLKFREQ_FRANGE_WIDTH      (3U)

// SCOMP0 Macros

#define ADC_SCOMP0_VAL_OFS            (0U)
#define ADC_SCOMP0_VAL_WIDTH          (10U)

// SCOMP1 Macros

#define ADC_SCOMP1_VAL_OFS            (0U)
#define ADC_SCOMP1_VAL_WIDTH          (10U)


// MEMCTLy Macros

#define ADC_MEMCTL_CHANSEL_OFS        (0U)
#define ADC_MEMCTL_CHANSEL_WIDTH      (5U)

#define ADC_MEMCTL_VRSEL_OFS          (8U)
#define ADC_MEMCTL_VRSEL_WIDTH        (3U)

#define ADC_MEMCTL_STIME_OFS          (12U)
#define ADC_MEMCTL_TRIG_OFS           (24U)
// MEMRES Macros

#define ADC_MEMRES_RESULT_OFS         (0U)
#define ADC_MEMRES_RESULT_WIDTH       (12U)

// STATUS Macros

#define ADC_STATUS_BUSY_OFS           (0U)

void adc_enable_power(void);
void adc_disable_power(void);
void adc_init(adc_clksrc_t clk_source, adc_res_t resolution, adc_sclkdiv_sel_t sclkdiv, adc_frange_sel_t frange);
void adc_select_conversion_mode(adc_repeat_mode_t repeat_mode);
void adc_config_seq_addresses(adc_repeat_mode_t repeat_mode, uint32_t start_add, uint32_t end_add);
void adc_config_channel(uint32_t mem_idx, adc_channel_t channel);
void adc_set_channel_vref(uint32_t mem_idx, adc_vref_t vref);
void adc_trigger_select(adc_trig_sel_t trigger_select);
void adc_mode_select(adc_samp_mode_sel_t mode);
void adc_set_sample_time(adc_stime_sel_t scomp, uint32_t val);
void adc_set_channel_stime_source(uint32_t mem_idx, adc_stime_sel_t scomp);
void adc_set_channel_trig_policy(uint32_t mem_idx, uint32_t trig_needed);
void adc_enable_conversion(void);
void adc_disable_conversion(void);
void adc_software_auto_start(void);
uint32_t adc_is_busy(void); 
uint32_t adc_read_result(uint32_t mem_idx);


#endif // MSPM0L1306_ADC12_H