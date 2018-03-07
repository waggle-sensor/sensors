// Alpha sensor serial

void InitSensor29()
{
	InitSensor28();
}

void ConfigSensor29()
{
	return;
}

void EnableSensor29()
{
	EnableSensor(0x29);
}

void DisableSensor29()
{
	DisableSensor(0x29);
}

void ReadSensor29(byte *sensorReading, int *readingLength)
{
	delay(1000);
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x10);    // 0xF3
	delay(10);

	for (int i = 0; i < 20; i++)
	{
		sensorReading[i] = SPI.transfer(0x10);
		*readingLength += 1;
		delay(1);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void WriteSensor29(byte *packet)
{
	return;
}
