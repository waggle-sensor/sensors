// Bus functions to set PWM through pin 01

#define PWM01 01

void InitBusPWM01(byte *parameters)
{
	pinMode(PWM01, OUTPUT);
}

void ConfigBusPWM01(byte *parameters)
{
	return;
}

void EnableBusPWM01()
{
	return;
}

void DisableBusPWM01()
{
	return;
}

void ReadBusPWM01(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM01(byte *parameters)
{
	int value = parameters[0] * 255;  // duty cycle * 255
	analogWrite(PWM01, value);
}