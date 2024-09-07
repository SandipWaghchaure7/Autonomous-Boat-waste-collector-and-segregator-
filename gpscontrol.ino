#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define the connections to the GPS module
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// Create a SoftwareSerial object
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  // Start the serial communication with the GPS module
  ss.begin(GPSBaud);

  // Start the serial communication with the computer
  Serial.begin(115200);
  Serial.println(F("GPS Module Test"));

  // Give the GPS module some time to start up
  delay(1000);
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
  {
    gps.encode(ss.read());
    if (gps.location.isUpdated())
    {
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6); 
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
    }
  }
}