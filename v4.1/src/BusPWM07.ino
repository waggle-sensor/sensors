// Bus functions to set PWM through pin 07

#define PWM07 7

void InitBusPWM07(byte *parameters)
{
	pinMode(PWM07, OUTPUT);
}

void ConfigBusPWM07(byte *parameters)
{
	return;
}

void EnableBusPWM07()
{
	return;
}

void DisableBusPWM07()
{
	return;
}

void ReadBusPWM07(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM07(byte *parameters)
{
	int value = (parameters[0] * 255) / 100;  // duty cycle * 255
	analogWrite(PWM07, value);
}
