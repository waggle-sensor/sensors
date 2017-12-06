// Bus functions to set PWM through pin 10

#define PWM10 10

void InitBusPWM10(byte *parameters)
{
	pinMode(PWM10, OUTPUT);
}

void ConfigBusPWM10(byte *parameters)
{
	return;
}

void EnableBusPWM10()
{
	return;
}

void DisableBusPWM10()
{
	return;
}

void ReadBusPWM10(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM10(byte *parameters)
{
	int value = (parameters[0] * 255) / 100;  // duty cycle * 255
	analogWrite(PWM10, value);
}
