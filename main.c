#include "system.h"


int main(void)
{

    IOMUX->SECCFG.PINCM[26] = IOMUX_PINCM_PC_CONNECTED | IOMUX_PINCM27_PF_GPIOA_DIO26;
    gpio_enable_power();
    //GPIOA->GPRCM.PWREN = GPIO_PWREN_KEY_UNLOCK_W | GPIO_PWREN_ENABLE_ENABLE;
    
    // PA26 -> Output
    GPIOA->DOE31_0 |= LED2_PIN;

    // Pocetno stanje
    GPIOA->DOUTCLR31_0 = LED2_PIN;

    while (1) {
        
        GPIOA->DOUTTGL31_0 = LED2_PIN;
        delay_ms(3000);
    }
}