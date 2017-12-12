// SPV Raw AMP reading using bus function

#define AnalogPin05 A5

void InitBusAnalog05(byte *parameters)
{
	return;
}

void ConfigBusAnalog05(byte *parameters)
{
	return;
}

void EnableBusAnalog05()
{
	return;
}

void DisableBusAnalog05()
{
	return;
}

void ReadBusAnalog05(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin05);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog05(byte *parameters)
{
	return;
}