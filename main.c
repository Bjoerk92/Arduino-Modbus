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
#include "Timers.h"


static void TimerOverflowCallback(void) {
    // This function will be called when the timer overflows
    // You can toggle an LED, send a message, or perform any other action here
}

static void InitDrv(void) {
    
    Timer_config_t Timer_cfg = {
        .timer_id = TIMER_ID_1,
        .wave_gen_mode = WAVE_GEN_MODE_NORMAL,
        .clock_select = CLOCK_SELECT_CLK_64,
        .timer_irq_mode = TIMER_IRQ_MODE_OVERFLOW,
        .timer_irq_callback = TimerOverflowCallback,
    };

    Timers_Init(&Timer_cfg);

};




int main(void)
{
    InitDrv();
    while(1) {
    }   
    return 0;
}
