// #include "main.h"
#include "scanner.h"
#include "stringutils.h"
#include "fmt.h"
#include "devices.h"
#include "serial/serial.h"
#include "spi/spi.h"
#include "i2c/i2c.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// OneWire ds(48);
#define MetSenNum 0x09
#define LightSenNum 0x08

char dataReading[256];
char buffer[256];
Scanner scanner;
CustomSerial customserial;
CustomSPI customspi;

void InitSerialUSB() {
	SerialUSB.begin(115200);
	delay(10);
}

void InitI2C() {
	Wire.begin();
	delay(10);
}

void commandID() {
	SerialUSB.println("ok: 12345678");
}

void commandVersion() {
	SerialUSB.println("ok: 4.0.1");
}

void commandWriteCore() {
	scanner.Scan();

	// If user wants to change Mac address of Met/Lightsense boards,
	scanner.Scan();
	strncpy(dataReading, scanner.TokenText(), sizeof(dataReading));

	// long metmac = strtol(dataReading, NULL, 10);
	// metsense.writeMac(metmac);
}

void commandReadCore() {
	int data[16];

	while (scanner.Scan() != '\n') {
		const char *name = scanner.TokenText();
		const Device *dev = FindDevice(name);

		if (dev == NULL) {
			SerialUSB.print("err: no device ");
			SerialUSB.println(name);
			continue;
		}

		int sensor_ID = dev->addr;
		int size = dev->read(data);

		SerialUSB.print("data ");
		SerialUSB.print(sensor_ID, HEX);
		SerialUSB.print(' ');

		for (int i = 0; i < size; i++) {
			SerialUSB.print(data[i]);
			SerialUSB.print(' ');
		}

		SerialUSB.println();
	}
}

void printData(byte ID, int size, char *dataReading)
{
	// Print data,
	SerialUSB.print("data ");
	SerialUSB.print(ID, HEX);
	SerialUSB.print(' ');

	for (int i = 0; i < size; i++) {
		SerialUSB.print(dataReading[i], HEX);
		SerialUSB.print(' ');
	}

	SerialUSB.println("");
}

void commandSPIconfig()
{
	int size = fillBuffer();

	int slavePin = (int)buffer[0];
	int bitOrder = (int)buffer[size-2];
	int dataMode = (int)buffer[size-1];

	long maxSpeed = (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);

	customspi.configSPI(slavePin, maxSpeed, bitOrder, dataMode);
}

void commandSPIread()
{
	int size = fillBuffer();

	int bufferlength = size-2;
	int delaytime = (int)buffer[0];
	int iter = (int)buffer[1];
	int slavePin;

	for (int i = 0; i < bufferlength; i++)
		buffer[i] = buffer[i + 2];

	customspi.readSPI(buffer, bufferlength, delaytime, iter, &slavePin);
	printData(slavePin, bufferlength, buffer);
}

void commandSerialconfig()
{
	int size = fillBuffer();
	int port = (int)buffer[0];
	int powerPin = (int)buffer[size-1];
	long datarate = (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
	long timeout = (buffer[4] << 16) | (buffer[5] << 8) | (buffer[6]);

	customserial.configSerial(port, datarate, timeout, powerPin);
}

void commandSerialwrite()
{
	int size = fillBuffer();
	int port = (int)buffer[0];
	int bufferlength = size-1;

	for (int i = 0; i < bufferlength; i++)
		buffer[i] = buffer[i + 1];

	customserial.writeSerial(buffer, bufferlength, port);
}

void commandSerialread()
{
	int size = fillBuffer();
	int port = (int)buffer[0];

	customserial.readSerial(buffer, &size, port);
	int serialID = 0xc0 | port;
	printData(serialID, size, buffer);
}

void commandI2Cwrite()
{
	int size = fillBuffer();
	char address = buffer[0];
	int bufferlength = size-1;

	for (int i = 0; i < bufferlength; i++) {
		buffer[i] = buffer[i+1];
	}

	WriteI2C(address, bufferlength, buffer);
}

void commandI2Cread()
{
	int size = fillBuffer();
	char address = buffer[0];
	int length = buffer[1];

	ReadI2C(address, length, buffer);
	printData(address, length, buffer);
}

void commandAnalogread()
{
	int size = fillBuffer();
	int analogPin = (int)buffer[0];
	char analogid = 0xa0|analogPin;

	SerialUSB.print("data ");
	SerialUSB.println(buffer[0], HEX);

	int analogreading = analogRead(analogPin);
	// Print data,
	printReading(analogid, analogreading);
}

void commandDigitalread()
{
	int size = fillBuffer();
	int digitalPin = (int)buffer[0];
	char digitalid = digitalPin;

	SerialUSB.print("data ");
	SerialUSB.println(buffer[0], HEX);

	int digitalreading = digitalRead(digitalPin);
	// Print data,
	printReading(digitalid, digitalreading);
}

void commandDigitalwrite()
{
	int size = fillBuffer();
	int digitalPin = (int)buffer[0];
	int power = (int)buffer[1];

	if (power == 0) {
		digitalWrite(digitalPin, LOW); // power on
	} else if (power == 1) {
		digitalWrite(digitalPin, HIGH); // power off
	}
}

void printReading(char id, int value) {
	SerialUSB.print("data ");
	SerialUSB.print(id, HEX);
	SerialUSB.print(' ');
	SerialUSB.println(value);
}

int fillBuffer() {
	memset(buffer, 0, sizeof(buffer));
	memset(dataReading, 0, sizeof(dataReading));

	int size = 0;

	while (scanner.Scan() != '\n') {
		strncpy(dataReading, scanner.TokenText(), sizeof(dataReading));
		buffer[size++] = strtol(dataReading, NULL, 16);
	}

	return size;
}

struct Command {
	const char *name;
	void (*func)();
};

const Command commands[] = {
	{"id", commandID},
	{"ver", commandVersion},
	{"Corewrite", commandWriteCore},
	{"Coreread", commandReadCore},
	{"read", commandReadCore},
	{"SPIconfig", commandSPIconfig},
	{"SPIread", commandSPIread},
	{"Serialconfig", commandSerialconfig},
	{"Serialwrite", commandSerialwrite},
	{"Serialread", commandSerialread},
	{"I2Cwrite", commandI2Cwrite},
	{"I2Cread", commandI2Cread},
	{"analogRead", commandAnalogread},
	{"digitalRead", commandDigitalread},
	{"digitalWrite", commandDigitalwrite},
};

const int numcommands = sizeof(commands) / sizeof(commands[0]);

const Command *FindCommand(const char *name) {
	for (int i = 0; i < numcommands; i++) {
		const Command *cmd = commands+i;

		if (strcmp(cmd->name, name) == 0) {
			return cmd;
		}
	}

	return NULL;
}

bool ExecCommand() {
	// consume leading newline tokens
	while (scanner.Scan() == '\n') {
	}

	const Command *cmd = FindCommand(scanner.TokenText());

	if (cmd == NULL) {
		return false;
	}

	cmd->func();
	return true;
}

void setup() {
	InitSerialUSB();
	InitI2C();
	InitDevices();
}

void loop() {
	if (ExecCommand()) {
		Printf("end: next command");
	} else {
		Printf("end: invalid command");
	}
}
