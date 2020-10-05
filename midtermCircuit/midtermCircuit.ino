#include <SharpIR.h>

SharpIR sensor(SharpIR::GP2Y0A21YK0F, A0);
int led1 = 13; // red led
int led2 = 12; //green led

void setup() {
  Serial.begin(9600); //Enable the serial comunication
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

//Get 5 distance readings, each 1/5th of a second apart, then average them to get a stable reading.
//Send that to Processing, then turn on the Red LED if the distance is closer than 20 cm, or turn on
//the Green LED if the distance is further than 20cm.
void loop() {
  int distance = 0;
  distance += sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  delay(200);
  distance += sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  delay(200);
  distance += sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  delay(200);
  distance += sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  delay(200);
  distance += sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  delay(200);

  distance = distance/5;//get an average of 5 reads per second. Help with consistency?
  // Print the measured distance to the serial monitor:
  Serial.println(distance);
  if(distance > 20) {
     digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  } else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }

}
