// Rain gauge

void InitSensor2C(byte *sensorReading, int *readingLength)
{
	// pinMode(RAIN_INTERRUPT_PIN, INPUT_PULLUP);
	// attachInterrupt(digitalPinToInterrupt(RAIN_INTERRUPT_PIN), blink, RISING);
	// delay(5);
	// pin_signal = 0;
	return;
}

void ConfigSensor2C(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensor2C(byte *sensorReading, int *readingLength)
{
	EnableSensor(0x2C);
}

void DisableSensor2C(byte *sensorReading, int *readingLength)
{
	DisableSensor(0x2C);
}

void ReadSensor2C(byte *sensorReading, int *readingLength)
{
    return;
}

void WriteSensor2C(byte *sensorReading, int *readingLength)
{
	return;
}

void blink()
{
	// pin_signal++;
	// if (pin_signal == 2)
	// {
	// 	count_num++;
	// 	pin_signal = 0;
	// }
}