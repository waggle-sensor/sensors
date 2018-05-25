// Bus functions to read value through digital pin 38

#define DigitalPin38 38

void InitBusDigital38(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin38, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin38, OUTPUT);
}

void ConfigBusDigital38(byte *parameters)
{
	return;
}

void EnableBusDigital38()
{
	return;
}

void DisableBusDigital38()
{
	return;
}

void ReadBusDigital38(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin38);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital38(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin38, value);
}