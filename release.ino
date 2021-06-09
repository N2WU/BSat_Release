//Include Libraries, from https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo myservo;
int pos = 0; // check if this actually works or not based on how we mount it

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
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if text.equals("RELEASE BALLOON") == 1 //test with all the formats
    {
      myservo.write(pos+90);
      delay(10);
    }
    if text.equals("RESET Balloon") == 1 //test with all the formats
    {
      myservo.write(pos-90);
      delay(10);
    }
  }
}


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
