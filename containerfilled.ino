const int pingPin1 = 7; 
const int echoPin1 = 6; 

const int pingPin2 = 9; 
const int echoPin2 = 8; 

void setup() {
   Serial.begin(9600); 
}

void loop() {
   long duration1, cm1;
   long duration2, cm2;
   
   // Sensor 1
   pinMode(pingPin1, OUTPUT);
   digitalWrite(pingPin1, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin1, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin1, LOW);
   pinMode(echoPin1, INPUT);
   duration1 = pulseIn(echoPin1, HIGH);
   cm1 = microsecondsToCentimeters(duration1);
   
   // Sensor 2
   pinMode(pingPin2, OUTPUT);
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   pinMode(echoPin2, INPUT);
   duration2 = pulseIn(echoPin2, HIGH);
   cm2 = microsecondsToCentimeters(duration2);

   // Display results for Sensor 1
   Serial.print("Sensor 1: ");
   Serial.print(cm1);
   Serial.print(" cm");
   if(cm1 <= 3){
      Serial.print(" - Metal Dustbin  is fully filled!!!");
   }
   Serial.println();

   // Display results for Sensor 2
   Serial.print("Sensor 2: ");
   Serial.print(cm2);
   Serial.print(" cm");
   if(cm2 <= 3){
      Serial.print(" - Non-Metal Dustbin  is fully filled!!!");
   }
   Serial.println();

   delay(100);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
