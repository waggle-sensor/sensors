// Bus functions to read value through digital pin 34

#define DigitalPin34 34

void InitBusDigital34(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin34, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin34, OUTPUT);
}

void ConfigBusDigital34(byte *parameters)
{
	return;
}

void EnableBusDigital34()
{
	return;
}

void DisableBusDigital34()
{
	return;
}

void ReadBusDigital34(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin34);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital34(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin34, value);
}