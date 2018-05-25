// PR103J2 reading using bus function

#define AnalogPin00 A0

void InitBusAnalog00(byte *parameters)
{
	return;
}

void ConfigBusAnalog00(byte *parameters)
{
	return;
}

void EnableBusAnalog00()
{
	return;
}

void DisableBusAnalog00()
{
	return;
}

void ReadBusAnalog00(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin00);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog00(byte *parameters)
{
	return;
}