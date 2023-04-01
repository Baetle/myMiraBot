// Variablen
const int SN_switchPin_L = 2;
const int SN_switchPin_R = 4;

int SN_switchState_L = 0;
int SN_switchState_R = 0;

#include <Servo.h>
Servo SN;
int angle;
int angle_befor;
int angle_step = 1;
int angle_delay = 0;

int SN_angle_max = 180;
int SN_angle_min = 0;

void setup() {
  pinMode(SN_switchPin_L, INPUT);
  pinMode(SN_switchPin_R, INPUT);

  Serial.begin(9600);

// Servo Initialisierung
  SN.attach(9);
  angle = 90;
  SN.write(angle);

}

void loop() {
  SN_switchState_L = digitalRead(SN_switchPin_L);
  SN_switchState_R = digitalRead(SN_switchPin_R);

  
  // rechts drehen
  if (SN_switchState_L == HIGH && SN_switchState_R != HIGH && angle <= SN_angle_max - angle_step) {
    angle = angle + angle_step;
    
  }
  // links drehen
  if (SN_switchState_R == HIGH  && SN_switchState_L != HIGH && angle >= SN_angle_min + angle_step) {
    angle = angle - angle_step;
  }

  if (angle != angle_befor) {
    Serial.print("Angle: ");
    Serial.println(angle);
    SN.write(angle);
    delay(angle_delay);
  }
  angle_befor = angle;
}
