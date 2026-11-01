# MSPM0L1306 System Library

Bare-metal system library for TI MSPM0L1306 (Arm Cortex-M0+). All register-level code is written from scratch, without SysConfig and DriverLib.

## Status

| Module | Mode             | Status                                            |
|--------|------------------|---------------------------------------------------|
|Clock   | -                |  ✅ (4/32 MHz, 16/24 MHz user-trim)              |
|GPIO    | polling + IRQ    |  ✅                                              |
|IOMUX   | -                |  ✅                                              |
|NVIC    | -                |  ✅ (minimal)                                    |
|SysTick | delay_ms         |  ✅                                              |
|UART0   | polling + RX IRQ |  ✅ (TX IRQ: partially working, see Known issues)|
|ADC12   | polling          |  ✅ (single-channel)                             |
|I2C     | polling          |  ✅                                              |
|SPI     | polling          |  ✅                                              |
|PWM     | -                |  ✅                                              |

## Project Structure

```
.
├───core/        # Cortex-M0+ core-specific code
├───include/     # Header files, one per driver
├───linker/      # Linker script
├───src/         # Driver implementation, one .c file per driver
├───examples/    # Usage examples for each driver
├───startup.c    # Vector table and Reset_Handler
├───main.c       # Application entry point
├───CMakeLists.txt
└───toolchain-arm-none-eabi.cmake
```

## Requirements

**Board:** TI LP-MSPM0L1306 LaunchPad (on-board XDS110 debug probe)
**Toolchain:** arm-none-eabi-gcc
**Build system:** CMake 3.20 or newer, Ninja (or another generator)
**Debugger:** OpenOCD with XDS110 support

## Build

```
cmake -S . -B build -G Ninja
cmake --build build
```

Output (`firmware.elf`, `firmware.bin`, `firmware.hex`) is generated in the `build/` directory.

The toolchain file is picked up automatically. Any generator that works with `arm-none-eabi-gcc` can be used instead of Ninja.

Note: build commands were not verified on Windows.

### Running the examples

Only `startup.c`, `main.c` and `src/*.c` are compiled. To run an example from `examples/`, copy its contents into `main.c`.

## Known issues

- **UART TX interrupt:** works for the first transmission only; the second transmission does not start. Not fully debugged.
- **ADC12:** only single-channel conversions are supported. Sequence mode is not working (`MEMRES[1]` always reads 0).
- **Untested after the last changes:** the board is no longer available, so the current state of `main` could not be re-verified on hardware.