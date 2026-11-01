## MSPM0L1306 System Library

Bare-metal system library for TI MSPML1306 (Arm Cortex-M0+). All register-level code is written from scratch, without SysConfig and DriverLib.

## Status

| Module | Mode          | Status |
|--------|---------------|--------|
|Clock   | -             | 4/32 MHz, 16/24 MHz user-trim |
|GPIO    | polling + IRQ |  ✅                     |
|IOMUX   | -             |  ✅                     |
|NVIC    | -             |  ✅ (minimal)           |
|SysTick | delay_ms      |  ✅                     |
|UART0   | polling + IRQ |  ✅                     |
|ADC12   | polling       |  ✅ (single-channel)    |
|I2C     | polling       |  ✅                     |
|SPI     | polling       |  ✅                     |
|PWM     | polling       |  ✅                     |

## Project Structure

## Project Structure
```
├───core/        # Cortex-M0+ core-specific code
├───include/     # Header files, one per driver
├───linker/      # Linker script
├───src/         # Driver implementation, one .c file per driver
├───examples/    # Usage examples for each driver
├───startup.c    # Vector table and Reset_Hanlder
├───main.c       # Application entry point
├───CMakeList.txt
└───toolchain-arm-none-eabi.cmake
```