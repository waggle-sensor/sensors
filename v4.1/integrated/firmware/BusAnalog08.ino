// Bus function for sensor reading using analogRead() through pin A08

#define AnalogPin08 A8

void InitBusAnalog08(byte *parameters)
{
	return;
}

void ConfigBusAnalog08(byte *parameters)
{
	return;
}

void EnableBusAnalog08()
{
	return;
}

void DisableBusAnalog08()
{
	return;
}

void ReadBusAnalog08(byte *sensorReading, int *readingLength)
{
	int value = analogRead(AnalogPin08);

	sensorReading[0] = (value >> 8) & 0xFF;
	sensorReading[1] = value & 0xFF;

	*readingLength = 2;
}

void WriteBusAnalog08(byte *parameters)
{
	return;
}