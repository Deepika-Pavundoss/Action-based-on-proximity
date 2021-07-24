#include <Servo.h>

Servo myservo; 

int pos = 0;// variable to store the servo position
int trigPin = 2;
int echoPin = 3;
int ledPin = 6;
void distance();
 
void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  distance();
  digitalWrite(ledPin,HIGH);  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  for (pos = 0; pos <= 45; pos += 1) { // goes from 0 degrees to 45 degrees
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 45; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
}
 
void distance(){
  int time; long dist=500;
  digitalWrite(ledPin,HIGH);
  while(dist>=120)
  {
     digitalWrite(trigPin,LOW);
    delay(2000);
    digitalWrite(trigPin,HIGH);
    delay(10);
    digitalWrite(trigPin,LOW);
    time = pulseIn(echoPin,HIGH);
    dist = time*0.034/2;
    Serial.print("Distance in cm: ");
    Serial.println(dist);
  }
  
}

void loop(){
  
}
