// PMS 7003 reading

#define LENG 32

void InitSensor36()
{
	Serial1.begin(9600);
	Serial1.setTimeout(5000);
	delay(1000);

	for (int i = 0; i < 10; i++)
	{
		if (Serial1.available() <= 0)
			DisableSensor(0x36);
	}
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
	*readingLength = 32;
	int while_time = 0;
	while (while_time < 5000)
	{
		if (Serial1.available() >= LENG*2)
		{
			for (int i = 0; i < LENG+1; i++)
			{
				char header1 = Serial1.read();
				char header2 = Serial1.read();
				if (header1 != 0x42 || header2 != 0x4D)
				{
					delay(100);
		    		while_time += 100;
		    		continue;
				}
				else
				{
					sensorReading[0] = header1;
					sensorReading[1] = header2;
					for (int i = 0; i < 30; i++)
						sensorReading[i+2] = Serial1.read();
					return;
				}
			}
		}
		else
		{
			delay(100);
			while_time += 100;
		}
	}

	for (int i = 0; i < 32; i++)
		sensorReading[i] = 0xAB;
}

void WriteSensor36(byte *packet)
{
	return;
}
