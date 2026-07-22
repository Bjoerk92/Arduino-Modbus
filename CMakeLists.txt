cmake_minimum_required(VERSION 3.10)

set(TARGET_CHIP "ATmega328P" CACHE STRING "Target AVR chip")
set(F_CPU "16000000UL" CACHE STRING "CPU clock frequency")
set(BAUD "9600" CACHE STRING "UART baud rate")

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/../ArduinoSys/toolchain/avr_toolchain.cmake" CACHE FILEPATH "Toolchain file for AVR")
endif()

project (Modbus C CXX ASM)

set(CMAKE_BUILD_TYPE Release)

# Project setup
add_executable(${PROJECT_NAME} main.c)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")

target_link_libraries(${PROJECT_NAME} PUBLIC
    AVR_CMSIS
    Drivers
)

add_subdirectory(Components)
add_subdirectory(ArduinoSys/AVR_CMSIS)
add_subdirectory(ArduinoDriver/Drivers)

# Compiling targets
add_custom_target(strip ALL     ${AVRSTRIP} "${PROJECT_NAME}.elf" DEPENDS ${PROJECT_NAME})
add_custom_target(hex   ALL     ${OBJCOPY} -R .eeprom -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.hex" DEPENDS strip)
add_custom_target(eeprom        ${OBJCOPY} -j .eeprom --change-section-lma .eeprom=0 -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.eeprom" DEPENDS strip)

add_custom_target(flash ${AVRDUDE} -c ${PROG_TYPE} -p ${MCU} -U flash:w:${PROJECT_NAME}.hex DEPENDS hex)
