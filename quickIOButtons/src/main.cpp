#include <Arduino.h>
/*
  QuickIO_Button.ino

  Created by Baltimore Hackerspace 11/26/2016

  This is a simple sketch tutorial to demonstrate how to toggle an LED on the QuickIO Shield with the press of a button.
  This sketch turns on a single LED if a button is pressed and turns it off again if the button is released. With more
  complex circuits it often makes more sense to handle button detection using interrupts so don't get too comfortable
  with this method of handling button press events.

  QuickIO Pins:
  Green LEDs: 2 - 5
  Yellow LEDs: 6-7
  Red LEDs 8-9

  Button A0
  Button A1
  Button A2
  Button A3
*/

/*
 *  It can be confusing to remember if a logic HIGH equates to an LED that's ON or a button that is PRESSED. Likewise, it
 *  can be hard to remember which pin goes to which peripheral. For that reason here we will create symbols which are more
 *  meaningful.
 */

 // Peripherals
 const int BUTTON = A0; // Creates a Symbol called BUTTON for the button on pin A0
 const int LED = 2;     // Creates a Symbol called LED for the LED on pin 2

 // LED States
 const int LED_ON = HIGH;
 const int LED_OFF = LOW;

 // Button States
 const int BUTTON_PRESSED = LOW;
 const int BUTTON_RELEASED = HIGH;

void setup() {
  pinMode(LED,OUTPUT);           // setup the LED pin as an output
  pinMode(BUTTON,INPUT);         // Setup button pin as Inputs.
  digitalWrite(LED, LED_OFF);    // initialize LED pin to OFF
}

void loop() {
  if(digitalRead(BUTTON) == BUTTON_PRESSED)   // If the Button is pressed
  {
    digitalWrite(LED,LED_ON);                 // Turn the LED ON
  }else{                                      // otherwise
    digitalWrite(LED,LED_OFF);                // Turn the LED OFF
  }
}
