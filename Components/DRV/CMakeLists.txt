cmake_minimum_required(VERSION 3.10)


add_library(DRV INTERFACE
    inc/Driver_interface.h
)

target_include_directories(DRV INTERFACE
    inc/
)








add_subdirectory(Timers)