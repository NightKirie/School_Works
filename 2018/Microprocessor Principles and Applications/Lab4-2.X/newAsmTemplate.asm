LIST p = 18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
	org 0x00
	
Initial:
    movlb   0x01
    movlw   0x06
    movwf   0x40, 1
    movlw   0x05
    movwf   0x16, 1
    movlw   0x04
    movwf   0x54, 1
    lfsr    FSR0, 100H
    movff   0x140, POSTINC0
    movff   0x116, POSTINC0
    movff   0x154, POSTINC0
    rcall   mclear
    lfsr    FSR0, 100H
    movff   POSTINC0, 0x140
    movff   POSTINC0, 0x116
    movff   POSTINC0, 0x154
    goto    exit
mclear:   

    movff   0x140, WREG
    mulwf   0x116
    movff   PROD, WREG
    mulwf   0x154
    movff   PROD, WREG
    clrf    0x140
    clrf    0x116
    clrf    0x154
    return
exit:
	
	
end	
	
	


