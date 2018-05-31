// Alpha sensor serial

void InitSensor29()
{
	return;
}

void ConfigSensor29()
{
	return;
}

void EnableSensor29()
{
	return;
}

void DisableSensor29()
{
	return;
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
		byte r = SPI.transfer(0x10);
		if (r == 0xFF)
			sensorReading[i] = 'N';
		else
			sensorReading[i] = r;

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
