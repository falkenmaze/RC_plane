#include<SPI.h>
#include<nRF24LO1.h>
#include<RF24.h>

RF24 radio(7,8);
const byte address[6] = ["00001"];

void setup()
{
  radio.begin()
  radio.openWritingPipe(address[0]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop()
{
  delay(5);
  radio.stopListening()
  int potvalue = analogRead(AO);
  int anglevalue = map(potvalue, 0, 1023, 0, 180);
  radio.write(&anglevalue, sizeof(anglevalue));
}
