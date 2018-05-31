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
	EnableSensor(0x29);
	EnableSensor(0x2B);
	EnableSensor(0x30);
	EnableSensor(0x31);
}
	
void DisableSensor28()
{
	DisableSensor(0x28);
	DisableSensor(0x29);
	DisableSensor(0x2B);
	DisableSensor(0x30);
	DisableSensor(0x31);
}

void ReadSensor28(byte *sensorReading, int *readingLength)
{
	delay(1000);
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

void alpha_onagain()
{
	byte returnbyte;

	alphasense_on();
	returnbyte = alpha_status();

	// byte alphaStatusid = 0x2B;

	int repeat = 0;
	while ((returnbyte != 0x31) && (repeat < 5))
	{
		if (repeat != 0)
			delay(5000);
		repeat++;
		alphasense_on();
		delay(100);
		returnbyte = alpha_status();

		if (returnbyte != 0x31)
			DisableSensor28();
		else
			EnableSensor28();
	}
}

// Alphasense
void alphasense_on()   // initialization
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	SPI.transfer(0x03);
	delay(10);
	SPI.transfer(0x00);

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

byte alpha_status()   // initialization
{
	byte returnbyte;

	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	returnbyte = SPI.transfer(0xCF);
	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();

	return returnbyte;
}

void alphasense_off()   // disenable
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);

	SPI.transfer(0x03);
	delay(10);
	SPI.transfer(0x01);

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}
