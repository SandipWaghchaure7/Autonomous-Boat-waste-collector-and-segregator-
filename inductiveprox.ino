int sensor = 10;

void setup() { 
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() {
  int state = digitalRead(sensor);
  if (state == HIGH) {
    Serial.println("Metal is detected");
    delay(2000); 
  } 
  else {
    Serial.println("No metal");
    delay(2000); 
    }
  }