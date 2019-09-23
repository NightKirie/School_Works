#include "xc.inc"
GLOBAL _mul
    
PSECT mytext, local, class=CODE, reloc=2

_mul:
    MOVFF 0x001, LATC
    MOVFF 0x003, LATD
    MOVLW 0x08
    MOVWF LATA, f
    CLRF PRODL
    CLRF PRODH
    CLRF WREG
start: 
    BRA shift
aftershift:
    BTFSC LATD, 7
    BRA multi   
aftermulti:
    RLCF LATD, f
    BCF LATD, 0, 0
    DECFSZ LATA
    BRA start
    MOVFF PRODL, 0x001
    MOVFF PRODH, 0x002
    RETURN
multi: 
    MOVFF LATC, WREG
    ADDWF PRODL, f
    CLRF WREG
    ADDWFC PRODH, f
    BRA aftermulti
shift:
    RLNCF PRODH, f 
    BTFSC PRODL, 7
    INCF PRODH
    RLNCF PRODL, f
    BCF PRODL, 0, 0
    CLRF WREG
    BRA aftershift
    
 

 