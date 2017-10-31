#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <OneWire.h>

// lib for sensors on lightsense
#include "./MCP342X/MCP342X.h"
MCP342X mcp3428_1;
MCP342X mcp3428_2;

OneWire ds2401(48);

char dataReading[256];

void setup()
{
	// serial between cs and np
	SerialUSB.begin(9600);
	delay(10);

	// wire for sensors on met/lightsense boards
	// AND initialization for sensors on met/lightsense boards
	Wire.begin();
	delay(10);
	InitSensors();
}

void loop()
{
	int MaxInputLength = 260;
	byte inputarray[MaxInputLength];
	byte input = '\0';
	bool postscript = false;
	int length = 0;

	// Read data until it gets a postscript
	while (!postscript)
	{
		input = SerialUSB.read();

		// If input is preamble, then store bytes from now
		if (input == 0xaa)
		{
			inputarray[length] = input;
			inputarray[++length] = '\0';

			// And keep reading until it gets a postscript
			while (!postscript)
			{
				input = SerialUSB.read();
				inputarray[length] = input;

				// If it gets a postscript, break loops
				// If length of the input is 260, break loops
				if (input == 0x55)
					postscript = true;
				if (length == MaxInputLength)
					break;

				inputarray[++length] = '\0';

			}
			if (length == MaxInputLength)
				break;
		}
	}

	if (postscript)
		SortReading(inputarray, length-1);
}