#include <Arduino.h>

const int stepX = 2;
const int dirX = 5;
const int enPin = 8; //enPin disable/Enable
//digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

void setup() {
  pinMode(stepX, OUTPUT);
  pinMode(dirX, OUTPUT);
  pinMode(enPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(dirX, LOW);
  digitalWrite(enPin, LOW);
}

void loop() {
   while(Serial.available() > 0){
    
    //Serial.print("Avaliable");

    char inByte = Serial.read();
    if(inByte == '1'){
      digitalWrite(enPin, LOW);
      digitalWrite(stepX,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepX,LOW); 
      delayMicroseconds(500);
    }
    if(inByte == '0'){

    }

  }
}

