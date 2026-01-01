cmake_minimum_required(VERSION 3.10)


add_library(UARTS OBJECT 
    uarts.c 
    uarts.h
)

target_include_directories(UARTS INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

target_link_libraries(UARTS 
    PUBLIC
        CHIP
)
