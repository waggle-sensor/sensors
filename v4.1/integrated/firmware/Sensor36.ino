// PMS 7003 reading

#define LENG 32

void InitSensor36()
{
	Serial2.begin(9600);
	Serial2.setTimeout(5000);
	delay(1000);

	for (int i = 0; i < 10; i++)
	{
		if (Serial2.available() <= 0)
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
		if (Serial2.available() >= LENG)
		{
			for (int i = 0; i < LENG*3; i++)
			{
				char header1 = Serial2.read();
				char header2 = Serial2.read();
				if (header1 != 0x42 || header2 != 0x4D)
				{
					delay(10);
		    			while_time += 10;
		    			continue;
				}
				else
				{
					sensorReading[0] = header1;
					sensorReading[1] = header2;
					for (int j = 0; j < 30; j++)
						sensorReading[j+2] = Serial2.read();
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
	{
		if (i == 0 || i == 1)
			sensorReading[i] = 0xAB;
		else
			sensorReading[i] = 0;
	}
}

void WriteSensor36(byte *packet)
{
	return;
}
