// HIH4030 Relative Humidity sensor

void InitSensor03(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensor03(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor03(byte *sensorReading, int *readingLength)
{
	
	EnableSensor(0x03);
}

void DisableSensor03(byte *sensorReading, int *readingLength)
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

void WriteSensor03(byte *sensorReading, int *readingLength)
{
	return;
}