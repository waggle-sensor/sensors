// Alpha sensor firmware version

void InitSensor30()
{
	InitSensor28();
}

void ConfigSensor30()
{
	EnableSensor(0x30);
}

void EnableSensor30()
{
	DisableSensor(0x30);
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

	returnbyte = SPI.transfer(0x12);    // 0xF3
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
