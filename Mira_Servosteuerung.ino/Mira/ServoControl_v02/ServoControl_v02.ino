// ToDos
// - Geschwindigkeits-Input
// - Servo 2
// - Servo 3

//Library Import
#include "PWM.hpp"

// Variablen
/// Servo_SN
PWM SN_speed(3);
const int SN_switchPin_L = 2;
const int SN_switchPin_R = 4;

int SN_switchState_L = 0;
int SN_switchState_R = 0;
int SN_speedRead = 0;

#include <Servo.h>
Servo SN;
float angle;
float angle_befor;
float angle_step = 0.5;
float angle_delay = 0;

int SN_angle_max = 125;
int SN_angle_min = 55;

void setup() {
  pinMode(SN_switchPin_L, INPUT);
  pinMode(SN_switchPin_R, INPUT);

  Serial.begin(9600);

// Servo Initialisierung
  SN_speed.begin(true);
  SN.attach(9);
  angle = 90;
  SN.write(angle);

}

void loop() {
  SN_switchState_L = digitalRead(SN_switchPin_L);
  SN_switchState_R = digitalRead(SN_switchPin_R);
  SN_speedRead = SN_speed.getValue();
  angle_step = map(SN_speedRead,270, 19900, 1, 25);
  
  // rechts drehen
  if (SN_switchState_L == HIGH && SN_switchState_R != HIGH && angle <= SN_angle_max - angle_step) {
    angle = angle + angle_step;
    
  }
  // links drehen
  if (SN_switchState_R == HIGH  && SN_switchState_L != HIGH && angle >= SN_angle_min + angle_step) {
    angle = angle - angle_step;
  }

  if (angle != angle_befor) {
    SN.write(angle);
    delay(angle_delay);
  }
  angle_befor = angle;
  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print("\tSpeed: ");
  Serial.print(SN_speedRead);
  Serial.print("\tAngle Step: ");
  Serial.println(angle_step);
}
