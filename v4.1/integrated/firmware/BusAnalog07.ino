// GP2Y out reading using bus function

#define AnalogPin07 A7

void InitBusAnalog07(byte *parameters)
{
	return;
}

void ConfigBusAnalog07(byte *parameters)
{
	return;
}

void EnableBusAnalog07()
{
	return;
}

void DisableBusAnalog07()
{
	return;
}

void ReadBusAnalog07(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin07);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog07(byte *parameters)
{
	return;
}