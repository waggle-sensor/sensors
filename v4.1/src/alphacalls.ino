

void InitAlphasensor()
{
	// begin SPI
	setAlpha = SPISettings(5000000, MSBFIRST, SPI_MODE1);
	pinMode(ALPHA_SLAVE_PIN, OUTPUT);

	// SPI begin
	SPI.begin();
	delay(1000);

 	alpha_onagain();
}

byte returnbyte;
void alpha_onagain()
{
	alphasense_on();
	alpha_status();

	byte alphaStatusid = 0x2B;

	int repeat = 0;
	while ((returnbyte != 0x31) && (repeat < 10))
	{
		repeat++;
		alphasense_on();
		alpha_status();
		// SerialUSB.println(returnbyte);
		// SerialUSB.println("Alphasensor");
		delay(5000);
	}
	delay(1000);

	if (returnbyte == 0x31)
	{
		// byte sensorReading[2];
		// int readingLength;
		// ReadAlphaFWver(sensorReading, &readingLength);
		// Packetization(0x30, sensorReading, readingLength);
		Packetization(alphaStatusid, 0x01);
	}
	else
		Packetization(alphaStatusid, 0x00);
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

void ReadAlphaFWver(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	returnbyte = SPI.transfer(0x12);    // 0xF3
	delay(10);

	for (int i = 0; i < 2; i++)
	{
		sensorReading[i] = SPI.transfer(0x12);
		*readingLength += 1;
		delay(10);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void ReadAlphaSerial(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x10);    // 0xF3
	delay(10);

	for (int i = 0; i < 20; i++)
	{
		sensorReading[i] = SPI.transfer(0x10);
		*readingLength += 1;
		delay(10);
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();
}

void ReadAlphaHisto(byte *sensorReading, int *readingLength)
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


void ReadAlphaConfig(byte *sensorReading, int *readingLength)
{
	SPI.beginTransaction(setAlpha);
	digitalWrite(ALPHA_SLAVE_PIN, LOW);
	delay(100);

	SPI.transfer(0x3C);   // 0xF3
	delay(10);

	for (int i = 0; i < 256; i++)
	{
		sensorReading[i] = SPI.transfer(0x3C);
		delay(10);
		*readingLength += 1;
	}

	digitalWrite(ALPHA_SLAVE_PIN, HIGH);
	SPI.endTransaction();

}