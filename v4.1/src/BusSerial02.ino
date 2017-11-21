// Chem sensor reading through bus functions

void InitBusSerial02(byte *parameters)
{
	byte powerPin = parameters[0];
	int baudrate = (parameters[1] << 16) | (parameters[2] << 8) | parameters[3];
	int timeout = (parameters[4] << 8) | parameters[5];


	Serial3.begin(baudrate);	// begin serial3
	Serial3.setTimeout(timeout);	// set timeout of serial3 as 5 sec
	pinMode(powerPin, OUTPUT);  // pin for chemsense power is 47
	digitalWrite(powerPin, LOW); 	// power on the device --> LOW means power on
	delay(1000);

	if (Serial3.available() > 0)
		chemConfigLength = Serial3.readBytesUntil(36, chemConfigReading, 1516);
	else
		Serial3.end();
}

void ConfigBusSerial02(byte *parameters)
{
	return;
}

void EnableBusSerial02()
{
	return;
}

void DisableBusSerial02()
{
	return;
}

void ReadBusSerial02(byte *sensorReading, int *readingLength)
{
	ReadRS232(sensorReading, readingLength, 2);
}

void WriteBusSerial02(byte *sensorReading)
{
	return;
}