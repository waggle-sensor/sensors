// Bus functions to read value through digital pin 33

#define DigitalPin33 33

void InitBusDigital33(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin33, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin33, OUTPUT);
}

void ConfigBusDigital33(byte *parameters)
{
	return;
}

void EnableBusDigital33()
{
	return;
}

void DisableBusDigital33()
{
	return;
}

void ReadBusDigital33(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin33);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital33(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin33, value);
}