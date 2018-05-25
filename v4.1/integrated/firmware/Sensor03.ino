// HIH4030 Relative Humidity sensor

#define HIH4030_PIN A10

void InitSensor03()
{
	return;
}

void ConfigSensor03()
{
	return;
}

void EnableSensor03()
{
	
	EnableSensor(0x03);
}

void DisableSensor03()
{
	
	DisableSensor(0x03);
}

void ReadSensor03(byte *sensorReading, int *readingLength)
{
	int value = analogRead(HIH4030_PIN);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteSensor03(byte *packet)
{
	return;
}