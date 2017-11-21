
// HIH6130 Temperature and relative humidity sensor

#define HIH6130_ADDRESS 0x27

void InitSensor0B()
{
	return;
}

void ConfigSensor0B()
{
	return;
}

void EnableSensor0B()
{
	EnableSensor(0x0B);
}

void DisableSensor0B()
{
	DisableSensor(0x0B);
}

void ReadSensor0B(byte *sensorReading, int *readingLength)
{
	byte readarray[4];
	DirectReadI2C(HIH6130_ADDRESS, 4, readarray, 10);

	for (int i = 0; i < 4; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}
}

void WriteSensor0B(byte *packet)
{
	return;
}