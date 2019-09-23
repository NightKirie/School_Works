LIST p = 18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
	org 0x00
    
    LFSR FSR0, 120H
    LFSR FSR1, 130H
    clrf WREG
    clrf TRISD
    movlw 0X08
    movwf TRISD, 0
    movlw 0X01
A1: ADDWF POSTINC0, 1 ,0
    INCF WREG
    decfsz TRISD
    BRA A1
    movlw 0x08
    movwf TRISD, 0
A2:     
    ADDWF POSTINC1, 1 ,0
    decf WREG
    decfsz TRISD
    BRA A2
    movlw 0x08
    movwf TRISD, 0
    LFSR FSR0, 120H
    LFSR FSR1, 130H
    clrf WREG
PLUS:
    ADDWF POSTINC0, 0 ,0
    ADDWF POSTINC1, 1 ,0
    clrf WREG
    decfsz TRISD
    BRA PLUS
END
