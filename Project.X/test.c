//
// vga_test.c - create first VGA frame
//
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pic18f4550.h>

// CONFIG1
#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config PWRT = ON
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config BOREN = ON
#pragma config CLKOUTEN = OFF
#pragma config FCMEN = ON

// CONFIG2
#pragma config WRT = ALL
#pragma config PPS1WAY = OFF
#pragma config ZCDDIS = ON
#pragma config PLLEN = ON
#pragma config STVREN = OFF
#pragma config BORV = LO
#pragma config LPBOR = OFF
#pragma config LVP = ON

//
// h/w interface definition
//
#define REG_OE_bar 0b00010000
#define WE_bar     0b00000001
#define OE_bar     0b00000010
#define CP_en      0b00001000
#define MR_en      0b00100000
#define CP_bar     0b00000100
#define MR_bar     0b00010000

#define VSYNC 0b10000000
#define HSYNC 0b01000000
#define RGB(r, g, b) (((r) << 4) | ((g) << 2) | (b))

#if 0 // manually inlined below to save 4 instructions
void SetupPeripherals() {
  // intosc 32 MHz
  OSCCON = 0b11110000;

  // select digital I/O
  ANSELA = 0;
  ANSELB = 0;
  ANSELC = 0;

  // set TRIS bits: all outputs
  PORTA = 0x00;
  TRISA = 0x00;
  PORTB = 0x00;
  TRISB = 0x00;
  PORTC = 0x00;
  TRISC = 0x80;
}
#endif

//
// set control lines for free-running VGA signal generation
//
void RunMode()
{
  TRISC = 0xff; // data lines all inputs
  // reset address counter, then let it rip
  LATB = WE_bar | OE_bar&0 | CP_en&0 | CP_bar&0 | MR_en   | MR_bar   ;
  LATB = WE_bar | OE_bar&0 | CP_en&0 | CP_bar&0 | MR_en&0 | MR_bar&0 ;
  LATA = REG_OE_bar&0;
}

//
// set control lines for bitbanging waveforms into SRAM, and
//   reset SRAM address counter to 0
//
void LoadMode()
{
  LATA = REG_OE_bar;
  // toggle CP with MR low to reset address counter
  LATB = WE_bar | OE_bar | CP_en | CP_bar   | MR_en | MR_bar   ;
  LATB = WE_bar | OE_bar | CP_en | CP_bar&0 | MR_en | MR_bar   ;
  LATB = WE_bar | OE_bar | CP_en | CP_bar   | MR_en | MR_bar   ;
  // bring out of reset
  LATB = WE_bar | OE_bar | CP_en | CP_bar   | MR_en | MR_bar&0 ;
  TRISC = 0x00; // data lines all outputs
}

//
// bitbang a number of identical bytes into sequential SRAM addresses
//
void write_SRAM_bytes(uint8_t value, uint8_t count)
{
  PORTC = value;
  LATB = WE_bar | OE_bar | CP_en | CP_bar | MR_en | MR_bar&0 ;
  do {
    // toggle WE to write data
    LATB = WE_bar&0 | OE_bar | CP_en | CP_bar   | MR_en | MR_bar&0 ;
    LATB = WE_bar   | OE_bar | CP_en | CP_bar   | MR_en | MR_bar&0 ;
    // toggle CP to advance address
    LATB = WE_bar   | OE_bar | CP_en | CP_bar&0 | MR_en | MR_bar&0 ;
    LATB = WE_bar   | OE_bar | CP_en | CP_bar   | MR_en | MR_bar&0 ;
  } while (--count);
}

