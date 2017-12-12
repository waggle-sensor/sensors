// Bus function for sensor reading using analogRead() through pin A11

#define AnalogPin11 A11

void InitBusAnalog11(byte *parameters)
{
	return;
}

void ConfigBusAnalog11(byte *parameters)
{
	return;
}

void EnableBusAnalog11()
{
	return;
}

void DisableBusAnalog11()
{
	return;
}

void ReadBusAnalog11(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin11);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog11(byte *parameters)
{
	return;
}