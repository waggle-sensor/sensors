// TSL250 Light sensor

#define TSL250RDms_PIN 1

void InitSensor06()
{
	return;
}

void ConfigSensor06()
{
	return;
}

void EnableSensor06()
{
	EnableSensor(0x06);
}

void DisableSensor06()
{
	DisableSensor(0x06);
}

void ReadSensor06(byte *sensorReading, int *readingLength)
{
	int TSL250_1 = analogRead(TSL250RDms_PIN);

	sensorReading[0] = (TSL250_1 >> 8) & 0xFF;
	sensorReading[1] = TSL250_1 & 0xFF;

	*readingLength = 2;
}

void WriteSensor06(byte *packet)
{
	return;
}