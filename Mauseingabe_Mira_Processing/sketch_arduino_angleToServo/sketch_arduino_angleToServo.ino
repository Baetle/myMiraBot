#include <Servo.h>

// Read data from the serial port and set the position of a servomotor
// according to the value

Servo myservox;
Servo myservoy;

// Globale Variablen
int servoPinX = 3;  
int servoPinY = 9;               // Connect yellow servo wire to digital I/O pin 3 and 9 (must be PWM)

int valx = 90;
int valy = 90;  
int indexOfX; 
int indexOfY;               

String serialDataIn;
char c;


void setup() {
  myservox.attach(servoPinX);
  myservoy.attach(servoPinY);     // Attach the servo to the PWM pin
  Serial.begin(9600);            // Start serial communication at 9600 bps
}

void loop() {

  Recieve_Serial_Data();
  if (c == '\n') {
    Parse_the_Data();
    c=0;
    serialDataIn="";
  }

myservox.write(valx);
myservoy.write(valy);



}

void Recieve_Serial_Data() {
  while (Serial.available()>0) {
    
    c = Serial.read();
    Serial.println(c);
    if (c == '\n')  {break;}
    else            {serialDataIn+=c;}

  }
}

void Parse_the_Data() {
  String str_servoXdegree , str_servoYdegree;

  indexOfX = serialDataIn.indexOf("X");
  indexOfY = serialDataIn.indexOf("Y");
  
  if(indexOfX > -1) {
      str_servoXdegree = serialDataIn.substring(0, indexOfX);
      valx = str_servoXdegree.toInt();
  }
  if(indexOfY > -1) {
    str_servoYdegree = serialDataIn.substring(indexOfX+1, indexOfY);
    valy = str_servoYdegree.toInt();
  }
} 
  
