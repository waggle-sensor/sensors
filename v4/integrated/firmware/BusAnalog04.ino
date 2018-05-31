// GP2Y in using bus function

#define AnalogPin04 A4

void InitBusAnalog04(byte *parameters)
{
	return;
}

void ConfigBusAnalog04(byte *parameters)
{
	return;
}

void EnableBusAnalog04()
{
	return;
}

void DisableBusAnalog04()
{
	return;
}

void ReadBusAnalog04(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin04);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog04(byte *parameters)
{
	return;
}