#include "serial.h"

// void customSerial::setting()
// {
// 	// Begin Serial3
//     Serial3.begin(CHEMSENSE_DATARATE);
//     // To wait until chem sends data again
//     // if chem does not send data for 2 secs
//     Serial3.setTimeout(4000);
    
//     // Set a GPIO pin for chemsense power
//     pinMode(PIN_CHEMSENSE_POW, OUTPUT);
//     // LOW means power on
//     digitalWrite(PIN_CHEMSENSE_POW, LOW);	
// }


void CustomSerial::configSerial(int port, long datarate, long timeout, int powerPin)
{
	if (port == 3)
	{
		Serial3.begin(datarate);
		Serial3.setTimeout(timeout); //ms
		pinMode(powerPin, OUTPUT); // Set a GPIO pin
		digitalWrite(powerPin, LOW); // LOW means power on
		delay(500);
	}
	else if (port == 2)
	{
		Serial2.begin(datarate);
		Serial2.setTimeout(timeout);
		pinMode(powerPin, OUTPUT);
		digitalWrite(powerPin, LOW);
		delay(500);
	}
	else if (port == 1)
	{
		Serial1.begin(datarate);
		Serial1.setTimeout(timeout);
		pinMode(powerPin, OUTPUT);
		digitalWrite(powerPin, LOW);
		delay(500);
	}
}

void CustomSerial::readSerial(char* reading, int* NumVal, int port)
{
	int len = 0;
	char inputbyte;

	if (port == 3)
	{
		while (Serial3.available() > 0)
			inputbyte = Serial3.read();

		len = Serial3.readBytesUntil('\n', reading, 256);
	}

	else if (port == 2)
	{
		while (Serial2.available() > 0)
			inputbyte = Serial2.read();

		len = Serial2.readBytesUntil('\n', reading, 256);
	}

	else if (port == 1)
	{
		while (Serial1.available() > 0)
			inputbyte = Serial1.read();
		len = Serial1.readBytesUntil('\n', reading, 256);
	}

	reading[len] = '\0';
	*NumVal = len;
}

void CustomSerial::writeSerial(char* writing, int length, int port)
{
	if (port == 3)
		Serial3.write(writing, length);
	else if (port == 2)
		Serial3.write(writing, length);
	else if (port == 1)
		Serial3.write(writing, length);
}