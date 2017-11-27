// Alpha sensor serial

#define ALPHA_SLAVE_PIN 40

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
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	returnbyte = SPI.transfer(0xCF);
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