// Chem sensor reading

#define CHEM_POWER_PIN 47

void InitSensor2A()
{
	Serial3.begin(115200);	// begin serial3
	Serial3.setTimeout(5000);	// set timeout of serial3 as 5 sec
	pinMode(CHEM_POWER_PIN, OUTPUT);  // pin for chemsense power is 47
	delay(100);
	digitalWrite(CHEM_POWER_PIN, LOW); 	// power on the device --> LOW means power on
	delay(1000);

	for (int i = 0; i < 5; i++)
	{
		if (Serial3.available() > 0)
		{
			chemConfigLength = Serial3.readBytesUntil(36, chemConfigReading, 1516);
			return;
		}
	}
	Serial3.end();
	digitalWrite(CHEM_POWER_PIN, HIGH);
	DisableSensor(0x2A);
}

void ConfigSensor2A()
{
	return;
}

void EnableSensor2A()
{
	EnableSensor(0x2A);
	digitalWrite(CHEM_POWER_PIN, LOW);
}

void DisableSensor2A()
{
	DisableSensor(0x2A);
	digitalWrite(CHEM_POWER_PIN, HIGH);
}

void ReadSensor2A(byte *sensorReading, int *readingLength)
{
	ReadRS232(sensorReading, readingLength);
}

void WriteSensor2A(byte *packet)
{
	return;
}
