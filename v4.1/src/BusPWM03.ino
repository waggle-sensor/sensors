// Bus functions to set PWM through pin 03

#define PWM03 3

void InitBusPWM03(byte *parameters)
{
	pinMode(PWM03, OUTPUT);
}

void ConfigBusPWM03(byte *parameters)
{
	return;
}

void EnableBusPWM03()
{
	return;
}

void DisableBusPWM03()
{
	return;
}

void ReadBusPWM03(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM03(byte *parameters)
{
	int value = parameters[0] * 255;  // duty cycle * 255
	analogWrite(PWM03, value);
}