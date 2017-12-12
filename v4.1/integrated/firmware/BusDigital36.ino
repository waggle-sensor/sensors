// Bus functions to read value through digital pin 36

#define DigitalPin36 36

void InitBusDigital36(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin36, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin36, OUTPUT);
}

void ConfigBusDigital36(byte *parameters)
{
	return;
}

void EnableBusDigital36()
{
	return;
}

void DisableBusDigital36()
{
	return;
}

void ReadBusDigital36(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin36);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital36(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin36, value);
}