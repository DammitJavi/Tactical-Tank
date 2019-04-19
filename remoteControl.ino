#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);
byte switchPin[3] = { 2,3,4 };

const byte address[6] = "00011";

int pinVal;

void setup() {
  radio.begin();
  radio.setRetries(15,15);
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(address);
  radio.stopListening();
   for (byte i = 0; i < 3; i++)
   pinMode(switchPin[i], INPUT_PULLUP);
   Serial.begin(9600);
}

void loop() {
  for (byte i = 0; i < 3; i++) {
    pinVal = digitalRead(switchPin[i]);
    if (pinVal == LOW) {
      sendRF(switchPin[i]);
      Serial.println(switchPin[i]);
    }
  }
  delay(0);
}

void sendRF(int data) {
    radio.write(&data, sizeof(data));
}
