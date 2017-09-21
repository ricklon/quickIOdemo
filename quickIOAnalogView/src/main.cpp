#include <Arduino.h>
/*
  QuickIO_Analog_VU.ino

  Created by Baltimore Hackerspace 11/26/2016

  This is a simple sketch tutorial to demonstrate how the analogRead function is used. In this example we read
  a value from the potentiometer between the values of 0 and 1023. This value is then scaled and inverted, using
  the map function, to values between 2 and 9. The result is a VU Meter which is set by the A4 potentiometer.

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
  int analogValue;                // create a place holder for the value read on pin A4
  int led_count;                  // holds a scaled value representing the highest LED

  analogValue = analogRead(A4);   // reads an analog value between 0 and 1023.

  /*
   * The map function scales the analog value to a number between 2 and 9. However, the
   * POT on QuickIO would seem backwards if you are use to the idea that turning to the
   * right would increase the value and turning to the left woul decrease the value. Therefore,
   * the map function is alsu used to invert this behaviour by making 0 = 9 and 1023 = 2.
   */
  led_count = map(analogValue,0,1023,9,2);

  for(int i = 2; i<=led_count; i++)
  {
    digitalWrite(i,HIGH); // Turn on all LEDs up to the max setpoint
  }
  for(int i = led_count + 1; i<=9; i++)
  {
    digitalWrite(i,LOW); // Turn off all LEDs after the setpoint upto the highest LED.
  }
}
