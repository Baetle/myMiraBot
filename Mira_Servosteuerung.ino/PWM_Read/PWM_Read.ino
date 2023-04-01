#include "PWM.hpp"

PWM my_pwm(3);

void setup() {
    Serial.begin(115200);
    my_pwm.begin(true); 

}

void loop() {
    Serial.print("Value: ");
    Serial.print(my_pwm.getValue());
    Serial.print("\tAGE: ");
    Serial.println(my_pwm.getAge());
    delay(100);
}
