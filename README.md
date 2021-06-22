# BSat_Release
Uses an nRF24L01 with an arduino to control a servo

Connect the nRF24 to the arduino using this pinout: https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/

Connect the servo to +Vcc, GND, and pin 5 (PWM) of the receive arduino.

Before installation, check the following
1. The mounted position of the servo is where you want it to be upon initialization (pos = 0)
2. The servo moves in the correct direction (+90 degrees for release, -90 degrees for reset)
3. The TNC has the correct commands programmed ("RELEASE BALLOON" and "RESET BALLOON")

TNC_example.ino also works to test the mechanism before testing the actual TNC. Connect the arduino to the nRF24 using the link above. Wire a pushbutton to pins 2 and 7 each.

**June 21**
I just built and tested the circuit with two nRF-enabled arduinos. I added minor bugfixes. I also eliminated a pushbutton in the TNC_example.ino script, so now it just cycles between release and reset. Upon installation, the servo position must be confirmed so that "release" actually releases the payloadm etc.
