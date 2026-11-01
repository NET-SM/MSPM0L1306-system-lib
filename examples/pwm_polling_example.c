#include "system.h"

int main(void) {

    iomux_configure_pin(IOMUX_PINCM13, IOMUX_PINCM13_PF_TIMG0_CCP0, DISABLE, IOMUX_PULL_NONE);
    
    pwm_reset();
    pwm_power_enable();
    
    pwm_set_clock_configuration(GPTimer_CLKSEL_BUSCLK, GPTimer_CLKDIV_NO_DIV);


    pwm_set_count_mode(GPTimer_CM_UP);
    pwm_set_up_clc_cac_czc();
    pwm_set_cvae(GPTimer_ZERO_VALUE);
    pwm_set_repeat_mode(GPTimer_REPEAT_CONTINUE);

    pwm_set_load((uint16_t) 0xFFFF);
    pwm_set_duty((uint16_t) 0x3FFF);
    pwm_set_coc_mode(GPTimer_COC_MODE_COMPARE);

    pwm_set_action_on_zero(GPTimer_ACTION_SET_HIGH);
    pwm_set_action_on_compare_up(GPTimer_ACTION_SET_LOW);

    pwm_set_direction(GPTimer_CCPD_DIR_OUTPUT);

    pwm_set_output_source(GPTimer_CCPO_SIGNAL_GEN);
    pwm_set_output_invert(0);
    pwm_set_disabled_state(0);
    pwm_output_enable();

    pwm_enable();
    while (1) {
        
    }
}


