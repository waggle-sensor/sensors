// Alpha sensor firmware version

void InitSensor30(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensor30(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x30);
}

void EnableSensor30(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x30);
}

void DisableSensor30(byte *sensorReading, int *readingLength)
{
	return;
}

void ReadSensor30(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	returnbyte = SPI.transfer(0x12);    // 0xF3
	delay(10);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = SPI.transfer(0x12);
		*readingLength += 1;
		delay(10);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void WriteSensor30(byte *sensorReading, int *readingLength)
{
	return;
}