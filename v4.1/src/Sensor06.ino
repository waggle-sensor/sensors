// TSL250 Light sensor

void InitSensor06(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensor06(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor06(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x06);
}

void DisableSensor06(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x06);
}

void ReadSensor06(byte *sensorReading, int *readingLength)
{
	int TSL250_1 = analogRead(TSL250RDms_PIN);

	sensorReading[0] = (TSL250_1 >> 8) & 0xFF;
	sensorReading[1] = TSL250_1 & 0xFF;

	*readingLength = 2;
}

void WriteSensor06(byte *sensorReading, int *readingLength)
{
	return;
}