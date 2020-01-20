LIST p = 18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
	org 0x00
    
    CLRF WREG
    MOVLW 0xB5
    ANDLW 0x7C
    XORLW 0xFF
    MOVWF LATD
    
    CLRF WREG
    MOVLW 0x96
    IORLW 0x69
    XORLW 0xFF
    MOVWF LATC
    
    end