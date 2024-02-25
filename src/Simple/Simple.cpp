#include <Arduino.h>

const int stepX = 2;
const int dirX = 5;
const int enPin = 8; //enPin disable/Enable
//digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

/*
// put your setup code here, to run once:
   Serial.begin(9600);
   Serial.println();
   Serial.println(75);
   Serial.println(75, BIN);
   Serial.println('A');
   Serial.println('A',BIN);
   Serial.println(1.912,BIN);
*/

bool isConnected = false;
enum handShake {
  SYN,
  SYNACK,
  ACK
} handShakeState;

enum ConnectionStatus{
  DISCONNECTED,
  DISCONNECTING,
  CONNECTING,
  CONNECTED,
} connectionStatus;

enum expectedMessagesSizes{

};

void setup() {
  pinMode(stepX, OUTPUT);
  pinMode(dirX, OUTPUT);
  pinMode(enPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(dirX, LOW);
  digitalWrite(enPin, LOW);
}

//c - connect
//d - disconnect
//t - start
//p - stop
//1 - move motor
//0 - stop motor

bool isConnected = false;
bool move = false;
bool start = false;

void loop() {

  while(Serial.available() > 0){
    
    //Serial.print("Avaliable");

    char inByte = Serial.read();
    if(!isConnected){
      if(inByte == 'c'){
        isConnected = true;
      }
    }else{

      if(inByte == 't'){
        start = true;
      }

      if(inByte == 'p'){
        start = false;
      }

      if(start){
        if(inByte == '1'){
          move = true;
        }

        if(inByte == '0'){
          move = false;
        }
      }else{

      }
      

      if(inByte == 'd'){
        isConnected = false;
      }

    }
    
  }

  if(move){
    digitalWrite(enPin, LOW);
    digitalWrite(stepX,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepX,LOW); 
    delayMicroseconds(500);
  }else{
    
  }

  
}