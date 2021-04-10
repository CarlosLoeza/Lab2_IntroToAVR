/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s

    unsigned char tmpA= 0x00; 
    unsigned char tmpC= 0x00;
    unsigned char pin_A0, pin_A1, pin_A2, pin_A3;

    while(1) {
	// 1) Read input
	tmpA = PINA & 0x0F;
	// 3) Write output
	pin_A0 = (tmpA & 0x01);
	pin_A1 = (tmpA & 0x02) >> 1;
	pin_A2 = (tmpA & 0x04) >> 2;
	pin_A3 = (tmpA & 0x08) >> 3;
	tmpC = pin_A0 + pin_A1 + pin_A2 + pin_A3; 
	
	if(tmpC == 4){
	    PORTC = tmpC | 0x80;
	} else {
	    PORTC = tmpC & 0x0F;
	}
    }
    return 0;
}
