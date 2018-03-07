// Chem sensor reading

#define CHEM_POWER_PIN 47

void InitSensor2A()
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
		digitalWrite(CHEM_POWER_PIN, HIGH);
		DisableSensor(0x2A);
	}
}

void ConfigSensor2A()
{
	return;
}

void EnableSensor2A()
{
	EnableSensor(0x2A);
}

void DisableSensor2A()
{
	DisableSensor(0x2A);
}

void ReadSensor2A(byte *sensorReading, int *readingLength)
{
	ReadRS232(sensorReading, readingLength);

	if (readingLength == 0)
	{
		*readingLength = 1;
		sensorReading[0] = 0xAB;
	}
}

void WriteSensor2A(byte *packet)
{
	return;
}
