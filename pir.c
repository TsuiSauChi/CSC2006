#include <stdio.h>
#include <string.h>
#define PERIOD 60000 

// Outside PIR
int pin1 = 12;
int pin1Value = 0;

// Inside PIR
int pin2 = 11;
int pin2Value = 0;

// Timer Variables
int temp_starttime = 0;
int temp_endtime = 0;
int program_starttime = 0;
int program_endtime = 0;

// Counter 
int counterWalkIn = 0;
int counterWalkOut = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  program_starttime = millis();
  program_endtime = program_starttime;

  // Hardcoded for 1 minute
  while ((program_endtime - program_starttime) <= PERIOD) {
    program_endtime = millis();
    
    pin1Value = digitalRead(pin1);
    pin2Value = digitalRead(pin2);
  
    // Walking in 
    if (pin1Value == 1 && pin2Value == 0) {
      temp_starttime = millis();
      temp_endtime = temp_starttime;
  
      while ((temp_endtime - temp_starttime) <= 2000) {
        temp_endtime = millis();
        pin1Value = digitalRead(pin1);
        pin2Value = digitalRead(pin2);
        if (pin1Value == 1 && pin2Value == 1) {
          Serial.println("Walking in");
          counterWalkIn += 1;
          delay(4000);
        } else {
          // Insert Logic here
        }
      }
      Serial.println("TESTINGTESTINGTESTING");
    }
  
  // Walking in 
    if (pin1Value == 0 && pin2Value == 1) {
      temp_starttime = millis();
      temp_endtime = temp_starttime;
  
      while ((temp_endtime - temp_starttime) <= 2000) {
        temp_endtime = millis();
        pin1Value = digitalRead(pin1);
        pin2Value = digitalRead(pin2);
        if (pin1Value == 1 && pin2Value == 1) {
          Serial.println("Walking out");
          counterWalkOut += 1;
          delay(4000);
        } else {
          // Insert Logic here
        }
      }
      Serial.println("TESTINGTESTINGTESTING");
    } 
  }

  Serial.println("One Minute Ended");
  Serial.print("Counter Walk in: ");
  Serial.print(counterWalkIn);
  Serial.println("");
  Serial.print("Counter Walk out: ");
  Serial.print(counterWalkOut);
  Serial.println("");

  counterWalkIn = 0;
  counterWalkOut = 0;
}