LIST p = 18f4520
#include<p18f4520.inc>
    CONFIG OSC = INTIO67
    CONFIG WDT = OFF
	org 0x00
  
intial:	
    clrf WREG
    movlw 0x00
    cpfseq LATA
    goto Rotate
    
Loop:
    addwf LATA, 1, 0
    bov exit
    incf WREG
    goto Loop

exit: 
    nop
    nop
    nop
    goto intial
 
Rotate:    
    movlw 0x8f
    movwf LATB
    rlcf LATB, 0, 0
    
    
    end


