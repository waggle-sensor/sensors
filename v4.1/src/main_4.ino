#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <OneWire.h>
#include "./SCAN/scanner.h"

// lib for sensors on lightsense
#include "./MCP342X/MCP342X.h"
MCP342X mcp3428_1;
MCP342X mcp3428_2;

OneWire ds2401(48);

char dataReading[256];

Scanner scanner;

void setup()
{
	// serial between cs and np
	SerialUSB.begin(115200);
	delay(10);

	// wire for sensors on met/lightsense boards
	Wire.begin();
	delay(10);

	// initialization for sensors on met/lightsense boards
	InitSensors();

	// initialization for chemsense board
	// If chemsense is on board????
	InitChemsense();

	// initialization for alpha sensor
	// If alpha sensor is on board????
	InitAlphasensor();

	// initialization for interruption function
	// If rain gauge is on board?
	InitInterrupt();
}

void loop()
{
	byte inputarray[256];
	byte input = '\0';
	bool postscript = false;
	int length = 0;
	while (!postscript)
	{
		input = SerialUSB.read();
		if (input == 0xaa)
		{
			inputarray[length++] = input;
			inputarray[length] = '\0';
			while (!postscript)
			{
				input = SerialUSB.read();
				inputarray[length++] = input;
				inputarray[length] = '\0';
				if (input == 0x55)
					postscript = true;
				if (length == 256)
					break;

			}
			if (length == 256)
				break;
		}
	}

	if (postscript)
		SortReading(inputarray, length);
}