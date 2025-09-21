#include "motors.h"
#include "timers.h"
#include <stdlib.h>
#include <string.h>

int stepPin = 2;
bool debugPrint = true;
int resetPin = 7;

void setup() {
  // init the communication to the loom
  init_mcp23017();
  write_dir();
  write_enable();

  //set up reset pin
  pinMode(resetPin, INPUT_PULLUP);
  resetTimer.start();

  // Set up step pin
  pinMode(stepPin, OUTPUT);
  // Set frequency of step pin (2) to about 4k Hz
  TCCR3B = TCCR3B & B11111000 | B00000010; // for PWM frequency of 4 kHz use 2 as prescaler
  // Set the step pin’s duty cycle to half (127)
  analogWrite(stepPin, 127);

  //Write all motors disabled and direction to begin

  // begin serial communication
  Serial.begin(115200);
}

void loop() {
  check_serial();
  check_timers();

  //check reset
  reset_motors();
  
}

int resetVal = 1;
int resetPrev = 1;

void reset_motors() {
  resetVal = digitalRead(resetPin);
  if (!resetVal && resetVal!=resetPrev && resetTimer.ding()) {
    resetTimer.reset();
    resetTimer.start();
    Serial.println("Reset");
    resetPrev = resetVal;
    move_all_down();
  } else {
    resetPrev = resetVal;
  }
}
