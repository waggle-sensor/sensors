// Chem sensor reading through bus functions

int ConfigLength;
byte ConfigReading[1516];

void InitBusSerial03(byte *parameters)
{
	byte powerPin = parameters[0];
	int baudrate = (parameters[1] << 16) | (parameters[2] << 8) | parameters[3];
	int timeout = parameters[4] * 1000;


	Serial3.begin(baudrate);	// begin serial3
	Serial3.setTimeout(timeout);	// set timeout of serial3 as 5 sec
	pinMode(powerPin, OUTPUT);  // pin for chemsense power is 47
	digitalWrite(powerPin, LOW); 	// power on the device --> LOW means power on
	delay(1000);

	if (Serial3.available() > 0)
		ConfigLength = Serial3.readBytesUntil(36, ConfigReading, 1516);
	else
		Serial3.end();
}

void ConfigBusSerial03(byte *parameters)
{
	return;
}

void EnableBusSerial03()
{
	return;
}

void DisableBusSerial03()
{
	return;
}

void ReadBusSerial03(byte *parameters, byte *sensorReading, int *readingLength)
{
	byte serialNum = parameters[1];
	ReadRS232(sensorReading, readingLength, serialNum);
}

void WriteBusSerial03(byte *sensorReading)
{
	return;
}