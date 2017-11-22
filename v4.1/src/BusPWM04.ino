// Bus functions to set PWM through pin 04

#define PWM04 4

void InitBusPWM04(byte *parameters)
{
	pinMode(PWM04, OUTPUT);
}

void ConfigBusPWM04(byte *parameters)
{
	return;
}

void EnableBusPWM04()
{
	return;
}

void DisableBusPWM04()
{
	return;
}

void ReadBusPWM04(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM04(byte *parameters)
{
	int value = parameters[0] * 255;  // duty cycle * 255
	analogWrite(PWM04, value);
}