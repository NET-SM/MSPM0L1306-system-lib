#ifndef SYSTEM_H
#define SYSTEM_H

#include "mspm0l1306_base.h"
#include "mspm0_reg_utils.h"
#include "mspm0l1306_sysctl.h"
#include "mspm0l1306_gpio.h"
#include "mspm0l1306_iomux.h"


typedef enum {
    CLOCK_4MHZ = 4,
    CLOCK_16MHZ = 16,   // TODO
    CLOCK_24MHZ = 24,   // TODO
    CLOCK_32MHZ = 32,
    CLOCK_48MHZ = 48,   
} SystemClock_t;

extern uint32_t SystemCoreClock;

void SystemInit(SystemClock_t clock);
void ClockInit(SystemClock_t clock);

#endif