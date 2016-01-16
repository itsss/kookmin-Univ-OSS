#include <Servo.h> 

int motorpin1 = 3;                

int motorpin2 = 4;                 
 int echoPin = 13;
int trigPin = 12;
int servoPin = 9;
Servo servo; 
int angle = 0; 
int sw = 0, i;

void setup () {

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
  delay(5);

  motor(distance);
}

void motor(float distance)
{
  if(distance > 15.000)
  {
    if(sw >= 0)
    {
        servo.write(180); 
        delay(30);
        sw = 180;
    }
    if(sw <= 180)
    {
        servo.write(0); 
        delay(30);
        sw = 0;
    }
  }
  else
  {
    if(distance < 12) analogWrite(motorpin1, 255);
    if(distance < 11) analogWrite(motorpin1, 180);
    if(distance < 10) analogWrite(motorpin1, 120);
    if(distance < 9) analogWrite(motorpin1, 80);
    if(distance < 6) analogWrite(motorpin1, 50);
    if(distance < 3) analogWrite(motorpin1, 20);
  }
}

