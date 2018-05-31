// Rain gauge

#define TRIDENT_POWER  38 // one of any ditial pins
#define DECAGON_DATARATE  1200

void InitSensor2D()
{
	Serial1.begin(DECAGON_DATARATE);	// begin serial3
	Serial1.setTimeout(5000);	// set timeout of serial1 as 5 sec
	pinMode(TRIDENT_POWER, OUTPUT);    // pin for providing power to soil moisture sensor, Decagon sensor
	delay(100);

	digitalWrite(TRIDENT_POWER, true); 	// power on the device --> LOW means power on
	delay(100);

	for (int i = 0; i < 5; i++)
	{
		if (Serial1.available() > 0)
			return;
	}

	Serial1.end();
	digitalWrite(TRIDENT_POWER, false);
	DisableSensor2D();
}

void ConfigSensor2D()
{
	return;
}

void EnableSensor2D()
{
	EnableSensor(0x2D);
}	

void DisableSensor2D()
{
	DisableSensor(0x2D);
}

void ReadSensor2D(byte *sensorReading, int *readingLength)
{
	digitalWrite(TRIDENT_POWER, true);
	delay(100);

	byte inputbyte;
	while (Serial1.available() > 0)   // Throw out redundant values from previous pair
		inputbyte = Serial1.read();

	int length = 0;
	int last = 0;
	byte buffer[256];
	for (int i = 0; i < 3; i++)
	{
		length = Serial1.readBytesUntil('\n', buffer, 256);

		for (int j = 0; j < length; j++)
			sensorReading[last + j] = buffer[j];

		last += length;
	}

	*readingLength = last;
	digitalWrite(TRIDENT_POWER, false);
}

void WriteSensor2D(byte *packet)
{
	return;
}
