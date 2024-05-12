#include <Arduino.h>
#include "movment.h"

void setup() {
    Serial.begin(9600);


/**
* Bit masks for inputs and outputs:
* 
* 			        DDRD(0-7)		       DDRB(8-13)     
* not used: 0 1	            |   9             [14 15] Unusable
* output: 	    2 3 4 5 6 7 |     10 11 12 13 
* input:	    	            | 8	        
*
*/


  DDRD |= B11111100;     // set outputs
  DDRB |= B00111100; 
    
  DDRB &= ~B00000001;    // set inputs
}

void loop() {
  movment movment;

  movment.moveFoward(100,1000);

  delay(1000);

  movment.turnRight(90);

  delay(1000);

  movment.turnLeft(90);

  delay(995);

  movment.moveReverse(100,1000);

  while(1);

}
