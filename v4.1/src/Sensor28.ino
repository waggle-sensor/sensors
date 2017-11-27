// Alpha sensor histogram

// Alphasensor
#define ALPHA_SLAVE_PIN 40

void InitSensor28()
{
	if (!flagON)
	{
		// begin SPI
		setAlpha = SPISettings(5000000, MSBFIRST, SPI_MODE1);
		pinMode(ALPHA_SLAVE_PIN, OUTPUT);

		// SPI begin
		SPI.begin();
		delay(1000);

		alpha_onagain();
	}
	flagON = true;
}

void ConfigSensor28()
{
	return;
}

void EnableSensor28()
{
	EnableSensor(0x28);
}

void DisableSensor28()
{
	DisableSensor(0x28);
}

void ReadSensor28(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x30);   // 0xF3
	delay(10);

	for (int i = 0; i < 62; i++)
	{
		sensorReading[i] = SPI.transfer(0x30);
		*readingLength += 1;
		delay(1);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void WriteSensor28(byte *packet)
{
	return;
}

byte returnbyte;
void alpha_onagain()
{
	alphasense_on();
	alpha_status();

	// byte alphaStatusid = 0x2B;

	int repeat = 0;
	while ((returnbyte != 0x31) && (repeat < 5))
	{
		if (repeat != 0)
			delay(5000);
		repeat++;
		alphasense_on();
		delay(100);
		alpha_status();
	}
	// delay(1000);

	byte thisid = 0x28;
	if (returnbyte == 0x31)
		SensorEnable(thisid);
	else
		SensorDisable(thisid);
}

// Alphasense
void alphasense_on()   // initialization
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	returnbyte = SPI.transfer(0x03);
	delay(10);
	returnbyte = SPI.transfer(0x00);

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void alpha_status()   // initialization
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	returnbyte = SPI.transfer(0xCF);
	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void alphasense_off()   // disenable
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	returnbyte = SPI.transfer(0x03);
	delay(10);
	returnbyte = SPI.transfer(0x01);

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

