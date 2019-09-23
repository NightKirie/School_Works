LIST p=18f4520
#include<p18f4520.inc>
; CONFIG1H
  CONFIG  OSC = XT        ; Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
  CONFIG  FCMEN = OFF           ; Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
  CONFIG  IESO = OFF            ; Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

; CONFIG2L
  CONFIG  PWRT = OFF            ; Power-up Timer Enable bit (PWRT disabled)
  CONFIG  BOREN = SBORDIS       ; Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
  CONFIG  BORV = 3              ; Brown Out Reset Voltage bits (Minimum setting)

; CONFIG2H
  CONFIG  WDT = OFF             ; Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
  CONFIG  WDTPS = 32768         ; Watchdog Timer Postscale Select bits (1:32768)

; CONFIG3H
  CONFIG  CCP2MX = PORTC        ; CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
  CONFIG  PBADEN = ON           ; PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
  CONFIG  LPT1OSC = OFF         ; Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
  CONFIG  MCLRE = ON            ; MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

; CONFIG4L
  CONFIG  STVREN = ON           ; Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
  CONFIG  LVP = OFF             ; Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
  CONFIG  XINST = OFF           ; Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

; CONFIG5L
  CONFIG  CP0 = OFF             ; Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
  CONFIG  CP1 = OFF             ; Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
  CONFIG  CP2 = OFF             ; Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
  CONFIG  CP3 = OFF             ; Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

; CONFIG5H
  CONFIG  CPB = OFF             ; Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
  CONFIG  CPD = OFF             ; Data EEPROM Code Protection bit (Data EEPROM not code-protected)

; CONFIG6L
  CONFIG  WRT0 = OFF            ; Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
  CONFIG  WRT1 = OFF            ; Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
  CONFIG  WRT2 = OFF            ; Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
  CONFIG  WRT3 = OFF            ; Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

; CONFIG6H
  CONFIG  WRTC = OFF            ; Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
  CONFIG  WRTB = OFF            ; Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
  CONFIG  WRTD = OFF            ; Data EEPROM Write Protection bit (Data EEPROM not write-protected)

; CONFIG7L
  CONFIG  EBTR0 = OFF           ; Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR1 = OFF           ; Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR2 = OFF           ; Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR3 = OFF           ; Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

; CONFIG7H
  CONFIG  EBTRB = OFF           ; Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)
   ORG 0X00
TopCount:	equ	 0x0C
BotCount:	equ	 0x0D
LCount0:	equ	 0x10
LCount1:	equ	 0x11
LCount2:	equ	 0x12
LCount3:	equ	 0x13
LCount4:	equ	 0x14
LCount5:	equ	 0x15
LCount6:	equ	 0x16

blank:	macro
	bcf     PORTB, 1
	endm
point:	macro
	bsf     PORTB, 1
	endm

HSync:	macro
	bcf     PORTB, 3      ; horiz sync
	nop
	bsf     PORTB, 3      ; horiz sync
	endm

VSync:	macro
	bcf     PORTB, 4 	; vert sync
	nop
	nop
	nop
	nop
	nop
	bsf     PORTB, 4	; vert sync
	endm

	org	0
	goto	Start
	org     0x20            ; start address 0

Start:	
	;bsf	OSCCON, 6
	;bsf	OSCCON, 5
	;bcf	OSCCON, 4
	clrf    PORTB
	;movlb	0x01	; select bank 1
	clrf   	TRISB
	;movlb	0x00		; select bank 0
	bsf     PORTB, 4 	; vert sync
	

LoopV:	VSync			; 1-6

	blank      		; 1
	movlw   D'208'
	movwf   TopCount
	movwf   BotCount
	movlw   D'15'
	movwf   LCount0
	movwf   LCount1
	movwf   LCount2
	movwf   LCount3
	movwf   LCount4
	movwf   LCount5
	movwf   LCount6
				
BlankLoopTop:                   ; now, the blank area at the top
	blank      		; 1
	nop                     ; 2
	nop			; 3
	call    Delay10mkS     	; 4-13
	call    Delay10mkS     	; 14-23
	
	nop			; 24
	nop			; 25
	nop			; 26

	HSync                   ; 27-29

	decfsz  TopCount      	; 30
	goto    BlankLoopTop  	; 31
	nop			; 32 (207*32=6624)

	#include <text.inc>	; 7*15*32=3360
			      
BlankLoopBot:                   ;now, the blank area at the bottom
	blank      	      	; 1
	nop                   	; 2
	nop		      	; 3
	call    Delay10mkS    	; 4-13
	call    Delay10mkS    	; 14-23
	
	nop			; 24
	nop			; 25
	nop			; 26

	HSync		      	; 27-29

	decfsz  BotCount      	; 30
	goto    BlankLoopBot  	; 31

	goto    LoopV		; 32 (207*32=6624)

Delay10mkS:
	nop
	nop
	nop
	nop
	nop
	nop
	return

	end


