
//** I2C
void ReadI2C(byte address, int length, byte *out)
{
	Wire.beginTransmission(address);
	Wire.requestFrom(address, (byte)length);

	if (Wire.available() > 0) {
		for (int i = 0; i < length; i++) {
			out[i] = Wire.read();
		}
	} else {
		for (int i = 0; i < length; i++) {
			out[i] = 0xff;
		}
	}
	Wire.endTransmission();
}

void WriteI2C(byte address, int length, byte *in)
{
	Wire.beginTransmission(address);

	for (int i = 0; i < length; i++) {
		Wire.write(in[i]);
	}

	Wire.endTransmission();
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out)
{
	WriteReadI2C(address, inlength, in, outlength, out, 0, true);
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out, int time)
{
	WriteReadI2C(address, inlength, in, outlength, out, time, true);
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out, bool end)
{
	WriteReadI2C(address, inlength, in, outlength, out, 0, end);
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out, int time, bool end)
{
	Wire.beginTransmission(address);
	for (int i = 0; i < inlength; i++)
		Wire.write(in[i]);
	Wire.endTransmission(end);
	delay(time);

	Wire.requestFrom(address, (byte)outlength);
	if (Wire.available() > 0)
		for (int i = 0; i < outlength; i++)
			out[i] = Wire.read();
	else
		for (int i = 0; i < outlength; i++)
			out[i] = 0xff;
	Wire.endTransmission();
}

void WriteReadI2C(byte address, int outlength, byte *out, int time)
{
	Wire.beginTransmission(address);
	Wire.endTransmission();
	delay(time);

	Wire.requestFrom(address, (byte)outlength);
	if (Wire.available() > 0)
		for (int i = 0; i < outlength; i++)
			out[i] = Wire.read();
	else
		for (int i = 0; i < outlength; i++)
			out[i] = 0xff;
	Wire.endTransmission();
}

//** RS232
void InitRS232(int port, int powerPin, long datarate, long timeout)
{
	if (port == 3)
	{
		Serial3.begin(datarate);
		Serial3.setTimeout(timeout); //ms
		pinMode(powerPin, OUTPUT); // Set a GPIO pin
		digitalWrite(powerPin, LOW); // LOW means power on
		delay(500);
	}
	else if (port == 2)
	{
		Serial2.begin(datarate);
		Serial2.setTimeout(timeout);
		pinMode(powerPin, OUTPUT);
		digitalWrite(powerPin, LOW);
		delay(500);
	}
	else if (port == 1)
	{
		Serial1.begin(datarate);
		Serial1.setTimeout(timeout);
		pinMode(powerPin, OUTPUT);
		digitalWrite(powerPin, LOW);
		delay(500);
	}
}


byte inputbyte;
void ReadRS232(byte* reading, int* NumVal, int port)
{
	int len = 0;

	if (port == 3)
	{
		while (Serial3.available() > 0)
			inputbyte = Serial3.read();

		len = Serial3.readBytesUntil('\n', reading, 256);
	}

	else if (port == 2)
	{
		while (Serial2.available() > 0)
			inputbyte = Serial2.read();

		len = Serial2.readBytesUntil('\n', reading, 256);
	}

	else if (port == 1)
	{
		while (Serial1.available() > 0)
			inputbyte = Serial1.read();
		len = Serial1.readBytesUntil('\n', reading, 256);
	}

	reading[len] = '\0';
	*NumVal = len;
}

void ReadRS232(byte* reading, int *sumlen)
{
	while (Serial3.available() > 0)
		inputbyte = Serial3.read();

	int len = 0;
	for (int i = 0; i < 3; i++)
	{
		len = Serial3.readBytesUntil('\n', reading, 256);
		*sumlen += len;

		// SerialUSB.print("this is :");
		// SerialUSB.print(i);
		// SerialUSB.print("th reading, with length ");
		// SerialUSB.println(len);
		// for (int i = 0; i < len; i++)
		// 	SerialUSB.println(reading[i]);
	}
	// SerialUSB.println("EEENNNNNDDDDD");
}

void WriteRS232(byte* writing, int length, int port)
{
	if (port == 3)
		Serial3.write(writing, length);
	else if (port == 2)
		Serial3.write(writing, length);
	else if (port == 1)
		Serial3.write(writing, length);
}

//** SPI

int PIN_SLAVE;
SPISettings set;

void InitSPI(int slavePin, long maxSpeed, int bitOrder, int dataMode)
{
	if (bitOrder == 1)
		set = SPISettings(maxSpeed, MSBFIRST, dataMode);
	else
		set = SPISettings(maxSpeed, LSBFIRST, dataMode);

	PIN_SLAVE = slavePin;
	pinMode(slavePin, OUTPUT);

	// SPI begin
	SPI.begin();
}

void ReadSPI(char* buff, int bufflen, int msdelay, int delayiter, int* pin)
{
	*pin = PIN_SLAVE;
	
	// get set with regard to pin_slave#

	SPI.beginTransaction(set);
	delay(400);
	digitalWrite(PIN_SLAVE, LOW);

	for (int i = 0; i < bufflen; i++)
	{
		SPI.transfer(buff[i]);

		if (i < delayiter)
			delay(msdelay);
	}

	digitalWrite(PIN_SLAVE, HIGH);
	SPI.endTransaction();
}


// void WriteSPI(char* buff, int bufflen, int msdelay, int delayiter, int* pin)
// {
// 	*pin = PIN_SLAVE;
	
// 	SPI.beginTransaction(set);
// 	delay(400);
// 	digitalWrite(PIN_SLAVE, LOW);

// 	for (int i = 0; i < bufflen; i++)
// 	{
// 		buff[i] = SPI.transfer(buff[i]);

// 		if (i < delayiter)
// 			delay(msdelay);
// 	}

// 	digitalWrite(PIN_SLAVE, HIGH);
// 	SPI.endTransaction();
// }



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
