#include <Servo.h>

int sensor = 11;
int IRSensor = 12;

Servo myservo1;  // create servo object to control servo 1
Servo myservo2;  // create servo object to control servo 2

void setup() {
 Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(IRSensor, INPUT);

  myservo1.attach(9);  // attaches the servo 1 on pin 9 to the servo object
  myservo2.attach(10); // attaches the servo 2 on pin 10 to the servo object

  
}

void loop() {
  // Do nothing here
  int IRsensorStatus = digitalRead(IRSensor);
  if(IRsensorStatus == 1){
    Serial.println("Object is not Detected!");
  }
  if(IRsensorStatus == 0){
    Serial.println("Object is Detected!");
  }
  int state = digitalRead(sensor);
  if (state == HIGH  && IRsensorStatus == 0) {

    int pos;

  // Move servos in opposite directions: Servo 1 clockwise, Servo 2 anticlockwise
  for (pos = 0; pos <= 60; pos += 1) {
    myservo1.write(pos);            // tell servo 1 to go to position in variable 'pos'
    myservo2.write(60 - pos);       // tell servo 2 to go to the inverse position
    delay(15);                      // waits 15ms for the servos to reach the position
  }
  delay(1000);

  // Move servos in opposite directions: Servo 1 anticlockwise, Servo 2 clockwise
  for (pos = 60; pos >= 0; pos -= 1) {
    myservo1.write(pos);            // tell servo 1 to go to position in variable 'pos'
    myservo2.write(60 - pos);       // tell servo 2 to go to the inverse position
    delay(15);                      // waits 15ms for the servos to reach the position
  }


  }

  else if(state == LOW && IRsensorStatus == 0){
    int pos;

  // Move servos in opposite directions: Servo 1 clockwise, Servo 2 anticlockwise
  for (pos = 0; pos <= 60; pos += 1) {
    myservo1.write(60 - pos);            // tell servo 1 to go to position in variable 'pos'
    myservo2.write(pos);       // tell servo 2 to go to the inverse position
    delay(15);                      // waits 15ms for the servos to reach the position
  }
  delay(1000);

  // Move servos in opposite directions: Servo 1 anticlockwise, Servo 2 clockwise
  for (pos = 60; pos >= 0; pos -= 1) {
    myservo1.write(60 - pos);            // tell servo 1 to go to position in variable 'pos'
    myservo2.write(pos);       // tell servo 2 to go to the inverse position
    delay(15);                      // waits 15ms for the servos to reach the position
  }
    
  }
}
