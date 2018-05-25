// Bus function for sensor reading using analogRead() through pin A03

#define AnalogPin03 A3

void InitBusAnalog03(byte *parameters)
{
	return;
}

void ConfigBusAnalog03(byte *parameters)
{
	return;
}

void EnableBusAnalog03()
{
	return;
}

void DisableBusAnalog03()
{
	return;
}

void ReadBusAnalog03(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin03);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog03(byte *parameters)
{
	return;
}