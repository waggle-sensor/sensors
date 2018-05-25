// SPV Raw MIC reading using bus function

#define AnalogPin09 A9

void InitBusAnalog09(byte *parameters)
{
	return;
}

void ConfigBusAnalog09(byte *parameters)
{
	return;
}

void EnableBusAnalog09()
{
	return;
}

void DisableBusAnalog09()
{
	return;
}

void ReadBusAnalog09(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin09);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog09(byte *parameters)
{
	return;
}