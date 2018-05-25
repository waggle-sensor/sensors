// Bus functions to set PWM through pin 12

#define PWM12 12

void InitBusPWM12(byte *parameters)
{
	pinMode(PWM12, OUTPUT);
}

void ConfigBusPWM12(byte *parameters)
{
	return;
}

void EnableBusPWM12()
{
	return;
}

void DisableBusPWM12()
{
	return;
}

void ReadBusPWM12(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM12(byte *parameters)
{
	int value = (parameters[0] * 255) / 100;  // duty cycle * 255
	analogWrite(PWM12, value);
}
