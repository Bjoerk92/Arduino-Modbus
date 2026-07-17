/**
 * @file main.c
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Atmega.h"
#include "AVR_Drivers.h"

static void InitDrv(void) {
    setPinMode(0, OUTPUT);
};




int main(void)
{
    InitDrv();
    while(1) {
    }   
    return 0;
}
