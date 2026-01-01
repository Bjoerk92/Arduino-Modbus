/**
 * @file uarts.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <stdint.h>


#define UART_BAUD_PRESCALER(x)  (((F_CPU / (x * 16UL))) - 1)


void uart_init(uint32_t baud);