#include "mspm0l1306_iomux.h"
#include "mspm0_reg_utils.h"

void iomux_configure_pin(uint32_t pincm, uint32_t pf, uint32_t input_enable, iomux_pull_t pull){
    

    // Peripheral is connected
    IOMUX->SECCFG.PINCM[pincm] |= IOMUX_PINCM_PC_CONNECTED;
    
    // What is peripheral used for
    write_reg_field(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_PF_OFS, 6, pf);

    // Pull-up Config

    write_reg_bit(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_PIPU_OFS, DISABLE); // Disable PIPU Bit
    write_reg_bit(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_PIPD_OFS, DISABLE); // Clear PIPD Bit

    switch (pull){

    case IOMUX_PULL_UP:
        // Pull-up
        write_reg_bit(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_PIPU_OFS, ENABLE);
        break;

    case IOMUX_PULL_DOWN:
        write_reg_bit(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_PIPD_OFS, ENABLE);
        break;
    case IOMUX_PULL_NONE:
    default:
        break;
    }
    
    // Input Enable Control Selection enable/disable
    if (input_enable){

        write_reg_bit(&IOMUX->SECCFG.PINCM[pincm], IOMUX_PINCM_INENA_OFS, ENABLE);

    }

}

//  upisi PC_CONNECTED  + PF + (opciono INENA ako input_enable) IOMUX->PINCM[pincm]