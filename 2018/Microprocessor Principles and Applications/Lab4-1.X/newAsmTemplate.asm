LIST p = 18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
	org 0x00
Initial:
MOVLF	macro	pa, pb
	movlw	pa
	movwf	pb, 1
	endm
ADDFF	macro	pa, pb, pc
	clrf	WREG
	movff	pa, WREG
	addwf	pb, 0, 0
	movwf	pc, 0
	endm
start:
	clrf	0x12
	clrf	0x13
	clrf	0x14
	clrf	0x15
	MOVLF	0x01, 0x12
	MOVLF	0x02, 0x13
	MOVLF	0x08, 0x15
	rcall	Fib
	goto	exit
Fib:
	ADDFF	0x12, 0x13, 0x14
	movff	0x13, 0x12
	movff	0x14, 0x13
	decfsz	0x15
	movlw	0x18
	movwf	PCL
	return
exit:
    end



