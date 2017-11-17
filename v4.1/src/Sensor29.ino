// Alpha sensor serial

void InitSensor29(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensor29(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor29(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x29);
}

void DisableSensor29(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x29);
}

void ReadSensor29(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(129);

	SPI.transfer(0x10);    // 0xF3
	delay(10);

	for (int i = 0; i < 20; i++)
	{
		sensorReading[i] = SPI.transfer(0x10);
		*readingLength += 1;
		delay(10);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void WriteSensor29(byte *sensorReading, int *readingLength)
{
	return;
}