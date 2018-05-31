// TSL250RD on metsense board reading using bus function

#define AnalogPin01 A1

void InitBusAnalog01(byte *parameters)
{
	return;
}

void ConfigBusAnalog01(byte *parameters)
{
	return;
}

void EnableBusAnalog01()
{
	return;
}

void DisableBusAnalog01()
{
	return;
}

void ReadBusAnalog01(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin01);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog01(byte *parameters)
{
	return;
}