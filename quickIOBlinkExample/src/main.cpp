#include <Arduino.h>
/*
  QuickIO_Blink.ino

  Created by Baltimore Hackerspace 11/26/2016

  This is a simple sketch tutorial to demonstrate how to blink the LEDs on the QuickIO Shield. This sketch turns
  each LED on for a half second and then off. Then the next LED is lit in sequential order. This sketch makes use of
  a for loop for both the setup of the pins and also for the sequencing of the leds.  A variable (i) is
  initialized with the first LED pin number (2) and incremented until the loop reaches the last pin (9).

  QuickIO Pins:
  Green LEDs: 2 - 5
  Yellow LEDs: 6-7
  Red LEDs 8-9
*/


// the setup function runs one time when you press reset or power the board
void setup() {
  for (int i=2; i<=9; i++){  // loop from pin 2 to 9
    pinMode(i, OUTPUT);      // initialize all LEDs as digital outputs.
    digitalWrite(i, LOW);    // initialize all levels to LOW
  }
}

// the loop function runs forever
void loop() {
  for (int i=2; i<=9; i++){  // loop from pin 2 to 9
    digitalWrite(i, HIGH);   // i is a variable for the current pin, HIGH is the logic level.
    delay(500);              // wait for a 500 milliseconds
    digitalWrite(i, LOW);    // turn off the current LED by making the logic level LOW
  }
}
