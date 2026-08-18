#include "system.h"


int main(){

    adc_enable_power();   
    adc_init(ADC_SYSOSC, ADC_12BIT, ADC_SCKLDIV_NO_DIV, ADC_FRANGE_24_32MHZ); 
    adc_select_conversion_mode(ADC_SINGLE);
    adc_config_seq_addresses(ADC_SINGLE, 0, 0);
    adc_config_channel(0, ADC_CHANNEL_PA15);
    adc_set_channel_vref(0, ADC_VREF_VDDA_VSSA);
    adc_trigger_select(ADC_SW_TRIGGER);
    adc_mode_select(ADC_AUTO);
    adc_set_sample_time(ADC_STIME_SCOMP0, 50U);
    adc_set_channel_stime_source(0, ADC_STIME_SCOMP0);
    
    while (1){
        
        adc_enable_conversion();
        adc_software_auto_start();
        while(adc_is_busy()) {

        };
        volatile uint32_t result = adc_read_result(0);
        (void) result;
    }
}