/**
 * @file gpio.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-01-01
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum PinMode_etag{
    OUTPUT,
    INPUT
}PinMode_e;

typedef enum PinState_etag{
    LOW = 0,
    HIGH = 1
}PinState_e;

typedef enum GPIO_IRQ_MODE_etag{
    FALLING_EDGE,
    RISING_EDGE,
    CHANGE
}GPIO_IRQ_MODE_t;

void    DRV_GPIO_Init(uint16_t pin, PinMode_e dir);
void    DRV_GPIO_Set(uint16_t pin, PinState_e state);
bool    DRV_GPIO_Get(uint16_t pin, PinState_e *state);
void    DRV_GPIO_Toggle(uint16_t pin);

void    DRV_GPIO_SetupIRQ(uint16_t pin, GPIO_IRQ_MODE_t mode);