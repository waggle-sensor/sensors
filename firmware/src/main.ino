#include "main.h"
#include "devices.h"

void InitSerialUSB() {
	SerialUSB.begin(115200);
	delay(10);
}

void InitI2C() {
	Wire.begin();
	delay(10);
}

void commandID() {
	Printf("ok: 12345678\n");
}

void commandVersion() {
	Printf("ok: 4.0.1\n");
}

void commandwriteCore() {
	scanner.Scan();

	// If user wants to change Mac address of Met/Lightsense boards,
	scanner.Scan();
	strncpy(dataReading, scanner.TokenText(), strlen(scanner.TokenText()));
	long metmac = strtol(dataReading, NULL, 10);

	// metsense.writeMac(metmac);
}

void commandreadCore()
{
	int intValue[16];

	while (scanner.Scan() != '\n')
	{
		const Device *dev = FindDevice(scanner.TokenText());

		if (dev == NULL) {
			SerialUSB.println("err: invalid device");
			continue;
		}

		int sensor_ID = dev->addr;

		if (dev->read != NULL) {
			NumVal = dev->read(intValue);
		} else if (sensor_ID < 0x10) {
			metsense.readMet(sensor_ID, &NumVal, intValue);
		} else if (sensor_ID < 0x20) {
			lightsense.readLight(sensor_ID, &NumVal, intValue);
		}

		SerialUSB.print("data ");
		SerialUSB.print(sensor_ID, HEX);
		SerialUSB.print(' ');

		for (int i = 0; i < NumVal; i++)
		{
			SerialUSB.print(intValue[i]);
			SerialUSB.print(' ');
		}

		SerialUSB.println();
	}
}

void printData(byte ID, int NumVal, char* dataReading)
{
	// Print data,
	SerialUSB.print("data ");
	SerialUSB.print(ID, HEX);
	SerialUSB.print(' ');
	for (int i = 0; i < NumVal; i++)
	{
		SerialUSB.print(dataReading[i], HEX);
		SerialUSB.print(' ');
	}
	SerialUSB.println("");
}

void commandSPIconfig()
{
	fillBuffer();
	int slavePin = (int)buffer[0];
	int bitOrder = (int)buffer[NumVal - 2];
	int dataMode = (int)buffer[NumVal - 1];

	long maxSpeed = (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);

	customspi.configSPI(slavePin, maxSpeed, bitOrder, dataMode);
}

void commandSPIread()
{
	fillBuffer();
	int bufferlength = NumVal - 2;
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
	fillBuffer();
	int port = (int)buffer[0];
	int powerPin = (int)buffer[NumVal - 1];
	long datarate = (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
	long timeout = (buffer[4] << 16) | (buffer[5] << 8) | (buffer[6]);

	customserial.configSerial(port, datarate, timeout, powerPin);
}

void commandSerialwrite()
{
	fillBuffer();
	int port = (int)buffer[0];
	int bufferlength = NumVal - 1;

	for (int i = 0; i < bufferlength; i++)
		buffer[i] = buffer[i + 1];

	customserial.writeSerial(buffer, bufferlength, port);
}

void commandSerialread()
{
	fillBuffer();
	int port = (int)buffer[0];

	customserial.readSerial(buffer, &NumVal, port);
	int serialID = 0xc0 | port;
	printData(serialID, NumVal, buffer);
}

void commandI2Cwrite()
{
	fillBuffer();
	char address = buffer[0];
	int bufferlength = NumVal - 1;

	for (int i = 0; i < bufferlength; i++)
		buffer[i] = buffer[i + 1];

	WriteI2C(address, bufferlength, buffer);
}

void commandI2Cread()
{
	fillBuffer();
	char address = buffer[0];
	int length = buffer[1];

	ReadI2C(address, length, buffer);
	printData(address, length, buffer);
}

void commandAnalogread()
{
	fillBuffer();
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
	fillBuffer();
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
	fillBuffer();
	int digitalPin = (int)buffer[0];
	int power = (int)buffer[1];

	if (power == 0) {
		digitalWrite(digitalPin, LOW); // power on
	} else if (power == 1) {
		digitalWrite(digitalPin, HIGH); // power off
	}
}

void printReading(char id, int value)
{
	// Print data,
	SerialUSB.print("data ");
	SerialUSB.print(id, HEX);
	SerialUSB.print(' ');
	SerialUSB.println(value);
}

void fillBuffer()
{
	memset(buffer, 0, MaxSize);
	memset(dataReading, 0, MaxSize);
	NumVal = 0;
	while (scanner.Scan() != '\n')
	{
		strncpy(dataReading, scanner.TokenText(), strlen(scanner.TokenText()));
		buffer[NumVal++] = strtol(dataReading, NULL, 16);
	}
}

struct Command {
	const char *name;
	void (*func)();
};

const Command commands[] = {
	{"id", commandID},
	{"ver", commandVersion},
	{"Corewrite", commandwriteCore},
	{"Coreread", commandreadCore},
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

void setup()
{
	InitSerialUSB();
	InitI2C();
	InitDevices();
}

void loop() {
	bool ok = ExecCommand();

	if (ok) {
		Printf("end: next command");
	} else {
		Printf("end: invalid command");
	}

	// consume trailing tokens
	while (scanner.Scan() != '\n') {
	}
}
