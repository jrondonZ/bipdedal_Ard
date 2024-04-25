// #include <Arduino.h>


// #define period 10 // Time between each servo adjustment in microseconds

// extern Servo ServoTable[6];
// extern int Offsets[6];

// // Define gait parameters
// #define DUTY_CYCLE 0.5 // Percentage of gait cycle spent in swing phase


// float RHP = 90;
// float RKP = 90;
// float RAP = 90;
// float LHP = 90;
// float LKP = 90;
// float LAP = 90;

// boolean stepN;
// int last_angle = 90;
// int Speed = 400;

// void GroupMoveRight(int p1, int p2, int p3, int Speed) {
//   // Calculate servo movements for cyclic gait
//   // Adjust servo positions based on gait phase, step length, step height, and duty cycle
//   float ticks = Speed / period;
//   float RHS = (p1 - RHP) / ticks;
//   float RKS = (p2 - RKP) / ticks;
//   float RAS = (p3 - RAP) / ticks;


//   for (int x = 0; x < ticks; x++) {
//     RHP = RHP + RHS;
//     RKP = RKP + RKS;
//     RAP = RAP + RAS;


//     // Update servo positions
//     ServoTable[0].write(RHP + Offsets[0]);
//     ServoTable[1].write(RKP + Offsets[1]);
//     ServoTable[2].write(RAP + Offsets[2]);

//     // Delay for stability
//     delay(period);
//   }
// }

// void GroupMoveLeft(int p4, int p5, int p6, int Speed)
// {
//   float ticks = Speed / period;
//   float LHS = (p4 - LHP) / ticks;
//   float LKS = (p5 - LKP) / ticks;
//   float LAS = (p6 - LAP) / ticks;
//   for(int x = 0; x < ticks; x++)
//   {

//     LHP = LHP + LHS;
//     LKP = LKP + LKS;
//     LAP = LAP + LAS;

//     ServoTable[3].write(LHP + Offsets[3]);
//     ServoTable[4].write(LKP + Offsets[4]);
//     ServoTable[5].write(LAP + Offsets[5]);
//     delay(period);
//   }
// }

// void Walk(byte angle) {
//   // Calculate servo positions for swing phase
//   int servoPositionsSwingLeft[3] = {30, 60,last_angle};
//   int servoPositionsSwingRight[3] = {30, 60,last_angle};// Adjust as needed 3 was 55 and 6 was 75
//   //Calculate servo positions for stance phase (neutral position)
//   int servoPositionsStanceLeft[3] = {90,90,90};
//   int servoPositionsStanceRight[3] = {90,90,90}; // Adjust as needed
//   // Move through the gait cycle
//   for (int i = 0; i <= 2; i++) {
//     // Move servos for swing phase of the gait
//     GroupMoveLeft(servoPositionsSwingLeft[0], servoPositionsSwingLeft[1], servoPositionsSwingLeft[2],Speed);
//     delay(period);
//     GroupMoveRight(servoPositionsSwingRight[0], servoPositionsSwingRight[1], servoPositionsSwingRight[2],Speed);
    
//     // Delay for stability
//     delay(period);

//     // Move servos for stance phase of the gait
//     GroupMoveLeft(servoPositionsStanceLeft[0], servoPositionsStanceLeft[1], servoPositionsStanceLeft[2],Speed);
//     delay(period);
//     GroupMoveRight(servoPositionsStanceRight[0], servoPositionsStanceRight[1], servoPositionsStanceRight[2],Speed);
//     // Delay for stability
//     delay(period);
//   }

//   // Update last angle
//   last_angle = angle;
// }



//   void Turn_Left() {
//   // Define turning sequence
//   // Implement turning behavior based on the cyclic gait pattern

//   // For simplicity, let's just perform a half-step turn to the left
//   // Adjust servo positions for turning
//   int turningPositions[6] = {90, 90, 75, 90, 90, 75};

//   // Move servos to turning positions
//   for (int i = 0; i < 6; i++) {
//     ServoTable[i].write(turningPositions[i]);
//   }

//   // Delay for stability
//   delay(500); // Adjust duration as needed

//   // Return to neutral position
//   GroupMoveRight(90, 90, 90, 500);
//   GroupMoveLeft(90, 90, 90, 500); // Assuming 500ms duration for returning to neutral position
// }



