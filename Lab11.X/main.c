#include "setting_hardaware/setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#define C4 261u
#define D4 293u
#define E4 329u
#define F4 349u
#define G4 392u
#define A4 440u
#define B4 4493u
#define C5 523u
#define D5 587u
#define E5 659u
#define F5 698u
#define G5 783u
#define A5 880u
#define B5 987u
int tone[2][30] = {{G5, E5, E5, 0, F5, D5, D5, 0, C5, D5, E5, F5, G5, G5, G5, 0, G5, E5, E5, 0, F5, D5, D5, 0, C5, E5, G5, G5, E5, 0 },
                    {E4, G4, A4, A4, 0, A4, B4, C5, C5, 0, C5, D5, B4, B4, 0, A4, G4, A4, 0 }};
int tempo[2][30] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1,1,2,1,1,1,1,2,1,1,1,1,2,1,1,1,1,3,1}};
int length[2] = {30, 19};
int music_count = 0;
int music_index = 0;
int music_choose = 0;
int led_num = 0;
int led_interval = 0;
int led_loop = 0;
int music_playing = 0;
int led_breath = 0;
int updown = 0;
int led_mode = 0;
char str[10];

void __interrupt() tc_int(void)
{
    if(PIR1bits.TMR1IF){
        if(music_count==tempo[music_choose][music_index]){
            music_count=0;
            music_index++;
            if(tone[music_choose][music_index] == 0)
                T2CONbits.TMR2ON = 0;
            else{
                T2CONbits.TMR2ON = 1;
                PR2 = 62500/tone[music_choose][music_index];
                CCPR2L = PR2*2/4;
                CCP2CONbits.DC2B = PR2*2%4;
            }
        }
        if(music_index == length[music_choose])
            music_index = 0;
        music_count++;
        TMR1 = 34285;
        PIR1bits.TMR1IF =0;
    }
    else if(PIR2bits.TMR3IF) {
        if(led_mode == 0){
            if(led_loop == 0) {
                if(led_num == 1){
                    RC2 = !RC2;
                }
                else if(led_num == 2){
                    RC2 = !RC2;
                    RD5 = !RD5;
                }
                else if(led_num == 3){
                    RC2 = !RC2;
                    RD5 = !RD5;
                    RD6 = !RD6;
                }
                else if(led_num == 4){
                    RC2 = !RC2;
                    RD5 = !RD5;
                    RD6 = !RD6;
                    RD7 = !RD7;
                }
                led_loop = led_interval;
            }
            --led_loop;
            PIR2bits.TMR3IF = 0;
            TMR3 = 34285;
        }
        else if(led_mode){
            if(led_breath == 0)
                updown = 0;
            else if (led_breath == PR2){
                updown = 1;
            }
            if(updown == 0)
                ++led_breath;
            else if(updown == 1)
                --led_breath;
            CCPR1L = led_breath*2/4;
            CCP1CONbits.DC1B = led_breath*2%4;
            PIR2bits.TMR3IF = 0;
            TMR3 = 1000;
        }
    }
}


void Mode1() 
{
    ClearBuffer();
    led_mode = 0;
    UART_Write_Text("Mode1 ");
    T3CONbits.RD16 = 1;
    T3CONbits.T3CKPS = 3;
    T3CONbits.TMR3CS = 0;
    PIR2bits.TMR3IF = 0;
    PIE2bits.TMR3IE = 1;
    IPR2bits.TMR3IP = 1;
    TMR3 = 34285;
    while(1){
        if(strstr(GetString(), "1") != NULL) {
            led_num = 1;
            TRISCbits.RC2 = 0;
            RC2 = 0;
            ClearBuffer();
            break;
        }
        else if(strstr(GetString(), "2") != NULL) {
            led_num = 2;
            TRISCbits.RC2 = 0;
            RC2 = 0;
            TRISDbits.RD5 = 0;
            RD5 = 0;
            ClearBuffer();
            break;
        }
        else if(strstr(GetString(), "3") != NULL) {
            led_num = 3;
            TRISCbits.RC2 = 0;
            RC2 = 0;
            TRISDbits.RD5 = 0;
            RD5 = 0;
            TRISDbits.RD6 = 0;
            RD6 = 0;
            ClearBuffer();
            break;
        }
        else if(strstr(GetString(), "4") != NULL) {
            led_num = 4;
            TRISCbits.RC2 = 0;
            RC2 = 0;
            TRISDbits.RD5 = 0;
            RD5 = 0;
            TRISDbits.RD6 = 0;
            RD6 = 0;
            TRISDbits.RD7 = 0;
            RD7 = 0;
            ClearBuffer();
            break;
        }   
    }
    while(1){
        if(strstr(GetString(), "1") != NULL){
            led_interval = 1;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        }
        else if(strstr(GetString(), "2") != NULL){
            led_interval = 2;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        } 
        else if(strstr(GetString(), "3") != NULL){
            led_interval = 3;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        } 
        else if(strstr(GetString(), "4") != NULL){
            led_interval = 4;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        } 
        else if(strstr(GetString(), "5") != NULL){
            led_interval = 5;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        } 
        else if(strstr(GetString(), "6") != NULL){
            led_interval = 6;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        } 
        else if(strstr(GetString(), "7") != NULL){
            led_interval = 7;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        } 
        else if(strstr(GetString(), "8") != NULL){
            led_interval = 8;
            T3CONbits.TMR3ON = 1;
            ClearBuffer();
            break;
        } 
    }
    while(1){
        if(strstr(GetString(), "q") != NULL) {
            if(led_num == 1){
                RC2 = 0;
            }
            else if(led_num == 2){
                RC2 = 0;
                RD5 = 0;
            }
            else if(led_num == 3){
                RC2 = 0;
                RD5 = 0;
                RD6 = 0;
            }
            else if(led_num == 4){
                RC2 = 0;
                RD5 = 0;
                RD6 = 0;
                RD7 = 0;
            }
            T3CONbits.TMR3ON = 0;
            PIR2bits.TMR3IF = 0;
            PIE2bits.TMR3IE = 0;
            IPR2bits.TMR3IP = 0;
            led_num = 0;
            led_interval = 0;
            ClearBuffer();
            break;
        }
    }
    ClearBuffer();
}

