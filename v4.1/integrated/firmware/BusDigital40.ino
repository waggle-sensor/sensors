// Bus functions to read value through digital pin 40

#define DigitalPin40 40

void InitBusDigital40(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin40, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin40, OUTPUT);
}

void ConfigBusDigital40(byte *parameters)
{
	return;
}

void EnableBusDigital40()
{
	return;
}

void DisableBusDigital40()
{
	return;
}

void ReadBusDigital40(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin40);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital40(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin40, value);
}