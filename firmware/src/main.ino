#include "main.h"

void setup() 
{
	SerialUSB.begin(115200);

	while (!SerialUSB) {
	}

	// I2C begin, various sensors on met/lightsense boards
	Wire.begin();
	delay(10);

	// SPI begin, alpha sensor configs
	cspi.AlphaSetting();

	// Serial3 begin, Chemsense configs
	chem.setting();
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

void command2Write() 
{
	scanner.Scan();

	// If user wants to change Mac address of Met/Lightsense boards,
	if (matches(scanner.TokenText(), "mac"))
	{
		scanner.Scan();
		strncpy(dataReading, scanner.TokenText(), strlen(scanner.TokenText()));
		SensorBoardsMac = strtol(dataReading, NULL, 10);

		cmet.WriteMac(SensorBoardsMac);
	}
	else
	{
		Printf("err: %s", "no match");
		// consume trailing tokens
		while (scanner.Scan() != '\n') {
		}
	}
}

void command2Read() 
{
	// Let's grap some data

	// check input command
	// according to the input command,
	// we will grap data from Met/Light/or Chem board
	scanner.Scan();
	byte sensor_ID = sensor.sensorID(scanner.TokenText());

	// Call functions according to the sensor_ID
	if (sensor_ID < 0x40)
		readCore(sensor_ID);
	else if (sensor_ID == 0x40)
		readAlpha(sensor_ID);
	else
	{
		Printf("err: %x %s", sensor_ID, "no match");
			// consume trailing tokens
		while (scanner.Scan() != '\n') {
		}
	}
}

void readCore(byte sensor_ID)
{
	do
	{
		byte sensor_ID = sensor.sensorID(scanner.TokenText());
		// Mac addresses for Met and Chem
		if (sensor_ID == 0x00)
		{
			cmet.ReadMac(&SensorBoardsMac);
			Printf("data %x %ld", 0x00, SensorBoardsMac);
			chem.ChemGet(&NumVal, dataReading);
		}
		// Met data
		else if (sensor_ID < 0x10)
			cmet.MetGet(sensor_ID, &NumVal, dataReading);	
		// Light data
		else if (sensor_ID < 0x20)
			clight.LightGet(sensor_ID, &NumVal, dataReading);
		// Chem data	
		else if (sensor_ID < 0x40)
			chem.ChemGet(&NumVal, dataReading);

		printData(sensor_ID, NumVal, dataReading);
	} while (scanner.Scan() != '\n');
}

void readAlpha(byte sensor_ID)
{
	NumVal = 0;
	char buffer[256];
	while (scanner.Scan() != '\n') 
	{
		strncpy(dataReading, scanner.TokenText(), strlen(scanner.TokenText()));
		buffer[NumVal++] = strtol(dataReading, NULL, 16);
	}

	if (buffer[0] == 0x42)
		buffer[NumVal - 1] = (int)buffer[NumVal - 1];

	cspi.AlstartTrans();
	for (int i = 0; i < NumVal; i++)
	{
		buffer[i] = cspi.readSPI(buffer[i]);
		if (i == 0)
			delay(10);
	}
	cspi.AlendTrans();
	
	printData(sensor_ID, NumVal, buffer);
}

void printData(byte ID, int NumVal, char* dataReading)
{
	// Print data, for all data from three boards 
	// Met, light, and chem
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

bool execCommand() {
	// consume leading newline tokens
	while (scanner.Scan() == '\n') {
		// if (scanner.Err()) {
		//     scanner.Reset();
		// }
	}

	// Printf("debug: command <%s>", scanner.TokenText());

	if (matches(scanner.TokenText(), "ver")) {
		commandID();
		return true;
	}

	else if (matches(scanner.TokenText(), "id")) {
		commandVersion();
		return true;
	}

	else if (matches(scanner.TokenText(), "2write")) {
		command2Write();
		return true;
	}

	// Let's get data,
	else if (matches(scanner.TokenText(), "2read")) {
		command2Read();
		return true;
	}

	else if (matches(scanner.TokenText(), "data")) {
		SerialUSB.print("data ");
		for (int i = 0; i < 256; i++)
		{
			SerialUSB.print(dataReading[i], HEX);
			SerialUSB.print(' ');
		}
		SerialUSB.println("");
		Printf("ok: %s", "end data");
		return true;
	}

	else
		return false;

	// consume trailing tokens
	// while (scanner.Scan() != '\n') {
	// }

	// return false;
}

void loop() {
	bool ok = execCommand();

	if (ok)
		Printf("ok: next command");
	else
	{
		Printf("ok: invalid command");
			// consume trailing tokens
		while (scanner.Scan() != '\n') {
		}
	}
}
