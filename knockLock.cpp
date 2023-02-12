#include <Servo.h>

Servo myservo;
int pos = 0;
int soundSensor = A0;
int threshold = 500;

void setup() {
  myservo.attach(9);
  pinMode(soundSensor, INPUT);
}

void loop() {
  int sensorValue = analogRead(soundSensor);
  if (sensorValue > 100) {
    delay(500);
    if (sensorValue > 100) {	
      for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      for (pos = 180; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
    }
  }
}
