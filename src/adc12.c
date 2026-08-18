#include "mspm0l1306_adc12.h"
#include "mspm0_reg_utils.h"


void adc_enable_power(void){

    ADC12->ULLEM.GPRCM.PWREN = ( PWREN_KEY_UNLOCK_W | ENABLE );

}

void adc_disable_power(void){

    ADC12->ULLEM.GPRCM.PWREN = (PWREN_KEY_UNLOCK_W | DISABLE );

}

void adc_init(adc_clksrc_t clk_source, adc_res_t resolution, adc_sclkdiv_sel_t sclkdiv, adc_frange_sel_t frange){ 

    switch (clk_source) {

        case ADC_ULPCLK:
        
            ADC12->ULLEM.GPRCM.CLKCFG = ADC_CLKCFG_KEY_UNLOCK_W | ADC_CLKCFG_SAMPCLK_ULPCLK;
            break;

        case ADC_SYSOSC:
        
            ADC12->ULLEM.GPRCM.CLKCFG = ADC_CLKCFG_KEY_UNLOCK_W | ADC_CLKCFG_SAMPCLK_SYSOSC;
            break;

        case ADC_HFCLK:
        default:

            ADC12->ULLEM.GPRCM.CLKCFG = ADC_CLKCFG_KEY_UNLOCK_W | ADC_CLKCFG_SAMPCLK_HFCLK;
            break;
    }

    write_reg_field(&ADC12->ULLEM.CTL2, ADC_CTL2_RES_OFS, ADC_CTL2_RES_WIDTH, resolution);
    write_reg_field(&ADC12->ULLEM.CLKFREQ,ADC_CLKFREQ_FRANGE_OFS, ADC_CLKFREQ_FRANGE_WIDTH, frange);
    write_reg_field(&ADC12->ULLEM.CTL0, ADC_CTL0_SCLKDIV_OFS, ADC_CTL0_SCLKDIV_WIDTH, sclkdiv);
}

void adc_select_conversion_mode(adc_repeat_mode_t repeat_mode){

    write_reg_field(&ADC12->ULLEM.CTL1, ADC_CTL1_CONSEQ_OFS, ADC_CTL1_CONSEQ_WIDTH, repeat_mode);

}

void adc_config_seq_addresses(adc_repeat_mode_t repeat_mode, uint32_t start_add, uint32_t end_add){

    write_reg_field(&ADC12->ULLEM.CTL2, ADC_CTL2_STARTADD_OFS, ADC_CTL2_STARTADD_WIDTH, start_add);
    
    if(repeat_mode == ADC_SEQUENCE || repeat_mode == ADC__REPEATSEQUENCE){

        write_reg_field(&ADC12->ULLEM.CTL2, ADC_CTL2_ENDADD_OFS, ADC_CTL2_ENDADD_WIDTH, end_add);
    }  
}

void adc_config_channel(uint32_t mem_idx, adc_channel_t channel){

    // CTL0.ENC must be set to 0 to access MEMCTL register
    if(read_reg_bit(&ADC12->ULLEM.CTL0, ADC_CTL0_ENC_OFS)) write_reg_bit(&ADC12->ULLEM.CTL0, ADC_CTL0_ENC_OFS, DISABLE);


    write_reg_field(&ADC12->ULLEM.MEMCTL[mem_idx], ADC_MEMCTL_CHANSEL_OFS, 
                    ADC_MEMCTL_CHANSEL_WIDTH, channel);


}

void adc_set_channel_vref(uint32_t mem_idx, adc_vref_t vref){

    write_reg_field(&ADC12->ULLEM.MEMCTL[mem_idx], ADC_MEMCTL_VRSEL_OFS, 
                    ADC_MEMCTL_VRSEL_WIDTH, vref);

}

void adc_trigger_select(adc_trig_sel_t trigger_select){

    write_reg_bit(&ADC12->ULLEM.CTL1, ADC_CTL1_TRIGSRC_OFS, trigger_select);

}

void adc_mode_select(adc_samp_mode_sel_t mode){

    uint32_t check = read_reg_bit(&ADC12->ULLEM.CTL1, ADC_CTL1_TRIGSRC_OFS);

    if( mode == ADC_MANUAL && check) return;           // MANUAL not valid for HW trigger

    write_reg_bit(&ADC12->ULLEM.CTL1, ADC_CTL1_SAMPMODE_OFS, mode);

}

void adc_set_sample_time(adc_stime_sel_t scomp, uint32_t val){

    if(scomp == ADC_STIME_SCOMP0){

        write_reg_field(&ADC12->ULLEM.SCOMP0, ADC_SCOMP0_VAL_OFS, 
                        ADC_SCOMP0_VAL_WIDTH, val);

    } else{

        write_reg_field(&ADC12->ULLEM.SCOMP1, ADC_SCOMP1_VAL_OFS, 
                        ADC_SCOMP1_VAL_WIDTH, val);

    }

}

void adc_set_channel_stime_source(uint32_t mem_idx, adc_stime_sel_t scomp){

    write_reg_bit(&ADC12->ULLEM.MEMCTL[mem_idx], ADC_MEMCTL_STIME_OFS, scomp);

}

void adc_set_channel_trig_policy(uint32_t mem_idx, uint32_t trig_needed){

    write_reg_bit(&ADC12->ULLEM.MEMCTL[mem_idx], ADC_MEMCTL_TRIG_OFS, trig_needed);

}

void adc_enable_conversion(void){
    write_reg_bit(&ADC12->ULLEM.CTL0, ADC_CTL0_ENC_OFS, ENABLE);
}

void adc_disable_conversion(void){
    write_reg_bit(&ADC12->ULLEM.CTL0, ADC_CTL0_ENC_OFS, DISABLE);
}

void adc_software_auto_start(void){

    // Set SC bit to start sample phase
    write_reg_bit(&ADC12->ULLEM.CTL1, ADC_CTL1_SC_OFS, ENABLE);

    // TODO Sequence modes

}

uint32_t adc_is_busy(void){

    uint32_t status = read_reg_bit(&ADC12->ULLEM.STATUS, ADC_STATUS_BUSY_OFS);
    
    return status;
}

uint32_t adc_read_result(uint32_t mem_idx){

    // 12 conversion-result storage registers (MEMRES0:11)
    uint32_t result = read_reg_field(&ADC12->ULLEM.MEMRES[mem_idx], ADC_MEMRES_RESULT_OFS, ADC_MEMRES_RESULT_WIDTH);

    return result;

} 
