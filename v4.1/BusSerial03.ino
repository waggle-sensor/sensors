// Chem sensor reading through bus functions

void InitBusSerial3()
{
	Serial3.begin(115200);	// begin serial3
	Serial3.setTimeout(5000);	// set timeout of serial3 as 5 sec
	pinMode(CHEM_POWER_PIN, OUTPUT);  // pin for chemsense power is 47
	digitalWrite(CHEM_POWER_PIN, LOW); 	// power on the device --> LOW means power on
	delay(1000);

	if (Serial3.available() > 0)
		chemConfigLength = Serial3.readBytesUntil(36, chemConfigReading, 1516);
	else
	{
		Serial3.end();
		DisableSensor(0x2A);
	}
}

void ConfigBusSerial3()
{
	return;
}

void EnableBusSerial3()
{
	EnableSensor(0x2A);
}

void DisableBusSerial3()
{
	DisableSensor(0x2A);
}

void ReadBusSerial3(byte *sensorReading, int *readingLength)
{
	ReadRS232(sensorReading, readingLength);
}

void WriteBusSerial3(byte *sensorReading, int *readingLength)
{
	return;
}