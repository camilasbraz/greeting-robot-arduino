#include <Servo.h>

#define trigPin 9
#define echoPin 8

Servo servo;

int sound = 250;

void setup() {

Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(6);

}

void loop() {

long duration, distance;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance <= 10) {
Serial.print(distance);
Serial.println(" cm");
for(int j=0; j<2; j++){
        for(int i= 40; i<100; i++){
          servo.write(i);
          delay(10);
        }
        for(int i= 100; i>=40; i--){
          servo.write(i);
          delay(10);
        }

}
}

else {
Serial.println("The distance is more than 10 cm");

}

delay(500);

}
