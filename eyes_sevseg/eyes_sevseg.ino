#include "SevSeg.h"
SevSeg sevseg; //Initiate controller object

float randomTime = 48000;

int checkState = 1;

void setup() {
    byte numDigits = 4;  
    byte digitPins[] = {10, 11, 12, 13};
    byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
    bool resistorsOnSegments = 0; 
    // variable above indicates that 4 resistors were placed on the digit pins.
    // set variable to 1 if you want to use 8 resistors on the segment pins.
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(20);
}

void rolleyes() {
  for (int i = 0; i <= 14; i++) {
      sevseg.setChars(" oo ");
      //sevseg.setNumber(3141, 4);
      sevseg.refreshDisplay(); // Must run repeatedly

      delay(200);
  }
}

void eyesopen(){

  for (float i = 0; i <= randomTime; i++) {
    sevseg.setChars("0 . 0");
    sevseg.refreshDisplay();


  }

}

void eyesblink(){

  for (float i = 0; i <= 3000; i++) {
    sevseg.setChars("- . -");
    sevseg.refreshDisplay();
  }

}
    




void loop() {
  //rolleyes();
  eyesopen();
  eyesblink();
  randomTime = (random(86, 400)* 1000);
    
}
     