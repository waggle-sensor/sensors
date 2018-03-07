// Bus functions to read value through digital pin 37

#define DigitalPin37 37

void InitBusDigital37(byte *parameters)
{
	byte mode = parameters[0];
	if (mode == 0)
		pinMode(DigitalPin37, INPUT);
	else if (mode == 1)
		pinMode(DigitalPin37, OUTPUT);
}

void ConfigBusDigital37(byte *parameters)
{
	return;
}

void EnableBusDigital37()
{
	return;
}

void DisableBusDigital37()
{
	return;
}

void ReadBusDigital37(byte *sensorReading, int *readingLength)
{
	int value = digitalRead(DigitalPin37);

	sensorReading[0] = value & 0xFF;
	*readingLength = 1;
}

void WriteBusDigital37(byte *parameters)
{
	byte value = parameters[0];  // 0 or 1
	digitalWrite(DigitalPin37, value);
}