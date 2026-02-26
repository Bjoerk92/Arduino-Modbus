cmake_minimum_required(VERSION 3.10)

add_library(AVR OBJECT
    Atmega.h
    avr-gcc.h
    avr-assert.h
    avr-interrupt.h
)

target_include_directories(AVR INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    chips/
)

target_link_directories(AVR INTERFACE
    chips/
)

