// ML8511 Light sensor -- UV

void InitSensor12()
{
	return;
}

void ConfigSensor12()
{
	return;
}

void EnableSensor12()
{
	EnableSensor(0x12);
}

void DisableSensor12()
{
	DisableSensor(0x12);
}

void ReadSensor12(byte *sensorReading, int *readingLength)
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
			*readingLength += 2;
		}
	}
}

void WriteSensor12(byte *packet)
{
	return;
}