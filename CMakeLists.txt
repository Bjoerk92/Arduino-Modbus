cmake_minimum_required(VERSION 3.10)

# Variables regarding the AVR chip
set(MCU   atmega328p)
set(F_CPU 16000000)
set(BAUD  9600)
add_definitions(-DF_CPU=${F_CPU})

# program names
set(AVRCPP   avr-g++)
set(AVRC     avr-gcc)
set(AVRSTRIP avr-strip)
set(OBJCOPY  avr-objcopy)
set(OBJDUMP  avr-objdump)
set(AVRSIZE  avr-size)
set(AVRDUDE  avrdude)

# Sets the compiler
# Needs to come before the project function
set(CMAKE_SYSTEM_NAME  Generic)
set(CMAKE_CXX_COMPILER ${AVRCPP})
set(CMAKE_C_COMPILER   ${AVRC})
set(CMAKE_ASM_COMPILER   ${AVRC})

project (Modbus C CXX ASM)

set(CMAKE_BUILD_TYPE Release)

# Compiler flags
set(CSTANDARD "-std=gnu17")
set(CWARN     "-Wall -Wstrict-prototypes -Wl,--gc-sections -Wl,--relax")
set(CTUNING   "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections")
set(COPT      "-Os -lm -lprintf_flt")
set(CMCU      "-mmcu=${MCU}")
set(CDEFS     "-DF_CPU=${F_CPU} -DBAUD=${BAUD}")

set(CFLAGS   "${CMCU} ${CDEFS} ${COPT} ${CWARN} ${CSTANDARD} ${CTUNING}")
set(CXXFLAGS "${CMCU} ${CDEFS} ${COPT} ${CTUNING}")

set(CMAKE_C_FLAGS   "${CFLAGS}")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")
set(CMAKE_ASM_FLAGS   "${CFLAGS}")

SET(TARGET_CHIP "ATmega328P" CACHE STRING  "The AVR chip to target")

# Project setup
add_executable(${PROJECT_NAME} main.c)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")

SET(__AVR_ATmega328P__=1 CACHE STRING "Define the AVR chip to target")

add_compile_definitions(
    PUBLIC
        "F_CPU=${F_CPU}"
        "__AVR_ATmega328P__=1"
)

target_compile_definitions(${PROJECT_NAME} 
    PUBLIC
        "__AVR_ATmega328P__=1"
        "F_CPU=${F_CPU}"
)   

target_link_libraries(${PROJECT_NAME} PUBLIC
    AVR

)

add_subdirectory(Components)



# Compiling targets
add_custom_target(strip ALL     ${AVRSTRIP} "${PROJECT_NAME}.elf" DEPENDS ${PROJECT_NAME})
add_custom_target(hex   ALL     ${OBJCOPY} -R .eeprom -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.hex" DEPENDS strip)
add_custom_target(eeprom        ${OBJCOPY} -j .eeprom --change-section-lma .eeprom=0 -O ihex "${PROJECT_NAME}.elf" "${PROJECT_NAME}.eeprom" DEPENDS strip)

add_custom_target(flash ${AVRDUDE} -c ${PROG_TYPE} -p ${MCU} -U flash:w:${PROJECT_NAME}.hex DEPENDS hex)
