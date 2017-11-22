// Bus functions to set PWM through pin 06

#define PWM06 6

void InitBusPWM06(byte *parameters)
{
	pinMode(PWM06, OUTPUT);
}

void ConfigBusPWM06(byte *parameters)
{
	return;
}

void EnableBusPWM06()
{
	return;
}

void DisableBusPWM06()
{
	return;
}

void ReadBusPWM06(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM06(byte *parameters)
{
	int value = parameters[0] * 255;  // duty cycle * 255
	analogWrite(PWM06, value);
}