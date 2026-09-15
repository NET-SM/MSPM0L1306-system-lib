cmake_minimum_required(VERSION 3.20)

# Toolchain fajl mora biti setovan PRE project() komande
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain-arm-none-eabi.cmake)

project(firmware C ASM)

set(CPU_FLAGS -mcpu=cortex-m0plus -mthumb)

add_compile_options(
    ${CPU_FLAGS}
    -O0
    -g3
    -Wall
)

add_link_options(
    ${CPU_FLAGS}
    -T${CMAKE_CURRENT_SOURCE_DIR}/linker/mspm0l1306.ld
    -nostdlib
)

# ============================================================
# Source Files
# ============================================================
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(${PROJECT_NAME}.elf
    startup.c
    main.c
    ${SRC_FILES}
)

target_include_directories(${PROJECT_NAME}.elf PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/core
)

target_link_libraries(${PROJECT_NAME}.elf gcc)

# ============================================================
# .bin / .hex 
# ============================================================
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex   ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMENT "Generating .bin and .hex"
)