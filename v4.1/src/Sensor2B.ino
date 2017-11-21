// Alpha sensor serial

void InitSensor2B()
{
	InitSensor28();
}

void ConfigSensor2B()
{
	return;
}

void EnableSensor2B()
{
	EnableSensor(0x2B);
}

void DisableSensor2B()
{
	DisableSensor(0x2B);
}

void ReadSensor2B(byte *sensorReading, int *readingLength)
{
	byte alphaStatus = alphastatus();
	sensorReading[0] = alphaStatus;
	*readingLength = 1;
}

void WriteSensor2B(byte *packet)
{
	return;
}