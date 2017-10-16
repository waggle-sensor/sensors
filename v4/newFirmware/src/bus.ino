
//** I2C
void ReadI2C(char address, char *out)
{
	int length = sizeof(*out);
	SerialUSB.print("data: ");
	SerialUSB.println(length);

	Wire.beginTransmission(address);
	Wire.requestFrom(address, length);

	if (Wire.available() > 0) {
		for (int i = 0; i < length; i++) {
			out[i] = Wire.read();
		}
	} else {
		for (int i = 0; i < length; i++) {
			out[i] = 0xff;
		}
	}

	// TODO should return actual size read.

	Wire.endTransmission();
}


void ReadI2C(char address, char out)
{
	Wire.beginTransmission(address);
	Wire.requestFrom(address, 1);

	if (Wire.available() > 0)
		out = Wire.read();
	else
		out = 0xff;

	// TODO should return actual size read.

	Wire.endTransmission();
}

void WriteI2C(char address, char *in)
{
	int length = sizeof(*in);
	SerialUSB.print("data: ");
	SerialUSB.println(length);
	
	Wire.beginTransmission(address);

	for (int i = 0; i < length; i++) {
		Wire.write(in[i]);
	}

	Wire.endTransmission();
}

void WriteI2C(char address, char in)
{
	Wire.beginTransmission(address);
	Wire.write(in);
	Wire.endTransmission();
}

void BeginEndI2C(char address)
{
	Wire.beginTransmission(address);
	Wire.endTransmission();
}

//** RS232

void ConfigRS232(int port, long datarate, long timeout, int powerPin)
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

void ReadRS232(char* reading, int* NumVal, int port)
{
	int len = 0;
	char inputbyte;

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

void ReadRS232(char* reading, int sumlen)
{
	char inputbyte;
	while (Serial3.available() > 0)
		inputbyte = Serial3.read();

	int len = 0;
	sumlen = 0;
	for (int i = 0; i < 3; i++)
	{
		len = Serial3.readBytesUntil('\n', reading, 256);
		sumlen += len;
	}
}

void WriteRS232(char* writing, int length, int port)
{
	if (port == 3)
		Serial3.write(writing, length);
	else if (port == 2)
		Serial3.write(writing, length);
	else if (port == 1)
		Serial3.write(writing, length);
}

//** SPI

// void ConfigSPI(int slavePin, long maxSpeed, int bitOrder, int dataMode)
// {
// 	int PIN_SLAVE;
// 	SPISettings set;
// 	if (bitOrder == 1)
// 		set = SPISettings(maxSpeed, MSBFIRST, dataMode);
// 	else
// 		set = SPISettings(maxSpeed, LSBFIRST, dataMode);

// 	PIN_SLAVE = slavePin;
// 	pinMode(slavePin, OUTPUT);

// 	// SPI begin
// 	SPI.begin();
// }

// void ReadSPI(char* buff, int bufflen, int msdelay, int delayiter, int* pin)
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