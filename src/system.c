#include "system.h"

uint32_t SystemCoreClock;

void ClockInit(SystemClock_t clock);

void SystemInit(SystemClock_t clock)
{
    // Validacija
    if (clock > CLOCK_32MHZ) {
        clock = CLOCK_32MHZ;  // Fallback na max
    }

    // Konfigurisanje SYSOSC frekv.

    ClockInit(clock);
    SystemCoreClock = (uint32_t)clock * 1000000;
}

void ClockInit(SystemClock_t clock){

    // Nema potrebe za proverom jer je enumerisano

    uint32_t freq_value;
    
    switch (clock)
    {
    case CLOCK_4MHZ:
        freq_value = 0x1;
        break;
    case CLOCK_16MHZ:
        // TODO
        break;
    case CLOCK_24MHZ:
        // TODO
        break;
    case CLOCK_32MHZ:
        freq_value = 0x0;
        break;
    case CLOCK_48MHZ:
        freq_value = 0x3;
        break;
    default:
        break;
    }


    // Clearujemo preostale bite i stavljamo nove
    SYSCTL->SOCLOCK.SYSOSCCFG = (SYSCTL->SOCLOCK.SYSOSCCFG & ~0x3) | freq_value; 
    
    // Wait for sync
    while ((SYSCTL->SOCLOCK.CLKSTATUS & 0x3) != freq_value) { }  

}

void Flash_Init(){

};

void Power_Init(){

};
