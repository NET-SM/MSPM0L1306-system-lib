#include "mspm0l1306_iomux.h"
#include "mspm0_reg_utils.h"

void iomux_configure_pin(uint32_t pincm, uint32_t pf, uint32_t input_enable){
 
    IOMUX->SECCFG.PINCM[pincm] |= IOMUX_PINCM_PC_CONNECTED;
    write_reg_field(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_PF_OFS, 6, pf);

    if (input_enable){

        write_reg_bit(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_INENA_OFS, ENABLE);

    }

}

//  upisi PC_CONNECTED  + PF + (opciono INENA ako input_enable) IOMUX->PINCM[pincm]