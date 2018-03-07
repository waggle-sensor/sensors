// Bus function for sensor reading using analogRead() through pin A02

#define AnalogPin02 A2

void InitBusAnalog02(byte *parameters)
{
	return;
}

void ConfigBusAnalog02(byte *parameters)
{
	return;
}

void EnableBusAnalog02()
{
	return;
}

void DisableBusAnalog02()
{
	return;
}

void ReadBusAnalog02(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin02);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog02(byte *parameters)
{
	return;
}