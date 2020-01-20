#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP =OFF
#include <xc.h>
volatile int init = 75;
void main(void) {
    TRISDbits.RD0 = 1;
    TRISCbits.RC2 = 0;
    T2CONbits.TMR2ON = 1;
    T2CONbits.T2CKPS = 3;
    OSCCONbits.IRCF = 3;
    CCP1CONbits.CCP1M = 12;
    PR2 = 155;
    CCP1CONbits.DC1B = 3;
    CCPR1L = 18;
    while(1){
       if(PORTDbits.RD0 == 0){
           --init;
           CCPR1L = init / 4;
           CCP1CONbits.DC1B = init % 4;
       }
    }
    return;
}
