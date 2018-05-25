// Alpha sensor firmware version

void InitSensor30()
{
	return;
}

void ConfigSensor30()
{
	return;
}

void EnableSensor30()
{
	return;
}

void DisableSensor30()
{
	return;
}

void ReadSensor30(byte *sensorReading, int *readingLength)
{
	delay(1000);
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x12);    // 0xF3
	delay(10);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = SPI.transfer(0x12);
		*readingLength += 1;
		delay(1);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void WriteSensor30(byte *packet)
{
	return;
}
