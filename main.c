#include "system.h"


int main(void)
{

    //IOMUX->SECCFG.PINCM[26] = IOMUX_PINCM_PC_CONNECTED | IOMUX_PINCM27_PF_GPIOA_DIO26;
    
    iomux_configure_pin(IOMUX_PINCM19, IOMUX_PINCM19_PF_GPIOA_DIO18, 1);
    gpio_enable_power();
    gpio_enable_input(PA18);

    //GPIOA->GPRCM.PWREN = GPIO_PWREN_KEY_UNLOCK_W | GPIO_PWREN_ENABLE_ENABLE;
    
    // PA26 -> Output
    //GPIOA->DOE31_0 |= LED2_PIN;
    
    iomux_configure_pin(IOMUX_PINCM27, IOMUX_PINCM27_PF_GPIOA_DIO26, 0);
    gpio_enable_output(PA26);
    
    // Pocetno stanje
    //GPIOA->DOUTCLR31_0 = LED2_PIN;

    while (1) {
        
        //GPIOA->DOUTTGL31_0 = LED2_PIN;
        //delay_ms(3000);

        if(gpio_read(PA18) == 0){
            gpio_write(PA26, 1); // LED ON while S1 pressed
        } else {
            gpio_write(PA26, 0);
        }


    }
}