// PMS7003 particle sensor reading
#define LENG 32

char buf[LENG + LENG + 2];

void InitSensor54()
{
	Serial1.begin(9600);	// begin serial3
	Serial1.setTimeout(5000);	// set timeout of serial3 as 5 sec
	delay(100);

	for (int i = 0; i < 5; i++)
	{
		if (Serial1.available() > 0)
			return;
		delay(1000);
	}
	DisableSensor(0x36);
}

void ConfigSensor54()
{
	return;
}

void EnableSensor54()
{
	EnableSensor(0x36);
}

void DisableSensor54()
{
	DisableSensor(0x36);
}

void ReadSensor54(byte *sensorReading, int *readingLength)
{
	SerialUSB.println("PMS7003 read start");

	int delaytime = 0;
	while (Serial1.available() < (LENG + LENG) && delaytime < 500)
	{
		delay(10);
		delaytime += 10;
	}

	for (int i = 0; i < (LENG + LENG + 2); i++)
		buf[i] = Serial1.read();

	int startbyte = 255;
	for (int i = 0; i < (LENG + 1); i++)
	{
		if (buf[i] == 0x42 && buf[i+1] == 0x4D)
			startbyte = i;
	}

	if (startbyte == 255)
	{
		*readingLength = 1;
		sensorReading[0] = 0xAB;
	}
	else
	{
		for (int i = 0; i < LENG; i++)
			sensorReading[i] = buf[i + startbyte];
		*readingLength = LENG;
	}
}

void WriteSensor54(byte *packet)
{
	return;
}
