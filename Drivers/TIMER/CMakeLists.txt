cmake_minimum_required(VERSION 3.10)


add_library(TIMER OBJECT 
    Timer.c 
    Timer.h
)

target_include_directories(TIMER INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

target_link_libraries(TIMER PUBLIC
    CHIP
)