// SPV sound level sensor

void InitSensor08(byte *sensorReading, int *readingLength)
{
	pinMode(SPV_AMP_PIN,INPUT);  // Does this pin really work?
	pinMode(SPV_SPL_PIN,INPUT);  // Does this pin really work?
	pinMode(SPV_RAW_MIC_PIN,INPUT);
}

void ConfigSensor08(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor08(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x08);
}

void DisableSensor08(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x08);
}

void ReadSensor08(byte *sensorReading, int *readingLength)
{
	int buff = 0;
	for (int i = 0; i < 64; i++)
	{
		buff = analogRead(SPV_RAW_MIC_PIN);
		sensorReading[i * 2] = (buff >> 8) & 0xFF;
		sensorReading[i * 2 + 1] = buff & 0xFF;
		*readingLength += 2;
	}
}

void WriteSensor08(byte *sensorReading, int *readingLength)
{
	return;
}