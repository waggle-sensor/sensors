// Bus functions to set PWM through pin 08

#define PWM08 8

void InitBusPWM08(byte *parameters)
{
	pinMode(PWM08, OUTPUT);
}

void ConfigBusPWM08(byte *parameters)
{
	return;
}

void EnableBusPWM08()
{
	return;
}

void DisableBusPWM08()
{
	return;
}

void ReadBusPWM08(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM08(byte *parameters)
{
	int value = (parameters[0] * 255) / 100;  // duty cycle * 255
	analogWrite(PWM08, value);
}
