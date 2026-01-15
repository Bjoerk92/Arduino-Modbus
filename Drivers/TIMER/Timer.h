/**
 * @file Timer.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-02
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include "avr.h"

typedef enum {
    TIMER0 = 0,
    TIMER1 = 1,
    TIMER2 = 2
}Timer_id_t;

typedef enum {
    Normal      = 0,    // Normal counter mode, TOP = 0xff, OCRx update = immediate, TOV FLag set = MAX
    PWM_1       = 1,    // Phase correct PWM, TOP = 0xff, OCRx update = TOP, TOV FLag set = BOTTOM
    CTC         = 2,    // Clear timer on compare match, TOP = OCRA, OCRx update = immediate, TOV FLag set = MAX
    FAST_PWM    = 3,    // Fast PWM, TOP = 0xff, OCRx update = BOTTOM, TOV FLag set = MAX
    PWM_2       = 5,    // Phase correct PWM, TOP = ORCA, OCRx update = TOP, TOV FLag set = BOTTOM
    FAST_PWM_2  = 7     // Fast PWM, TOP = OCRB, OCRx update = BOTTOM, TOV FLag set = TOP
}Timer_wavegen_mode_t;

typedef enum {
    DISABLED = 0,
    COMPARE_MATCH_B = 1,
    COMPARE_MATCH_A = 2,
    OVERFLOW_FLAG = 3
}IRQ_MODE_e;


typedef struct {
    Timer_id_t              Timer_id;
    Timer_wavegen_mode_t    Wave_gen;
    IRQ_MODE_e              IRQ_mode;

}Timer_Configuration_t;


void DRV_TIMER_Init(Timer_Configuration_t* configuration);
void DRV_SYSTIMER_INIT(void);

void __attribute((interrupt(16))) IRQ_ABC(void);