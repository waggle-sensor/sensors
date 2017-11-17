// PR103J2 Temperature sensor

void InitSensor05(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensor05(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor05(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x05);
}

void DisableSensor05(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x05);
}

void ReadSensor05(byte *sensorReading, int *readingLength)
{
	int PR = analogRead(PRJ103J2_PIN);

	sensorReading[0] = (PR >> 8) & 0xFF;
	sensorReading[1] = PR & 0xFF;

	*readingLength = 2;
}

void WriteSensor05(byte *sensorReading, int *readingLength)
{
	return;
}