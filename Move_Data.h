#include <Arduino.h>

#define period 10 //time between each servo adjustment in Microseconds

extern Servo ServoTable[7];
extern int Offsets[7];


float RHP = 90;
float RKP = 90;
float RAP = 90;
float LHP = 90;
float LKP = 90;
float LAP = 90;
float PMP = 90;

boolean stepN;
int last_angle = 90;
int Speed = 500;

void GroupMove(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int Speed)
{
  float ticks = Speed / period;
  float RHS = (p1 - RHP) / ticks;
  float RKS = (p2 - RKP) / ticks;
  float RAS = (p3 - RAP) / ticks;
  float LHS = (p4 - LHP) / ticks;
  float LKS = (p5 - LKP) / ticks;
  float LAS = (p6 - LAP) / ticks;
  float PMS = (p7 - PMP) / ticks;
  for(int x = 0; x < ticks; x++)
  {
    RHP = RHP + RHS;
    RKP = RKP + RKS;
    RAP = RAP + RAS;
    LHP = LHP + RHS;
    LKP = LKP + LKS;
    LAP = LAP + LAS;
    PMP = PMP + PMS;
    ServoTable[0].write(RHP + Offsets[0]);
    ServoTable[1].write(RKP + Offsets[1]);
    ServoTable[2].write(RAP + Offsets[2]);
    ServoTable[3].write(LHP + Offsets[3]);
    ServoTable[4].write(LKP + Offsets[4]);
    ServoTable[5].write(LAP + Offsets[5]);
    ServoTable[6].write(PMP + Offsets[6]);


    delay(period);
  }
}



void Walk(byte angle)
{
 if(stepN)
  {
    angle = 80 + angle;

    GroupMove(last_angle, 100, 90, 95, 90, 45, 40, Speed);
    GroupMove(last_angle, 105, 90, 55, 105, 95, 20, Speed);
    GroupMove(last_angle, 110, 90, 110, 90, 90, 60, Speed);
    stepN = !stepN;
  }
  else
  {
    angle = 80 - angle;

    GroupMove(last_angle, 100, 90, 75, 100, 75, 60, Speed);
    GroupMove(last_angle, 105, 90, 75, 105, 90, 20, Speed);
    GroupMove(last_angle, 110, 90, 75, 110, 90, 40, Speed);
    stepN = !stepN;
  }
  last_angle = angle;
}



// void Aim_Down()
// {
//   GroupMove(95, 80, 80, 90, 120, 100, 90, 500);
// }

void Back_Up()
{
    //GroupMove(100, 20, 100, 95, last_angle, 90,100, Speed);
    GroupMove(last_angle, 95, 90, 90, 90, 70, 60, Speed);
    GroupMove(last_angle, 95, 90, 75, 90, 85, 80, Speed);
    GroupMove(last_angle, 95, 90, 90, 90, 70, 40, Speed);

}





