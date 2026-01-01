/**
 * @file Registers.h
 * @author Anders Bjørk (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-12-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdint.h>

#include "RegDef.h"

#define ACCESS_REGISTER_BYTE(x)  (*(volatile uint8_t*)(x))
#define ACCESS_REGISTER_WORD(x)  (*(volatile uint16_t*)(x))
#define ACCESS_REGISTER_DWORD(x) (*(volatile uint32_t*)(x))

typedef struct __attribute__((packed)) {
    uint8_t     reserved[3];    // addr: 0x00 - 0x02:   Reserved space at address
    PINB_t      PINB;           // addr: 0x03:          Port B input pins
    DDRB_t      DDRB;           // addr: 0x04:          Port B data direction register
    PORTB_t     PORTB;          // addr: 0x05:          Port B data register
    PINC_t      PINC;           // addr: 0x06:          Port C input pins
    DDRC_t      DDRC;           // addr: 0x07:          Port C data direction register
    PORTC_t     PORTC;          // addr: 0x08:          Port C data register
    PIND_t      PIND;           // addr: 0x09:          Port D input pins
    DDRD_t      DDRD;           // addr: 0x0A:          Port D data direction register
    PORTD_t     PORTD;          // addr: 0x0B:          Port D data register
    uint8_t     reserved2[9];   // addr: 0x0C - 0x14:   Reserved space at address 0x0C 0x14
    TIFR0_t     TIFR0;          // addr: 0x15:          Timer/Counter 0 Interrupt Flag Register
    TIFR1_t     TIFR1;          // addr: 0x16:          Timer/Counter 1 Interrupt Flag Register
    TIFR2_t     TIFR2;          // addr: 0x17:          Timer/Counter 2 Interrupt Flag Register
    uint8_t     reserved3[3];   // addr: 0x18 - 0x1A:   Reserved space at address
    PCIFR_t     PCIFR;          // addr: 0x1B:          Pin Change Interrupt Flag Register
    EIFR_t      EIFR;           // addr: 0x1C:          External Interrupt Flag Register
    EIMSK_t     EIMSK;          // addr: 0x1D:          External Interrupt Mask Register
    GPIOR0_t    GPIOR0;         // addr: 0x1E:          General Purpose I/O Register 0
    EECR_t      EECR;           // addr: 0x1F:          Eeprom Control Register
    uint8_t     EEDR;           // addr: 0x20:          Eeprom Data Register  
    EEAR_t      EEAR;           // addr: 0x22:          Eeprom Address register
    GTCCR_t     GTCCR;          // addr: 0x23:          General Timer/Counter Control Register
    TCCR0A_t    TCCR0A;         // addr: 0x24:          Timer/Counter 0 Control Register A
    TCCR0B_t    TCCR0B;         // addr: 0x25:          Timer/Counter 0 Control Register B
    uint8_t     TCNT0;          // addr: 0x26:          Timer/Counter 0
    uint8_t     OCR0A;          // addr: 0x27:          Timer/Counter 0 Output Compare Register A
    uint8_t     OCR0B;          // addr: 0x28:          Timer/Counter 0 Output Compare Register B
    uint8_t     reserved4;      // addr: 0x29:          Reserved space at address
    GPIOR1_t    GPIO1;          // addr: 0x2A:          General Purpose I/O Register 1
    GPIOR2_t    GPIO2;          // addr: 0x2B:          General Purpose I/O Register 2
    SPCR_t      SPRC;           // addr: 0x2C:          SPI Control Register
    SPSR_t      SPSC;           // addr: 0x2D:          SPI Status Register
    uint8_t     SPDR;           // addr: 0x2E:          SPI Data Register
    uint8_t     reserved5;      // addr: 0x2F:          Reserved space at address
    ACSR_t      ACSR;           // addr: 0x30:          Analog Comparator Control and Status Register
    uint8_t     reserved6[2];   // addr: 0x31 - 0x32:   Reserved space at address
    SMCR_t      SMCR;           // addr: 0x33:          Sleep Mode Control Register
    MCUSR_t     MCUSR;          // addr: 0x34:          MCU Control Register
    MCUCR_t     MCUCR;          // addr: 0x35:          MCU Status Register
    uint8_t     reserved7;      // addr: 0x36:          Reserved space at address
    SPMCSR_t    SPMCSR;         // addr: 0x37:          Store Program Memory Control Register
    uint8_t     reserved8[5];   // addr: 0x38 - 0x3C:   Reserved space at address
    SP_t        SP;             // addr: 0x3D - 0x3E:   Stack Pointer
    SREG_t      SREG;           // addr: 0x3F:          AVR Status Register
    uint8_t     reserved9[32];  // addr: 0x40 - 0x5F:   Reserved space at address
    WDTCSR_t    WDTCSR;         // addr: 0x60:          Watchdog Timer Control Register
    CLKPR_t     CLKPR;          // addr: 0x61:          Clock Prescale Register
    uint8_t     reserved10[2];  // addr: 0x62 - 0x63:   Reserved space at address
    PRR_t       PRR;            // addr: 0x64:          Power Reduction Register
    uint8_t     reserved11;     // addr: 0x65:          Reserved space at address
    uint8_t     OSCCAL;         // addr: 0x66:          Oscillator Calibration register
    uint8_t     reserved12;     // addr: 0x67:          Reserved space at address
    PCICR_t     PCICR;          // addr: 0x68:          Pin Change Interrupt Control Register
    EICRA_t     EICRA;          // addr: 0x69:          External Interrupt Control Register A
    uint8_t     reserved13;     // addr: 0x6A:          Reserved space at address
    PCMSK0_t    PCMSK0;         // addr: 0x6B:          Pin Change Mask Register 0
    PCMSK1_t    PCMSK1;         // addr: 0x6C:          Pin Change Mask Register 1
    PCMSK2_t    PCMSK2;         // addr: 0x6D:          Pin Change Mask Register 2
    TIMSK0_t    TIMSK0;         // addr: 0x6E:          Timer/Counter 0 Interrupt Mask Register
    TIMSK1_t    TIMSK1;         // addr: 0x6F:          Timer/Counter 1 Interrupt Mask Register
    TIMSK2_t    TIMSK2;         // addr: 0x70:          Timer/Counter 2 Interrupt Mask Register
    uint8_t     reserved14[7];  // addr: 0x71 - 0x77:   Reserved space at address
    ADC_t       ADC;            // addr: 0x78 - 0x79:   ADC Data Register
    ADCSRA_t    ADCSRA;         // addr: 0x7A:          ADC Control and Status Register A
    ADCSRB_t    ADCSRB;         // addr: 0x7B:          ADC Control and Status Register B
    ADMUX_t     ADMUX;          // addr: 0x7C:          ADC Multiplexer Selection Register
    uint8_t     reserved15;     // addr: 0x7D:          Reserved space at address
    DIDR0_t     DIDR0;          // addr: 0x7E:          Digital Input Disable Register 0
    DIDR1_t     DIDR1;          // addr: 0x7F:          Digital Input Disable Register 1
    TCCR1A_t    TCCR1A;         // addr: 0x80:          Timer/Counter 1 Control Register A
    TCCR1B_t    TCCR1B;         // addr: 0x81:          Timer/Counter 1 Control Register B
    TCCR1C_t    TCCR1C;         // addr: 0x82:          Timer/Counter 1 Control Register C
    uint8_t     reserved16;     // addr: 0x83:          Reserved space at address
    TCNT1_t     TCNT1;          // addr: 0x84 - 0x85:   Timer/Counter 1 Counter register
    ICR1_t      ICR1;           // addr: 0x86 - 0x87:   Timer/Counter 1 Input Capture Register
    OCR1A_t     OCR1A;          // addr: 0x88 - 0x89:   Timer/Counter 1 Output Compare Register A
    OCR1B_t     OCR1B;          // addr: 0x8A - 0x8B:   Timer/Counter 1 Output Compare Register B
    uint8_t     reserved17[36]; // addr: 0x8C - 0xAF:   Reserved space at address
    TCCR2A_t    TCCR2A;         // addr: 0xB0:          Timer/Counter 2 Control Register A
    TCCR2B_t    TCCR2B;         // addr: 0xB1:          Timer/Counter 2 Control Register B
    uint8_t     TCNT2;          // addr: 0xB2:          Timer/Counter 2 Counter Register
    uint8_t     OCR2A;          // addr: 0xB3:          Timer/Counter 2 Output Compare Register A
    uint8_t     OCR2B;          // addr: 0xB4:          Timer/Counter 2 Output Compare Register B
    uint8_t     reserved18;     // addr: 0xB5:          Reserved space at address
    ASSR_t      ASSR;           // addr: 0xB6:          Asynchronous Status Register
    uint8_t     reserved19;     // addr: 0xB7:          Reserved space at address
    uint8_t     TWBR;           // addr: 0xB8:          TWI Bit Rate Register
    TWSR_t      TWSR;           // addr: 0xB9:          TWI Status Register
    TWAR_t      TWAR;           // addr: 0xBA:          TWI Address Register
    uint8_t     TWDR;           // addr: 0xBB:          TWI Data Register
    TWCR_t      TWCR;           // addr: 0xBC:          TWI Control Register
    TWAMR_t     TWAMR;          // addr: 0xBD:          TWI Address Mask Register
    uint8_t     reserved20[2];  // addr: 0xBE - 0xBF:   Reserved space at address
    UCSR0A_t    UCSR0A;         // addr: 0xC0:          USART Control and Status Register 0 A
    UCSR0B_t    UCSR0B;         // addr: 0xC1:          USART Control and Status Register 0 B
    UCSR0C_t    UCSR0C;         // addr: 0xC2:          USART Control and Status Register 0 C
    uint8_t     reserved21;     // addr: 0xC3:          Reserved space at address
    UBRR0_t     UBRR0;          // addr: 0xC4 - 0xC5:   USART Baud Rate Register 0
    uint8_t     UDR0;           // addr: 0xC6:          USART Data Register 0
    uint8_t     reserved22[55]; // addr: 0xC7 - 0xFF:   Reserved space at address
}Atmega328p_regs_t;

#define reg_size sizeof(Atmega328p_regs_t)


static_assert(sizeof(Atmega328p_regs_t) == 0xFF, "Atmega328p_regs_t must be 0x100 bytes");

Atmega328p_regs_t* ptr_avr_reg = (Atmega328p_regs_t*)0x20;

