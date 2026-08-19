#include "system.h"


int main(){

    adc_enable_power();     
    adc_init(ADC_SYSOSC, ADC_12BIT, ADC_SCKLDIV_NO_DIV, ADC_FRANGE_24_32MHZ); 

    adc_select_conversion_mode(ADC_SEQUENCE);
    adc_config_seq_addresses(ADC_SEQUENCE, 0, 1);


    adc_config_channel(0, ADC_CHANNEL_PA15);
    adc_set_channel_vref(0, ADC_VREF_VDDA_VSSA);
    adc_set_channel_stime_source(0, ADC_STIME_SCOMP0);
    adc_set_channel_trig_policy(0, ADC_TRIG_AUTO_NEXT);

    adc_config_channel(1, ADC_CHANNEL_PA25);
    adc_set_channel_vref(1, ADC_VREF_VDDA_VSSA);
    adc_set_channel_stime_source(1, ADC_STIME_SCOMP1);
    adc_set_channel_trig_policy(1, ADC_TRIG_AUTO_NEXT);

    adc_trigger_select(ADC_SW_TRIGGER);
    adc_mode_select(ADC_AUTO);
    adc_set_sample_time(ADC_STIME_SCOMP0, 50U);
    adc_set_sample_time(ADC_STIME_SCOMP1, 50U);
    
    
    
    while (1){
        
        adc_enable_conversion();
        adc_software_auto_start();

        while(!adc_is_result_ready(0)) {  };
        volatile uint32_t result_pa15 = adc_read_result(0);


        while(!adc_is_result_ready(1)) {  };
        volatile uint32_t result_pa25 = adc_read_result(1);

        (void) result_pa15;
        (void) result_pa25;
    }
}