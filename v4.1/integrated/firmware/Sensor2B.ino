// Alpha sensor serial

#define ALPHA_SLAVE_PIN 40

void InitSensor2B()
{
	return;
}

void ConfigSensor2B()
{
	return;
}

void EnableSensor2B()
{
	return;
}

void DisableSensor2B()
{
	return;
}

void ReadSensor2B(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0xCF);
	delay(10);

	for (int i = 0; i < 5; i++)
	{
		sensorReading[i] = SPI.transfer(0xCF);
		*readingLength += 1;
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void WriteSensor2B(byte *packet)
{
	return;
}
