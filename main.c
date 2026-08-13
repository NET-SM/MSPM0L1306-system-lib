#include "system.h"


void s1_handler(uint32_t pin){
    gpio_toggle(PA26);
}

void s2_handler(uint32_t pin){
    gpio_toggle(PA0);
}

int main(void)
{

    iomux_configure_pin(IOMUX_PINCM19, IOMUX_PINCM19_PF_GPIOA_DIO18, 1, IOMUX_PULL_NONE);
    iomux_configure_pin(IOMUX_PINCM15, IOMUX_PINCM15_PF_GPIOA_DIO14, 1, IOMUX_PULL_UP);

    gpio_enable_power();
    gpio_enable_input(PA18);
    gpio_enable_input(PA14);

    gpio_configure_interrupt(PA18, GPIO_POLARITY_RISE);
    gpio_configure_interrupt(PA14, GPIO_POLARITY_FALL);
    gpio_enable_interrupt(PA18);
    gpio_enable_interrupt(PA14);

    nvic_enable_irq(GPIOA_INT_IRQn);

    iomux_configure_pin(IOMUX_PINCM27, IOMUX_PINCM27_PF_GPIOA_DIO26, 0, IOMUX_PULL_NONE);
    gpio_enable_output(PA26);

    iomux_configure_pin(IOMUX_PINCM1, IOMUX_PINCM1_PF_GPIOA_DIO00, 0, IOMUX_PULL_NONE);
    gpio_enable_output(PA0);
    

    gpio_register_callback(PA18, s1_handler);
    gpio_register_callback(PA14, s2_handler);

    while (1) {

    }
}

