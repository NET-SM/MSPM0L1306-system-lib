#include "mspm0l1306_gpio.h"
#include "mspm0_reg_utils.h"

void gpio_enable_power(void){

    GPIOA->GPRCM.PWREN = GPIO_PWREN_KEY_UNLOCK_W | 0x1;

}


void gpio_configure_interrupt(uint32_t pin, uint32_t edge)
{
 
    if (pin < 16){ 

        uint32_t shift =  pin * 2;
        GPIOA->POLARITY15_0 = (GPIOA->POLARITY15_0 &~ (0x3U << shift)) | (edge << shift);


    }else{

        uint32_t shift =  (pin - 16) * 2;
        GPIOA->POLARITY31_16 = (GPIOA->POLARITY31_16 &~ (0x3U << shift)) | (edge << shift);

    }

}

void gpio_enable_interrupt(uint32_t pin){
    
    write_reg_bit(&GPIOA->CPU_INT.IMASK, pin, ENABLE);   
}

void gpio_clear_interrupt(uint32_t pin)
{
    uint32_t shifted_pin = 1U << pin;

    GPIOA->CPU_INT.ICLR = shifted_pin;
}

uint32_t gpio_get_interrupt_status(uint32_t pin)
{
    uint32_t status = 0U; 
    uint32_t shifted_pin = 1U << pin;

    if (GPIOA->CPU_INT.MIS & shifted_pin) status = 1U; 

    return status;
}

// Configuration ( used during init phase of a GPIO )

void gpio_enable_output(uint32_t pin){
    
    write_reg_bit(&GPIOA->DOE31_0, pin, ENABLE);

}

void gpio_enable_input(uint32_t pin){

    write_reg_bit(&GPIOA->DOE31_0, pin, DISABLE);

}

// RW Funcs.

void gpio_write(uint32_t pin, uint32_t value){

    if(value){
    
        GPIOA->DOUTSET31_0 = (1U << pin);
    
    } else {

        GPIOA->DOUTCLR31_0 = (1U << pin);

    }

}


uint32_t gpio_read(uint32_t pin){

    uint32_t read_value = read_reg_bit(&GPIOA->DIN31_0, pin);
    return read_value;

}

void gpio_toggle(uint32_t pin){

    GPIOA->DOUTTGL31_0 = (1U << pin);

}

static gpio_callback_t callbacks[32] = {0};

void gpio_register_callback(uint32_t pin, gpio_callback_t callback){
    
    callbacks[pin] = callback;

}

void gpio_dispatch_interrupt(uint32_t pin){

    if(callbacks[pin] != 0){
        callbacks[pin](pin);
    }

    gpio_clear_interrupt(pin);
}