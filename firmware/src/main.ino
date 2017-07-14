#include "main.h"

void setup() 
{
	SerialUSB.begin(115200);

	while (!SerialUSB) {
	}

	// I2C begin, various sensors on met/lightsense boards
	Wire.begin();
	delay(1000);

	// SPI begin, alpha sensor configs
	// customspi.alphaSetting();

	// Serial3 begin, Chemsense configs
	// customserial.setting();
}

void commandID() 
{
	if (scanner.Scan() != '\n') 
	{
		Printf("err: invalid args");
		return;
	}
}

void commandVersion() 
{
	if (scanner.Scan() != '\n') 
	{
		Printf("err: invalid args");
		return;
	}

	Printf("ok: Ver 4.0.1");
}

void commandwriteCore() 
{
	scanner.Scan();

	// If user wants to change Mac address of Met/Lightsense boards,
	scanner.Scan();
	strncpy(dataReading, scanner.TokenText(), strlen(scanner.TokenText()));
	long metmac = strtol(dataReading, NULL, 10);

	metsense.writeMac(metmac);
}

void commandreadCore()
{	
	while (scanner.Scan() != '\n')
	{
		byte sensor_ID = sensor.sensorID(scanner.TokenText());	
		// Met data
		if (sensor_ID < 0x10)
			metsense.readMet(sensor_ID, &NumVal, dataReading);	
		// Light data
		else if (sensor_ID < 0x20)
			lightsense.readLight(sensor_ID, &NumVal, dataReading);

		printData(sensor_ID, NumVal, dataReading);
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

void commandSerialpower()
{	
	fillBuffer();
	int powerPin = (int)buffer[0];
	int sign = (int)buffer[1];

	customserial.powerSerialSensor(powerPin, sign);
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

	customi2c.writeI2C(address, bufferlength, buffer);
}

void commandI2Cread()
{
	fillBuffer();
	char address = buffer[0];
	int length = buffer[1];

	customi2c.readI2C(address, length, buffer);
	printData(address, length, buffer);
}

void fillBuffer()
{
	memset(buffer, '\0', PRINTF_BUF);
	NumVal = 0;
	while (scanner.Scan() != '\n') 
	{
		strncpy(dataReading, scanner.TokenText(), strlen(scanner.TokenText()));
		buffer[NumVal++] = strtol(dataReading, NULL, 16);
	}
}

bool execCommand() {
	// consume leading newline tokens
	while (scanner.Scan() == '\n') {
		// if (scanner.Err()) {
		//     scanner.Reset();
		// }
	}

	// Printf("debug: command <%s>", scanner.TokenText());

	if (matches(scanner.TokenText(), "ver"))
		commandID();

	else if (matches(scanner.TokenText(), "id"))
		commandVersion();


	else if (matches(scanner.TokenText(), "Corewrite"))
		commandwriteCore();
	else if (matches(scanner.TokenText(), "Coreread"))
		commandreadCore();

	else if (matches(scanner.TokenText(), "SPIconfig"))
		commandSPIconfig();
	else if (matches(scanner.TokenText(), "SPIread"))
		commandSPIread();

	else if (matches(scanner.TokenText(), "Serialpower"))
		commandSerialpower();
	else if (matches(scanner.TokenText(), "Serialconfig"))
		commandSerialconfig();
	else if (matches(scanner.TokenText(), "Serialwrite"))
		commandSerialwrite();
	else if (matches(scanner.TokenText(), "Serialread"))
		commandSerialread();

	else if (matches(scanner.TokenText(), "I2Cwrite")) 
		commandI2Cwrite();
	else if (matches(scanner.TokenText(), "I2Cread"))
		commandI2Cread();

	else
		return false;

	return true;
	// consume trailing tokens
	// while (scanner.Scan() != '\n') {
	// }

	// return false;
}

void loop() {
	bool ok = execCommand();

	if (ok)
		Printf("end: next command");
	else
	{
		Printf("end: invalid command");
			// consume trailing tokens
		while (scanner.Scan() != '\n') {
		}
	}
}
