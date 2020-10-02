#include <SharpIR.h>

//Create a new instance of the library
//Call the sensor "sensor"
//The model of the sensor is "GP2Y0A21YK0F"
//The sensor output pin is attached to the pin A0
SharpIR sensor(SharpIR::GP2Y0A21YK0F, A0);
int led1 = 13;

void setup() {
  Serial.begin(9600); //Enable the serial comunication
  pinMode(led1, OUTPUT);
}

void loop() {
  int distance = sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable

  // Print the measured distance to the serial monitor:
  Serial.print("Distance: ");
  Serial.print(distance);
  if(distance > 20) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  Serial.println("cm");
  delay(500);
}
