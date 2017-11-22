// Bus functions to set PWM through pin 09

#define PWM09 9

void InitBusPWM09(byte *parameters)
{
	pinMode(PWM09, OUTPUT);
}

void ConfigBusPWM09(byte *parameters)
{
	return;
}

void EnableBusPWM09()
{
	return;
}

void DisableBusPWM09()
{
	return;
}

void ReadBusPWM09(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM09(byte *parameters)
{
	int value = parameters[0] * 255;  // duty cycle * 255
	analogWrite(PWM09, value);
}