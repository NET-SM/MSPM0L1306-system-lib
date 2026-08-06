#ifndef MSPM0_REG_UTILS_H
#define MSPM0_REG_UTILS_H
#include <stdint.h>

static inline void REG_SET_BITS(volatile uint32_t *reg, uint32_t mask){

    *reg |= mask;
}
static inline void REG_CLEAR_BITS(volatile uint32_t *reg, uint32_t mask){
    
    *reg &= ~mask;

} // AND NOT
static inline void REG_WRITE_FIELD(volatile uint32_t *reg, uint32_t mask, uint32_t value){

    REG_CLEAR_BITS(reg, mask);
    *reg |= value;

} // clear+set u jednom pozivu (ono što si ručno radio za SYSOSCCFG.FREQ)
static inline uint32_t REG_READ_FIELD(volatile uint32_t *reg, uint32_t mask){

    uint32_t read_bit;
    uint32_t shift;
    while ((mask & 1) == 0){
        mask >> 1;
        shift++;
    }
    read_bit = (*reg & mask) >> shift;

    return read_bit; 
}



#endif // MSPM0_REG_UTILS_H