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

void setup()
{
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  //Send message to receiver
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    if count == 0 {
      const char text[] = "RELEASE BALLOON";
      radio.write(&text, sizeof(text));
      count++;
      delay(1000);
    }
    else{
      const char text[] = "RESET BALLOON";
      radio.write(&text, sizeof(text));
      count = count - 1;
      delay(1000);
    }
  }

}
