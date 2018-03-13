
//** I2C
void ReadI2C(byte address, int length, byte *out)
{
	ReadI2C(address, length, out, 0);
}

void ReadI2C(byte address, int length, byte *out, int time)
{
	Wire.beginTransmission(address);
	Wire.requestFrom(address, (byte)length);
	delay(time);

	if (Wire.available() > 0)
	{
		for (int i = 0; i < length; i++)
			out[i] = Wire.read();
	}
	else
	{
		for (int i = 0; i < length; i++)
			out[i] = 0xff;
	}
	Wire.endTransmission();
}

void DirectReadI2C(byte address, int length, byte *out, int time)
{
	Wire.requestFrom(address, (byte)length);
	delay(time);

	if (Wire.available() > 0)
	{
		for (int i = 0; i < length; i++)
			out[i] = Wire.read();
	}
	else
	{
		for (int i = 0; i < length; i++)
			out[i] = 0xff;
	}
}

void WriteI2C(byte address, int length, byte *in)
{
	Wire.beginTransmission(address);

	for (int i = 0; i < length; i++)
		Wire.write(in[i]);

	Wire.endTransmission();
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out)
{
	WriteReadI2C(address, inlength, in, outlength, out, 0);
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out, int time)
{
	Wire.beginTransmission(address);
	for (int i = 0; i < inlength; i++)
		Wire.write(in[i]);
	Wire.endTransmission();
	delay(time);

	Wire.requestFrom(address, (byte)outlength);
	if (Wire.available() > 0)
		for (int i = 0; i < outlength; i++)
			out[i] = Wire.read();
	else
		for (int i = 0; i < outlength; i++)
			out[i] = 0xff;
	// Wire.endTransmission();
}

//** SPI
SPISettings SetSPI(long maxSpeed, byte bitOrder, byte dataMode, byte pin)
{
	SPISettings set;
	if (bitOrder == 1)
	{
		if (dataMode == 0)
			set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE0);
		else if (dataMode == 1)
			set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE1);
		else if (dataMode == 2)
			set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE2);
		else if (dataMode == 3)
			set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE3);
	}
	else if (bitOrder == 0)
	{
		if (dataMode == 0)
			set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE0);
		else if (dataMode == 1)
			set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE1);
		else if (dataMode == 2)
			set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE2);
		else if (dataMode == 3)
			set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE3);
	}
	pinMode(pin, OUTPUT);

	return set;
}

void ReadSPI(byte* buff, int bufflen, byte pin, SPISettings set)
{
	ReadSPI(buff, bufflen, pin, set, 0, 0);
}

void ReadSPI(byte* buff, int bufflen, byte pin, SPISettings set, int msdelay, int delayiter)
{
	SPI.beginTransaction(set);
	delay(400);
	digitalWrite(pin, LOW);

	for (int i = 0; i < bufflen; i++)
	{
		SPI.transfer(buff[i]);

		if (i < delayiter)
			delay(msdelay);
	}

	digitalWrite(pin, HIGH);
	SPI.endTransaction();
}

void WriteSPI(byte* buff, int bufflen, byte pin, SPISettings set)
{
	WriteSPI(buff, bufflen, pin, set, 0, 0);
}

void WriteSPI(byte* buff, int bufflen, byte pin, SPISettings set, int msdelay, int delayiter)
{
	SPI.beginTransaction(set);
	delay(400);
	digitalWrite(pin, LOW);

	for (int i = 0; i < bufflen; i++)
	{
		buff[i] = SPI.transfer(buff[i]);

		if (i < delayiter)
			delay(msdelay);
	}

	digitalWrite(pin, HIGH);
	SPI.endTransaction();
}



//** EEPROM
#define EEPROM_ADDRESS 0x50

void writeEEPROM (unsigned int memory_address, byte data_byte )
{
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.write(data_byte);
    Wire.endTransmission();
    delay(5);
}

byte readEEPROM (unsigned int memory_address )
{
    byte recv_data = 0xff;

    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(memory_address >> 8));   // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(EEPROM_ADDRESS,1);

    if (Wire.available())
        recv_data = Wire.read();

    return recv_data;
}
