/**
 * @file atmega328p.h
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
#include "RegDef.h"
#include "Registers.h"
#include "avr-assert.h"


#ifndef WEAK
    /**
     * @def WEAK
     * @brief MACRO to mark a function as weak
     * @details a function marked as weak can be overriden by another function
     * 
     * @date 2026-01-01
     * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
     * 
    */
    #define WEAK __attribute__((weak))
#endif

#ifndef NORETURN
    /**
     * @def NORETURN
     * @brief MACRO to mark a function as not returning anything
     * @details a function marked as not returning anything will not return anything
     * 
     * @date 2026-01-01
     * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
     * 
    */
    #define NORETURN __attribute__((noreturn))
#endif

#ifndef NOINLINE
    /**
     * @def NOINLINE
     * @brief MACRO to mark a function as not inlined
     * @details a function marked as not inlined will not be inlined by the compiler
     * 
     * @date 2026-01-01
     * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
     * 
    */
    #define NOINLINE __attribute__((noinline))
#endif

#ifndef INLINE
    /**
     * @def INLINE
     * @brief MACRO to mark a function as inlined
     * @details a function marked as inlined will be inlined by the compiler
     * 
     * @date 2026-01-01
     * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
     * 
    */
    #define INLINE __attribute__((inline))
#endif

#ifndef ALWAYS_INLINE
    /**
     * @def ALWAYS_INLINE
     * @brief MACRO to mark a function as always inlined
     * @details a function marked as always inlined will always be inlined by the compiler
     * 
     * @date 2026-01-01
     * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
     * 
    */
    #define ALWAYS_INLINE __attribute__((always_inline))
#endif

#ifndef IRQ_HANDLER
    /**
     * @def IRQ_HANDLER
     * @brief MACRO to mark a function as an IRQ handler
     * @details a function marked as an IRQ handler will be called when an interrupt happens
     * 
     * @date 2026-01-01
     * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
     * 
    */
    #define IRQ_HANDLER __attribute__((interrupt))
#endif