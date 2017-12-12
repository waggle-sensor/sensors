// SPV Raw SPL reading using bus function

#define AnalogPin06 A6

void InitBusAnalog06(byte *parameters)
{
	return;
}

void ConfigBusAnalog06(byte *parameters)
{
	return;
}

void EnableBusAnalog06()
{
	return;
}

void DisableBusAnalog06()
{
	return;
}

void ReadBusAnalog06(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin06);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog06(byte *parameters)
{
	return;
}