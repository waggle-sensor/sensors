
void InitSensor32()
{
	return;
}

void ConfigSensor32()
{
	return;
}

void EnableSensor32()
{
	EnableSensor(0x32);
}

void DisableSensor32()
{
	DisableSensor(0x32);
}

void ReadSensor32(byte *sensorReading, int *readingLength)
{
	int j = 0;
	for (int i = 0; i < numEnabled; i++)
	{
		EnabledTable *et = enabledtable + i;
		if (et->enabled == false)
		{
			int a = et->enabledsensorid;
			char b[2];
			itoa(a, b, 16);
			sensorReading[j++] = b[0];
			sensorReading[j++] = b[1];
			sensorReading[j++] = ',';
			*readingLength += 3;
		}
	}
}

void WriteSensor32(byte *packet)
{
	return;
}