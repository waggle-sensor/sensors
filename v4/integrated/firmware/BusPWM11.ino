// Bus functions to set PWM through pin 11

#define PWM11 11

void InitBusPWM11(byte *parameters)
{
	pinMode(PWM11, OUTPUT);
}

void ConfigBusPWM11(byte *parameters)
{
	return;
}

void EnableBusPWM11()
{
	return;
}

void DisableBusPWM11()
{
	return;
}

void ReadBusPWM11(byte *sensorReading, int *readingLength)
{
	return;
}

void WriteBusPWM11(byte *parameters)
{
	int value = (parameters[0] * 255) / 100;  // duty cycle * 255
	analogWrite(PWM11, value);
}