void Mode2() { // Output Voltage 
    ClearBuffer();
    led_mode = 1;

    UART_Write_Text("Mode2");

    CCP1CONbits.DC1B = 0;
    CCP1CONbits.CCP1M = 1100;
    CCP1CONbits.P1M = 3;
    TRISCbits.RC2 = 0;
    TRISDbits.RD5 = 0;
    TRISDbits.RD6 = 0;
    TRISDbits.RD7 = 0;

    if(music_playing == 0){
        T2CONbits.TMR2ON = 1;
        T2CONbits.T2CKPS = 3;
        CCPR2L = 0;
        CCP2CONbits.DC2B = 0;
        PR2 = 10000;
    }
    led_breath = PR2;
    //T3CONbits.TMR3ON = 1;
    while(1){
        float interval =  ((float)5/1023)*ADC_Read(0);
        if(updown == 0)
            led_breath+=interval;
        else if(updown == 1)
            led_breath-=interval;
        if(led_breath <= 0){
            updown = 0;
            led_breath = 0;
        }
        else if (led_breath >= PR2){
            updown = 1;
            led_breath = PR2;
        }
        
        CCPR1L = led_breath*2/4;
        CCP1CONbits.DC1B = led_breath*2%4;
        if(strstr(GetString(), "q") != NULL) {
            if(music_playing == 0)
                T2CONbits.TMR2ON = 0;
            CCPR1L = 0;
            CCP1CONbits.DC1B = 0;
            ClearBuffer();
            break;
        }
    }
    ClearBuffer();
}

void Mode3() {
    ClearBuffer();
    TRISCbits.RC1 = 0;
    T2CONbits.T2CKPS = 3;
    CCP2CONbits.CCP2M = 12;
    PIE1bits.TMR1IE =1;
    PIR1bits.TMR1IF =0;
    IPR1bits.TMR1IP =1;
    T1CONbits.RD16 = 1;
    T1CONbits.T1CKPS = 3;
    T1CONbits.TMR1CS = 0;
    TMR1 = 34285;
    ClearBuffer();
    while(1){
        if(strstr(GetString(), "1") != NULL){
            T2CONbits.TMR2ON = 1;
            T1CONbits.TMR1ON = 1;
            music_choose = 0;
            music_count = 0;
            music_index = 0;
            ClearBuffer();
            break;
        }
        else if(strstr(GetString(), "2") != NULL){
            T2CONbits.TMR2ON = 1;
            T1CONbits.TMR1ON = 1;
            music_choose = 1;
            music_count = 0;
            music_index = 0;
            ClearBuffer();
            break;
        }
    }
    ClearBuffer();
    while(1){
        if(strstr(GetString(), "q") != NULL) {
            T2CONbits.TMR2ON = 0;
            T1CONbits.TMR1ON = 0;
            music_count = 0;
            music_index = 0;
            ClearBuffer();
            break;
        }
    }
}

void Playmusic(){
    ClearBuffer();
    TRISCbits.RC1 = 0;
    T2CONbits.T2CKPS = 3;
    OSCCONbits.IRCF = 6;
    CCP2CONbits.CCP2M = 12;
    RCONbits.IPEN = 1;
    PIE1bits.TMR1IE =1;
    PIR1bits.TMR1IF =0;
    IPR1bits.TMR1IP =1;
    INTCONbits.GIE =1;
    T1CONbits.RD16 = 1;
    T1CONbits.T1CKPS = 3;
    T1CONbits.TMR1CS = 0;
    T2CONbits.TMR2ON = 1;
    T1CONbits.TMR1ON = 1;
    music_choose = 0;
    music_count = 0;
    music_index = 0;
    music_playing = 1;
    TMR1 = 34285;
    ClearBuffer();
}

void Stopmusic(){
    ClearBuffer();
    T2CONbits.TMR2ON = 0;
    T1CONbits.TMR1ON = 0;
    music_count = 0;
    music_index = 0;
    music_playing = 0;
    ClearBuffer();
}

void main(void) 
{
    SYSTEM_Initialize() ;
    while(1) {
        if(strstr(GetString(), "clear") != NULL)
            ClearBuffer();
        else if(!strcmp(GetString(), "blink"))
            Mode1();
        else if(!strcmp(GetString(), "breath"))
            Mode2();
        else if(!strcmp(GetString(), "music"))
            Mode3();
        else if(!strcmp(GetString(), "p")) 
            Playmusic();
        else if(!strcmp(GetString(), "s")) 
            Stopmusic();
    }
    return;
    
}
