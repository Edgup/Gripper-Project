
 #include <Servo.h>

char app_value = 0; // Variable for apps response of button clicks

Servo servo1; // Servo Object
int servo1_pin = 13;  // Servos pin number

void setup() {  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    app_value = Serial.read();

    // On Button
    if(app_value == '1'){
      // Loop for pulling the arm across
      // Breaks loop once stop is selected
      servo1.attach(servo1_pin);  // Starts servo
      while(app_value != '0'){
        app_value = Serial.read();
        //analogWrite(servo1_pin, servo1_speed);
        servo1.write(180);
      }
      servo1.detach(); // Stops servo
    }

    // Reverse
    else if(app_value = '9'){
      // Breaks loop once stop is selected
      servo1.attach(servo1_pin);  // Starts servo
      while(app_value != '0'){
        app_value = Serial.read();
        //analogWrite(servo1_pin, servo1_speed);
        servo1.write(-180);
      }
      servo1.detach(); // Stops servo
    }
  }
}
