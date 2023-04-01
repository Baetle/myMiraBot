// Write data to the serial port according to the mouseX value

import processing.serial.*;

Serial port;                      // Create object from Serial class
float mx = 0.0;
float my = 0.0;

void setup() {
  size(200, 200);
  noStroke();
  frameRate(10);
  // Open the port that the board is connected to and use the same speed (9600 bps)
//  port = new Serial(this, 9600);  // Comment this line if it's not the correct port
  // If the above does not work uncomment the lines below to choose the correct port
  // List all the available serial ports, preceded by their index number:
  //printArray(Serial.list());
  // Instead of 0 input the index number of the port you are using:
  //port = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  // ---- First Marker
  background(0);  // Clear background
  fill(204);      // Set fill color
  
  rect(40, height - 55, 120, 25);       // Draw square

  float dif = mouseX - mx;
  if (abs(dif) > 1.0) {
    mx += dif/4.0;
  }
  mx = constrain(mx, 50, 149);                // Keeps marker on the screen
  noStroke();
  fill(255);
  rect(50, height-45, 100, 5);
  fill(204, 102, 0);

  rect(mx-2, height-45, 4, 5);               // Draw the position marker
  int angle = int(map(mx, 50, 149, 0, 180));  // Scale the value to the range 0-180
  

// ----- Second Marker
 fill(204);      // Set fill color
 rect(width/2 - 12, 10, 25, 120);      // Draw second square
 
 float dif2 = mouseY - my;
  if (abs(dif2) > 1.0) {
    my += dif2/4.0;
  }
  my = constrain(my, 20, 119);                // Keeps marker on the screen
  noStroke();
  fill(255);
  rect(width/2-2, 20, 5, 100);
  fill(204, 102, 0);

  rect(width/2-2, my-2, 5, 4);               // Draw the position marker
  int angle2 = int(map(my, 20, 119, 0, 180));  // Scale the value to the range 0-180
 
 // ---- Print Results

 print(angle + " ");                       // Print the current angle (debug)
 // port.write(angle);     // Write the angle to the serial port


 println(angle2 + " ");                       // Print the current angle (debug)
 // port.write(angle2);     // Write the angle to the serial port
 

}
