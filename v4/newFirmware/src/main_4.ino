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
	// If chemsense is onboard????
	InitChemsense();

	// initialization for alpha sensor
	// If alpha sensor is onboard????
	InitAlphasensor();
}

void loop()
{
	ExecCommand();
	SerialUSB.println("end: next command");
	while (scanner.Scan() != '\n') { }
}

void ExecCommand()
{
	// consume trailing tokens
	while (scanner.Scan() == '\n') { }

	strncpy(dataReading, scanner.TokenText(), sizeof(dataReading)); 

	SortReading(dataReading);

	SerialUSB.print("data: ");
	SerialUSB.println(scanner.TokenText());

// 	const Command *cmd = FindCommand(scanner.TokenText());

// 	if (cmd == NULL) {
// 		SerialUSB.print("! no command ");
// 		SerialUSB.println(scanner.TokenText());
// 		return;
// 	}

// cmd->func();
}
