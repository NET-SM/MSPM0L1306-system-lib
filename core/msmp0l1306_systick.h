#ifndef MSMP0L1306_SYSTICK_H
#define MSPM0L1306_SYSTICK_H

#include <stdint.h>
#include "mspm0_reg_utils.h"

extern uint32_t SystemCoreClock;

#define __I   volatile const   // Defines 'read only'  permission
#define __O   volatile         // Defines 'write only'  permission
#define __IO  volatile         // Defines 'read / write only'  permission
#define __IM  volatile const   // Defines 'read only' structure member  permission
#define __OM  volatile         // Defines 'write only'  structure member permission
#define __IOM volatile         // Defines 'read / write only'  structure member permission

// Structure Type to acces System Timer (SysTick)

typedef struct
{
    __IOM uint32_t CTRL;  // Offset 0x000 (R/W) SysTick Control and Status Register
    __IOM uint32_t LOAD;  // Offset 0x004 (R/W) SysTick Reload Value Register
    __IOM uint32_t VAL;   // Offset 0x008 (R/W) SysTick Current Value Register
    __IM  uint32_t CALIB; // Offset 0x00C (R/ ) SysTick Calibration Register

}SysTick_Type;

// SysTick Control / Status Register Definitions

#define SysTick_CTRL_COUNTFLAG_Pos   16U                                           // SysTick CTRL: COUNTERFLAG Position 
#define SysTick_CTRL_COUNTFLAG_Msk  (1UL << SysTick_CTRL_COUNTFLAG_Pos)            // SysTick CTRL: COUNTERFLAG Mask

#define SysTick_CTRL_CLKSOURCE_Pos   2U                                            // SysTick CTRL: CLOCKSOURCE Position 
#define SysTick_CTRL_CLKSOURCE_Msk  (1UL << SysTick_CTRL_CLKSOURCE_Pos)            // SysTick CTRL: CLOCKSOURCE Mask 

#define SysTick_CTRL_TICKINT_Pos     1U                                            // SysTick CTRL: TICKINT Position
#define SysTick_CTRL_TICKINT_Msk    (1UL << SysTick_CTRL_TICKINT_Pos)              // SysTick CTRL: TICKINT Mask

#define SysTick_CTRL_ENABLE_Pos      0U                                            // SysTick CTRL: ENABLE Position
#define SysTick_CTRL_ENABLE_Msk     (1UL << SysTick_CTRL_ENABLE_Pos)               // SysTick CTRL: ENABLE Mask

// SysTick Reload Register Definitions 

#define SysTick_LOAD_RELOAD_Pos      0U                                            // SysTick LOAD: RELOAD Position
#define SysTick_LOAD_RELOAD_Msk     (0xFFFFFFUL  /*<< SysTick_LOAD_RELOAD_Pos*/)   // SysTick CTRL: RELOAD Mask

// SysTick Current Register Definitions

#define SysTick_VAL_CURRENT_Pos      0U                                            // SysTick VAL: CURRENT Position 
#define SysTick_VAL_CURRENT_Msk     (0xFFFFFFUL /*<< SysTick_VAL_CURRENT_Pos*/)    // SysTick VAL: CURRENT Mask 

// SysTick Calibration Register Definitions

#define SysTick_CALIB_NOREF_Pos      31U                                           // SysTick CALIB: NOREF Position
#define SysTick_CALIB_NOREF_Msk     (1UL << SysTick_CALIB_NOREF_Pos)               // SysTick CALIB: NOREF Mask

#define SysTick_CALIB_SKEW_Pos       30U                                           // SysTick CALIB: SKEW Position 
#define SysTick_CALIB_SKEW_Msk      (1UL << SysTick_CALIB_SKEW_Pos)                // SysTick CALIB: SKEW Mask 

#define SysTick_CALIB_TENMS_Pos      0U                                            // SysTick CALIB: TENMS Position 
#define SysTick_CALIB_TENMS_Msk     (0xFFFFFFUL /*<< SysTick_CALIB_TENMS_Pos*/)    // SysTick CALIB: TENMS Mask 


// Memory mapping of core hardware
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */

//#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct */
#define SysTick               ((SysTick_Type   *)     SysTick_BASE  )   /*!< SysTick configuration struct */
//#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */



// SysTick function

static inline uint32_t SysTick_Config(uint32_t ticks){
    
    if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
    {
        return (1UL);  // Reload value impossible
    }
    
    SysTick->LOAD = (uint32_t)(ticks - 1UL);   //Set Reload Register
    //NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */

    SysTick->VAL   = 0UL;                                                /* Load the SysTick Counter Value */
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                             /* Enable SysTick IRQ and SysTick Timer */
    return (0UL);                                                       /* Function successful */

}



static inline void delay_ms(uint32_t ms){

    SysTick->LOAD = (SystemCoreClock / 1000) - 1; // Brojac broji load + 1 jer ubraja 0, onda da bi bilo tacno ticks, treba da bude ticks - 1
    SysTick->VAL = 0;

    // Setuje CLK SRC na CPU CLK 
    REG_SET_BITS(&SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk);
    // Enabeles counter
    REG_SET_BITS(&SysTick->CTRL, SysTick_CTRL_ENABLE_Msk);
    
    for (uint32_t i = 0; i < ms; i++){
        while (REG_READ_FIELD(&SysTick->CTRL, SysTick_CTRL_COUNTFLAG_Msk) == 0){
            // wait
        }
        
    }

    // Disabling counter
    REG_CLEAR_BITS(&SysTick->CTRL, SysTick_CTRL_ENABLE_Msk);

}


#endif // MSMP0L1306_SYSTICK_H