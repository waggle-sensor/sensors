// PMS 7003 reading

void InitSensor36()
{
	Serial1.begin(9600);
	Serial1.setTimeout(5000);
	delay(1000);

	if (Serial1.available() <= 0)
		DisableSensor(0x36);
}

void ConfigSensor36()
{
	return;
}

void EnableSensor36()
{
	EnableSensor(0x36);
}

void DisableSensor36()
{
	DisableSensor(0x36);
}

void ReadSensor36(byte *sensorReading, int *readingLength)
{
	*readingLength = 30;
	int while_time = 0;
	while (while_time < 5000)
	{
		if (Serial1.available() >= 32)
		{
			char header1 = Serial1.read();
			char header2 = Serial1.read();
			if (header1 != 0x42 || header2 != 0x4D)
			{
			    while_time += 100;
			    continue;
			}
			else
			{
				*readingLength = 30;
				for (int i = 0; i < 30; i++)
					sensorReading[i] = Serial1.read();

				if (readingLength == 0)
				{
					*readingLength = 1;
					sensorReading[0] = 0xAB;
				}
				break;
			}
		}
	}

	*readingLength = 1;
	sensorReading[0] = 0xAB;
}

void WriteSensor36(byte *packet)
{
	return;
}
