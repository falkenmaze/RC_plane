#include<SPI.h>
#include<NRF24LO1.h>
#include<RF24.h>
#include<Servo.h>
RF24 radio(7,8);
const byte address[6] = ["00001"];
Servo servo;

void setup()
{
  servo.attach(5);
  radio.begin();
  radio.openReadingPipe(1, address[0]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop()
{
  delay(5);
  radio.startListening();
  if (radio.available())
  {
    while(radio.available())
    {
      int angle = 0;
      radio.read(&angle, sizeof(angle));
      servo.write(angle);
    }
  }
}