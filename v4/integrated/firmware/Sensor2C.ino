// Rain gauge

#define RAIN_INTERRUPT_PIN      39
#define RAIN_MONITOR_PIN        A2

void InitSensor2C()
{
	pinMode(RAIN_INTERRUPT_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(RAIN_INTERRUPT_PIN), blink, RISING);
	delay(5);
	pin_signal = 0;
	count_num = 0;
	tip_count = 0;
}

void ConfigSensor2C()
{
	return;
}

void EnableSensor2C()
{
	EnableSensor(0x2C);
}

void DisableSensor2C()
{
	DisableSensor(0x2C);
}

void ReadSensor2C(byte *sensorReading, int *readingLength)
{
	if (count_num != 0 && tip_count == count_num) // no additional counts from the last count
		no_rain_check++;
	else if (no_rain_check != 0) // There is(are) additional count(s)
		no_rain_check = 0;

	if (no_rain_check == 3 && count_num == 1) // possible count error
		reset();
	if (no_rain_check == 72 && count_num != 0) // 10 mins (25 sec * 24), 30 mins (25 sec * 72), rain stopped
		reset();

	tip_count = count_num;

	sensorReading[0] = tip_count >> 8;
	sensorReading[1] = tip_count & 0xFF;

	*readingLength = 2;
}

void WriteSensor2C(byte *packet)
{
	return;
}

void reset()
{
	pin_signal = 0;
	count_num = 0;
	no_rain_check = 0;
}

void blink()
{
	pin_signal++;
	if (pin_signal == 3)
	{
		count_num++;
		pin_signal = 0;
	}
}