//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
const int buttonPin = 2; 

// variables will change:
bool buttonState = false;      
int count = 0;
void setup()
{
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
  Serial.begin(9600);

}
void loop()
{
  //Send message to receiver
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:

  delay(10000);
  buttonState = HIGH;
  if (buttonState == HIGH) {
    if (count == 0) {
      const char text[] = "RELEASE BALLOON";
      radio.write(&text, sizeof(text));
      Serial.print(text);
      count++;
      delay(250);
      buttonState = LOW;
      delay(1000);
    }
    else{
      const char text[] = "RESET BALLOON";
      radio.write(&text, sizeof(text));
      Serial.print(text);
      count = count - 1;
      delay(1000);
    }
  }

}
