//Include Libraries, from https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo myservo;
int pos = 90; // check if this actually works or not based on how we mount it

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    const char release[] = "RELEASE BALLOON";
    const char reset[] = "RESET BALLOON";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if (strcmp(text, "RELEASE BALLOON") == 0) //test with all the formats
    {
      myservo.write(pos+90);
      Serial.println("Success");
      delay(10);
    }
    if (strcmp(text, "RESET BALLOON") == 0) //test with all the formats
    {
      myservo.write(pos-90);
      Serial.println("Success");
      delay(10);
    }
  }
}


