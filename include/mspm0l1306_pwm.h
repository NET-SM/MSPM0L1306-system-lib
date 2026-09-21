#ifndef MSPM0L1306_PWM_H
#define MSPM0L1306_PWM_H

#include "mspm0l1306_gptimer.h"

void pwm_reset(void);
void pwm_power_enable(void);
void pwm_power_disable(void);
void pwm_enable(void);
void pwm_disable(void);

void pwm_set_clock_configuration                (gptimer_clock_t clock, gptimer_clock_div_t divider);
void pwm_set_count_mode                         (gptimer_count_mode_t mode);
void pwm_set_cvae                               (gptimer_cvae_t cvae);
void pwm_set_repeat_mode                        (gptimer_repeat_t mode);

void pwm_set_load                               (uint16_t value);
void pwm_set_duty                               (uint16_t value);
void pwm_set_coc_mode                           (gptimer_coc_mode_t mode);
void pwm_set_direction                          (gptimer_ccpd_direction_t direction);
void pwm_set_action_on_zero                     (gptimer_ccp_action_t action);
void pwm_set_action_on_compare_up               (gptimer_ccp_action_t action);
void pwm_set_output_source                      (gptimer_ccpo_source_t source);
void pwm_set_output_invert                      (uint8_t invert);
void pwm_set_disabled_state                     (uint8_t high_when_disabled);
void pwm_output_enable                          (void);
void pwm_output_disabled                        (void);
void pwm_set_up_clc_cac_czc                     (void);
#endif // MSPM0L1306_PWM_H