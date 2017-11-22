// Bus functions to read value through digital pin 35

#define DigitalPin35 35

void InitBusDigital35(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin35, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin35, OUTPUT);
}

void ConfigBusDigital35(byte *parameters)
{
	return;
}

void EnableBusDigital35()
{
	return;
}

void DisableBusDigital35()
{
	return;
}

void ReadBusDigital35(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin35);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital35(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin35, value);
}