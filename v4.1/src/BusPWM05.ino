// Bus functions to set PWM through pin 05

#define PWM05 5

void InitBusPWM05(byte *parameters)
{
	pinMode(PWM05, OUTPUT);
}

void ConfigBusPWM05(byte *parameters)
{
	return;
}

void EnableBusPWM05()
{
	return;
}

void DisableBusPWM05()
{
	return;
}

void ReadBusPWM05(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM05(byte *parameters)
{
	int value = (parameters[0] * 255) / 100;  // duty cycle * 255
	analogWrite(PWM05, value);
}