void GenerateLine(uint8_t vsync, uint8_t rgb, uint8_t count)
{
  do {
    write_SRAM_bytes( vsync | HSYNC   | rgb&0 , 16);  // front porch
    write_SRAM_bytes( vsync | HSYNC&0 | rgb&0 , 96);  // sync pulse
    write_SRAM_bytes( vsync | HSYNC   | rgb&0 , 48);  // back porch
    write_SRAM_bytes( vsync | HSYNC   | rgb   , 200); // video
    write_SRAM_bytes( vsync | HSYNC   | rgb   , 200); // video
    write_SRAM_bytes( vsync | HSYNC   | rgb   , 240); // video
  } while (--count);
}

#define S 12
#define FP(x) ((int16_t)((x) * (1<<S)))

//#define WHOLE_SET

#ifdef WHOLE_SET
#define ASPECT   (640./480.)
#define WIDTH     2.5
#define IMAG_MIN  FP(-1.25)
#define IMAG_STEP FP(WIDTH / 480.)
#define REAL_MIN  FP(-2.5)
#define REAL_STEP FP(ASPECT * WIDTH / 640.)
#define ESCAPE_RADIUS FP(4.)
#define MAXITER   255
#else
#define ASPECT   (640./480.)
#define WIDTH     0.125
#define IMAG_MIN  FP(-.0625)
#define REAL_MIN  FP(-1.5)
#define IMAG_STEP FP(WIDTH / 480.)
#define REAL_STEP FP(ASPECT * WIDTH / 640.)
#define ESCAPE_RADIUS FP(4.)
#define MAXITER   255
#endif

void GenerateFrame()
{
  GenerateLine( VSYNC   , 0,  33);  // V back porch

  int16_t dc = REAL_STEP;
  int16_t dd = IMAG_STEP;
  int16_t d = IMAG_MIN;  
  int16_t row = 480;
  do {
    write_SRAM_bytes( VSYNC | HSYNC   | 0 , 16);  // H front porch
    write_SRAM_bytes( VSYNC | HSYNC&0 | 0 , 96);  // H sync pulse
    write_SRAM_bytes( VSYNC | HSYNC   | 0 , 48);  // H back porch

    int16_t c = REAL_MIN;
    int16_t col = 640;
    do {
      int16_t a = 0;
      int16_t b = 0;
      uint8_t iter = MAXITER;
      do {
        int32_t aa32 = ((int32_t)a * (int32_t)a);
        if (aa32 & 0xf8000000){
          break;
        }
        int16_t aa = aa32 >> S;

        int32_t bb32 = ((int32_t)b * (int32_t)b);
        if (bb32 & 0xf8000000){
          break;
        }
        int16_t bb = bb32 >> S;

        if (aa > ESCAPE_RADIUS ||
            bb > ESCAPE_RADIUS ||
            aa + bb > ESCAPE_RADIUS){
          break;
        }
        b = (((int32_t)a * (int32_t)b) >> (S-1)) + d;
        a = aa - bb + c;
      } while(--iter);

      uint8_t red, green, blue;
      red = (iter & 3);
      green = ((iter & 0x0c) >> 2);
      blue = ((iter & 0x30) >> 4);
      write_SRAM_bytes( VSYNC | HSYNC   | RGB(red, green, blue), 1); // one pixel

      c += dc;
    } while (--col);
    d += dd;
  } while (--row);

  GenerateLine( VSYNC   , 0,  10);  // V front porch
  GenerateLine( VSYNC&0 , 0,  2);   // V sync pulse
  write_SRAM_bytes( VSYNC | HSYNC | 0, 2);     // end of vsync; resets counter
}

int main() {

  // this call inlined here to shave off instructions
  // SetupPeripherals();

  // intosc 32 MHz
  OSCCON = 0b11110000;

  // select digital I/O
  ANSELA = 0;
  ANSELB = 0;
  ANSELC = 0;

  // set TRIS bits: all outputs
  PORTA = 0x00;
  TRISA = 0x00;
  PORTB = 0x00;
  TRISB = 0x00;
  PORTC = 0x00;
  TRISC = 0x80;

  LoadMode();
  GenerateFrame();
  RunMode();

  while(1){
    continue;
  }

  return 0;
}
