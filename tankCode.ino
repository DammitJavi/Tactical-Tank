#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//
#define in1 2
#define in2 3
#define in3 4
#define in4 6


RF24 radio(7, 8);



const int motorPin = 5;
const int motorPin2 = 3;


const byte address[6] = "00011";

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
//  pinMode(in1, OUTPUT);
//  pinMode(in2, OUTPUT);
//  pinMode(in3, OUTPUT);
//  pinMode(in4, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int data;
    radio.read(&data, sizeof(data));
    Serial.println(data);
    if(data == 2 && data ==3){ 
      analogWrite(motorPin, 200);
      analogWrite(motorPin2, 200);
    }
    
    if (data == 2){
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      //digitalWrite(motorPin, HIGH);
      analogWrite(motorPin, 200);
      analogWrite(motorPin2, 0);
    }

    if (data == 3){
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      //digitalWrite(motorPin2, HIGH);
      analogWrite(motorPin, 0);
      analogWrite(motorPin2, 200);
      
  }
    if (data == 4)
      Serial.println("photo");
    delay(150);
    analogWrite(motorPin, 0);
    analogWrite(motorPin2, 0);
  //Serial.println(data);
  
  }
}
