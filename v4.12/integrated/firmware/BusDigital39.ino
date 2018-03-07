// Bus functions to read value through digital pin 39

#define DigitalPin39 39

void InitBusDigital39(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin39, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin39, OUTPUT);
}

void ConfigBusDigital39(byte *parameters)
{
	return;
}

void EnableBusDigital39()
{
	return;
}

void DisableBusDigital39()
{
	return;
}

void ReadBusDigital39(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin39);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital39(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin39, value);
}