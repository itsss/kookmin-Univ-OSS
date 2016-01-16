#include <Servo.h> 

int motorpin1 = 3;                 
int motorpin2 = 4;  

int echoPin = 6;
int trigPin = 5;

int servoPin = 9;
Servo servo; 
int angle = 0; 

void setup () 
{
  pinMode(motorpin1,OUTPUT); 
  pinMode(motorpin2,OUTPUT); 
  servo.attach(servoPin); 
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop () {

  digitalWrite(motorpin1,LOW);
  digitalWrite(motorpin2,HIGH);
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2;

  Serial.print(distance);
  Serial.println("cm");
  
  delay(500);
    for(angle = 0; angle < 180; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
  for(angle = 180; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
}
