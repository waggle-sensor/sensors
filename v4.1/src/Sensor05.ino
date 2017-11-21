// PR103J2 Temperature sensor

#define PRJ103J2_PIN 0

void InitSensor05()
{
	return;
}

void ConfigSensor05()
{
	return;
}

void EnableSensor05()
{
	EnableSensor(0x05);
}

void DisableSensor05()
{
	DisableSensor(0x05);
}

void ReadSensor05(byte *sensorReading, int *readingLength)
{
	int PR = analogRead(PRJ103J2_PIN);

	sensorReading[0] = (PR >> 8) & 0xFF;
	sensorReading[1] = PR & 0xFF;

	*readingLength = 2;
}

void WriteSensor05(byte *packet)
{
	return;
}