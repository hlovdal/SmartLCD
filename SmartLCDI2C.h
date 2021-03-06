/* FILE:    SMARTLCDI2C.h
   DATE:    12/07/17
   VERSION: 0.1
   AUTHOR:  Andrew Davies
   WEBSITE: HobbyComponents.com
   
12/07/17 version 0.1: Original version

Arduino I2C library for the Hobby Components Smart LCD.
Products currently supported by this library:

Hobby Components 1602 Smart LCD (HCMODU0122) available from hobbycomponents.com 

More information about this library can be found in the software section of our support 
forum here:

http://forum.hobbycomponents.com/software

You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of selling products that
directly compete with Hobby Components Ltd's own range of products.
THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.
*/


#ifndef SMARTLCDI2C_h
#define SMARTLCDI2C_h

#include <Wire.h>
#include "Arduino.h"


#define OFF				0	//Used to specify off state for some SmartLCD modes
#define ON				1	//Used to specify on state for some SmartLCD modes

#define LTOR			0	//Used to specify left to right cursor direction
#define RTOL			1	//Used to specify right to left cursor direction


//Keypad button values returned by SmartLCD.Button() function
#define KEYPAD_NONE 	0
#define KEYPAD_BACK 	1
#define KEYPAD_SELECT 	2
#define KEYPAD_RIGHT 	3
#define KEYPAD_DOWN		4
#define KEYPAD_UP 		5
#define KEYPAD_LEFT 	6

//Notes fore PlayNote() function
#define NOTE_C			0
#define NOTE_CS			1
#define NOTE_D			2
#define NOTE_DS			3
#define NOTE_E			4
#define NOTE_F			5
#define NOTE_FS			6
#define NOTE_G			7
#define NOTE_GS			8
#define NOTE_A			9
#define NOTE_A#			10
#define NOTE_B			11



//Bit masks used for the I2C status register
#define STATUS_BUSY		0b10000000
#define STATUS_ERROR	0b01000000
#define STATUS_BPS		0b00001000
#define STATUS_BUTTON	0b00000111


class SmartLCD
{
  public:
	SmartLCD(uint8_t I2C_Add);
	void init(void);
	void PrintChar(char Character);
	void Print(char *String);
	void Print(int Value);
	void Clear(void);
	void CurPos(uint8_t Row, uint8_t Col);
	void DispState(uint8_t State);
	void DispCursor(uint8_t State);
	void CursorBlink(uint8_t State);
	void Backlight(uint8_t Level);
	void PrintCustChar(uint8_t CharIndex);
	void DefCustChar(uint8_t CharIndex, uint8_t *Data);
	void CursorDir(uint8_t Dir);
	void I2CInit(void);
	void ClearButton(void);
	void PlayNote(uint8_t Note, uint8_t Time);
	void Address(uint8_t Address);
	void Contrast(uint8_t Level);
	void Version(void);
	void ClearError(void);
	void WaitBar(uint8_t Row, uint8_t Col, uint8_t Length, uint8_t Percent);
	
	boolean Busy(void);
	boolean Error(void);
	boolean ButtonState(void);
	uint8_t	Button(void);
	uint8_t ReadADC(void);
	uint8_t Status(void);
	


  private:
	byte _I2C_Add;
};

#endif