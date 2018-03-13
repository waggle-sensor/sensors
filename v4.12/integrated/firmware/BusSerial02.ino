// Bus function for Serial2 reading

void InitBusSerial02(byte *parameters)
{
	byte serial02powerPin = parameters[0];
	int baudrate = (parameters[1] << 16) | (parameters[2] << 8) | parameters[3];
	int timeout = parameters[4] * 1000; // parameter[4] in sec


	Serial2.begin(baudrate);	// begin serial3
	Serial2.setTimeout(timeout);	// set timeout of serial3 as 5 sec
	pinMode(serial02powerPin, OUTPUT);  // pin for chemsense power is 47
	digitalWrite(serial02powerPin, LOW); 	// power on the device --> LOW means power on
	delay(1000);

	if (Serial2.available() <= 0)
		Serial2.end();
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

	while (Serial2.available() > 0)
		inputbyte = Serial2.read();

	len = Serial2.readBytesUntil('\n', sensorReading, 256);

	if (readingLength == 0)
	{
		*readingLength = 1;
		sensorReading[0] = 0xAB;
	}
}

void WriteBusSerial02(byte *sensorReading)
{
	return;
}
