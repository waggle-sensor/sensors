// HIH6130 Temperature and relative humidity sensor

void InitSensor0B(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensor0B(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor0B(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x0B);
}

void DisableSensor0B(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x0B);
}

void ReadSensor0B(byte *sensorReading, int *readingLength)
{
	byte readarray[4];
	DirectReadI2C(HIH6130_ADDRESS, 4, readarray, 10B);

	for (int i = 0; i < 4; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}
}

void WriteSensor0B(byte *sensorReading, int *readingLength)
{
	return;
}