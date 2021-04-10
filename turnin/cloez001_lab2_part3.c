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
    unsigned char cntavail= 0x00;

    while(1) {
	tmpA = PINA & 0x0F;

        // no parking spots taken
        if (tmpA == 0x00){
            cntavail = 0x84;
        } // one spot taken
        else if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08){
            cntavail = 0x03;
        } //two spots taken
        else if (tmpA == 0x03 || tmpA == 0x06 || tmpA == 0x0C || tmpA == 0x05 || tmpA == 0x09 || tmpA == 0x0A){
                cntavail = 0x02;
        } // three spots taken
        else if(tmpA ==  0x07 || tmpA == 0x0B || tmpA == 0x0D || tmpA == 0x0E){
            cntavail = 0x01;
        } // four spots taken
        else{
            cntavail = 0x00;
        }
        // result/output
        PORTC = cntavail;
    }
    return 0;
}
