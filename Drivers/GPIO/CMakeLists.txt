cmake_minimum_required(VERSION 3.10)

add_library(GPIO OBJECT 
    gpio.c 
    gpio.h
)

target_include_directories(GPIO INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

target_link_libraries(GPIO 
    PUBLIC
        CHIP
)
