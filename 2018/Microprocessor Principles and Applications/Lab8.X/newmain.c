#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP =OFF
#include <xc.h>
void LED0(void);
void LED1(void);
void LED2(void);
void LED3(void);
void turnoff(void);
volatile int count = 0;
void main(void) {
    TRISD =0;
    LATD =0;
    T2CON = 0x7f;
    RCONbits.IPEN= 1;
    PIE1bits.TMR2IE =1;
    PIR1bits.TMR2IF =0;
    IPR1bits.TMR2IP =1;
    INTCONbits.GIE =1;
    PR2 = 0xf3;
    while(1);
    return;
}

void __interrupt() tc_int(void)
{
    if(TMR2IE && TMR2IF){
        count++;
    }
    if(count == 8){ // 2 sec
        LED0();
    }
    if(count == 16){
        LED1();
    }
    if(count == 24){
        LED2();
    }
    if(count == 32){
        LED3();
    }
    if(count == 40){
        turnoff();
    }
    if(count == 44){
        count = 7;
    }
    TMR2 = 0x00;
    PIR1bits.TMR2IF =0;
}
void LED0(void){
    LATDbits.LATD0 =1;
}
void LED1(void){
    LATDbits.LATD1 =1;   
}
void LED2(void){
    LATDbits.LATD2 =1;
}
void LED3(void){
    LATDbits.LATD3 =1;
}
void turnoff(void){
    LATD = 0;
}