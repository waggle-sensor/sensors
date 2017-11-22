// Bus functions to set PWM through pin 02

#define PWM02 2

void InitBusPWM02(byte *parameters)
{
	pinMode(PWM02, OUTPUT);
}

void ConfigBusPWM02(byte *parameters)
{
	return;
}

void EnableBusPWM02()
{
	return;
}

void DisableBusPWM02()
{
	return;
}

void ReadBusPWM02(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM02(byte *parameters)
{
	int value = parameters[0] * 255;  // duty cycle * 255
	analogWrite(PWM02, value);
}