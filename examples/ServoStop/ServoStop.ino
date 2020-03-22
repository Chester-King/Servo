/*
  Setting servo position to 0 whenever any object distance
  with the ultrasonic sensor is less than 17cm. Setting Servo position to 90 otherwise
  by Madhur Dixit https://github.com/Chester-King

  You can see the detailed description and required circuit for the sketch at https://gist.github.com/Chester-King/fc19b83777ff629b6708731f09eeaa6c  
*/


#include <Servo.h>
byte trigPin = 3;
byte echoPin = 2;
byte servoPin = 4;

Servo myservo;  // create servo object to control a servo
int pos = 0; // variable to store the servo position
void setup() {
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myservo.attach(servoPin);  // attaches the servo on pin 4 to the Servo object
}

void loop() {
  unsigned long duration;
  unsigned int distance;

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = (duration / 2) / 29.1;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Checks if the distance between the object is less than 17cm
  if (distance < 17) {
    myservo.write(0);   // if the distance between the object is less than 17cm then tell servo to go to position 0
  } else {
    myservo.write(90);   // if the distance between the object is greater than or equal to 17cm then tell servo to go to position 90
  }
}
