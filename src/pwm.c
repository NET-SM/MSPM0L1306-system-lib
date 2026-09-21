#include "mspm0l1306_pwm.h"
#include "mspm0_reg_utils.h"
#include "mspm0l1306_gptimer.h"

void pwm_reset(void){
    GPTIMER->GPRCM.RSTCTL = (GPTIMER_RSTCTL_KEY_UNLOCK_W | GPTIMER_RSTCTL_RESETASSERT);
}

void pwm_power_enable(void){
    GPTIMER->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | ENABLE);
}

void pwm_power_disable(void){
    GPTIMER->GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | DISABLE);
}

void pwm_enable(void){
    write_reg_bit(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_EN_OFS, ENABLE);
}

void pwm_disable(void){
    write_reg_bit(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_EN_OFS, DISABLE);
}

void pwm_set_clock_configuration(gptimer_clock_t clock, gptimer_clock_div_t divider){

    // Disable previous clock configs if there are any
    write_reg_bit(&GPTIMER->CLKSEL, GPTIMER_CLKSEL_LFCLK_OFS, DISABLE);
    write_reg_bit(&GPTIMER->CLKSEL, GPTIMER_CLKSEL_MFCLK_OFS, DISABLE);
    write_reg_bit(&GPTIMER->CLKSEL, GPTIMER_CLKSEL_BUSCLK_OFS, DISABLE);

    switch(clock){

        case GPTimer_CLKSEL_LFCLK:
            write_reg_bit(&GPTIMER->CLKSEL, GPTIMER_CLKSEL_LFCLK_OFS, ENABLE);
            break;
        case GPTimer_CLKSEL_MFCLK:
            write_reg_bit(&GPTIMER->CLKSEL, GPTIMER_CLKSEL_MFCLK_OFS, ENABLE);
            break;
        case GPTimer_CLKSEL_BUSCLK:
        default:
            write_reg_bit(&GPTIMER->CLKSEL, GPTIMER_CLKSEL_BUSCLK_OFS, ENABLE);
            break;
    }

    write_reg_field(&GPTIMER->CLKDIV, GPTIMER_CLKDIV_RATIO_OFS, GPTIMER_CLKDIV_RATIO_WIDTH, divider);
}

void pwm_set_count_mode(gptimer_count_mode_t mode){

    write_reg_field(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_CM_OFS, GPTIMER_CTRCTL_CM_WIDTH, mode);
}

void pwm_set_cvae(gptimer_cvae_t cvae){

    write_reg_field(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_CVAE_OFS, GPTIMER_CTRCTL_CVAE_WIDTH, cvae);
}

void pwm_set_repeat_mode(gptimer_repeat_t mode){
    
    write_reg_field(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_REPEAT_OFS, GPTIMER_CTRCTL_REPEAT_WIDTH, mode);
}


// Pogledati ponovo je se TRM i TI .h razlikuju
void pwm_set_load(uint16_t value){

    write_reg_field(&GPTIMER->COUNTERREGS.LOAD, GPTIMER_LOAD_LD_OFS, GPTIMER_LOAD_LD_WIDTH, value);
}

void pwm_set_duty(uint16_t value){

    write_reg_field(&GPTIMER->COUNTERREGS.CC_01[0], GPTIMER_CC01_CCVAL_OFS, GPTIMER_CC01_CCVAL_WIDTH, value);
}

void pwm_set_coc_mode(gptimer_coc_mode_t mode){

    write_reg_bit(&GPTIMER->COUNTERREGS.CCCTL_01[0], GPTIMER_CCCTL01_COC_OFS, mode);
}

void pwm_set_direction(gptimer_ccpd_direction_t direction){

    write_reg_bit(&GPTIMER->COMMONREGS.CCPD, GPTIMER_CCPD_C0CCP0_OFS, direction);
}

void pwm_set_action_on_zero(gptimer_ccp_action_t action){

    write_reg_field(&GPTIMER->COUNTERREGS.CCACT_01[0], GPTIMER_CCACT01_ZACT_OFS, GPTIMER_CCACT01_ZACT_WIDTH, action);

}
void pwm_set_action_on_compare_up(gptimer_ccp_action_t action){

    write_reg_field(&GPTIMER->COUNTERREGS.CCACT_01[0], GPTIMER_CCACT01_CUACT_OFS, GPTIMER_CCACT01_CUACT_WIDTH, action);
}

void pwm_set_output_source(gptimer_ccpo_source_t source){
    
    write_reg_field(&GPTIMER->COUNTERREGS.OCTL_01[0], GPTIMER_OCTL01_CCPO_OFS, GPTIMER_OCTL01_CCPO_WIDTH, source);
}

void pwm_set_output_invert(uint8_t invert){
    
    write_reg_bit(&GPTIMER->COUNTERREGS.OCTL_01[0], GPTIMER_OCTL01_CCPOINV_OFS, invert);
}

void pwm_set_disabled_state(uint8_t high_when_disabled){
    
    write_reg_bit(&GPTIMER->COUNTERREGS.OCTL_01[0], GPTIMER_OCTL01_CCPIV_OFS, high_when_disabled);
}

void pwm_output_enable(void){

    write_reg_bit(&GPTIMER->COMMONREGS.ODIS, GPTIMER_ODIS_C0CCP0_OFS, DISABLE);
}

void pwm_output_disabled(void){

    write_reg_bit(&GPTIMER->COMMONREGS.ODIS, GPTIMER_ODIS_C0CCP0_OFS, ENABLE);
}
void pwm_set_up_clc_cac_czc(void){

    write_reg_field(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_CLC_OFS, GPTIMER_CTRCTL_CLC_WIDTH, 0U);
    write_reg_field(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_CAC_OFS, GPTIMER_CTRCTL_CAC_WIDTH, 0U);
    write_reg_field(&GPTIMER->COUNTERREGS.CTRCTL, GPTIMER_CTRCTL_CZC_OFS, GPTIMER_CTRCTL_CZC_WIDTH, 0U);
}