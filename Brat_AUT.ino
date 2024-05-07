//Autonomous Brat code designed to avoid obstacles and wander
//Written for the BotBoarduino
//Robot kit from Lynxmotion
//Right Hip, Knee, Ankle on pins 12, 11, 10
//Left Hip, Knee, Ankle on pins 4, 3, 2
//Sensor used on pins 8, 9
//Onboard Speaker is used on pin 5
//Only Core libraries are used

#include <EEPROM.h>
#include "WriteReadAnything.h"
#include <Servo.h>
#include "Move_Data.h"

#define NUM_SERVOS 7
#define pingservo 5
#define RightHipPin 12
#define RightKneePin 11
#define RightAnklePin 10
#define LeftHipPin 4
#define LeftKneePin 3
#define LeftAnklePin 2


// Define pin assignments for Ping sensor
const int echoPin = 8;
const int trigPin = 9;

Servo ServoTable[NUM_SERVOS];  // Array to hold servo objects
int Offsets[NUM_SERVOS] = {0}; // Array to store offset values for each servo

struct PingSensor {
  int echoPin;
  int trigPin;
};

PingSensor pingSensor = {echoPin, trigPin};

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  // Attach servo objects to pins
  // order before top down of pins, 0 through 5.
  ServoTable[1].attach(RightHipPin);
  ServoTable[2].attach(RightKneePin);
  ServoTable[3].attach(RightAnklePin);
  ServoTable[4].attach(LeftHipPin);
  ServoTable[5].attach(LeftKneePin);
  ServoTable[6].attach(LeftAnklePin);
  ServoTable[7].attach(pingservo);

  pinMode(pingSensor.trigPin, OUTPUT);
  pinMode(pingSensor.echoPin, INPUT);



  // Load offsets from EEPROM
  LoadOffsets();
}


void LoadOffsets() {
  // Read offset values from EEPROM
  for (int i = 0; i < NUM_SERVOS; i++) {
    EEPROM.get(i * sizeof(int), Offsets[i]);
  }
}

void move (int duration){
  digitalWrite(5,HIGH);
  delay(duration);
  digitalWrite(5,LOW);
  delay(duration);
}
void pingSense() {
  // Perform ultrasonic sensor readings
  digitalWrite(pingSensor.trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingSensor.trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingSensor.trigPin, LOW);

  duration = pulseIn(pingSensor.echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println("distance: ");
  Serial.print(distance);
  Serial.println("inches");
  Serial.println();
  delay(400);

  // If an obstacle is detected, turn left
  if (distance < 30) { // Adjust the threshold value as needed
  Back_Up();

    }
  }


  void loop() {
  // Perform obstacle detection
  move(200);
  pingSense();
  Walk(8); // Walk forward with a step size of 8
  
  // Delay for stability and responsiveness
  delay(250);
}




