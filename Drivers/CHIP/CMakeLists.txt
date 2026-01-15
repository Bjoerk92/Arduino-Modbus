cmake_minimum_required(VERSION 3.10)

add_library(CHIP INTERFACE
    Atmega328p.h
    avr.h
    avr-assert.h
    avr-interrupt.h
)

target_include_directories(CHIP INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)