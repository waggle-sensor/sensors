// HIH4030 Humidity sensor reading using bus function

#define AnalogPin10 A10

void InitBusAnalog10(byte *parameters)
{
	return;
}

void ConfigBusAnalog10(byte *parameters)
{
	return;
}

void EnableBusAnalog10()
{
	return;
}

void DisableBusAnalog10()
{
	return;
}

void ReadBusAnalog10(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin10);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog10(byte *parameters)
{
	return;
}