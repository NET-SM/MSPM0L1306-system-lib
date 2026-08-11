#include "system.h"


int main(void)
{

    CLK_OUT_SETUP();

    // 24MHz: CAP = 0 FREQ = SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC24M
    Trim_Function(20, 8, 1, SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC16M);


    //IOMUX->SECCFG.PINCM[26] = IOMUX_PINCM_PC_CONNECTED | IOMUX_PINCM27_PF_GPIOA_DIO26;
    //GPIOA->GPRCM.PWREN = GPIO_PWREN_KEY_UNLOCK_W | GPIO_PWREN_ENABLE_ENABLE;
    
    // PA26 -> Output
    //GPIOA->DOE31_0 |= LED2_PIN;

    // Pocetno stanje
    //GPIOA->DOUTCLR31_0 = LED2_PIN;

    while (1) {
        
        //GPIOA->DOUTTGL31_0 = LED2_PIN;
        //delay_ms(1000);
    }
}