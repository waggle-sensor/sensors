#include "spi.h"

// Function to talk with alpha sensor
void customSPI::alphaSetting()
{
	// SPI begin
    SPI.begin();
    delay(10);

    // Set a GPIO pin for alpha sensor slave select pin
    pinMode(PIN_ALPHASENSE_SLAVE, OUTPUT);

    set = SPISettings(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
}

// Function to talk with alpha sensor
void customSPI::alphaStartTrans()
{
	// SPI.beginTransaction(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
	SPI.beginTransaction(set);
	delay(100);
	digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
	
}

// Function to talk with alpha sensor
void customSPI::alphaEndTrans()
{
	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
	SPI.endTransaction();
}

char customSPI::readSPI(char Input)
{
	return SPI.transfer(Input);
}






///////////////////////////////////////////////////////////////////////////////////////////////////
// For general use
void customSPI::configSPI(int slavePin, long maxSpeed, int bitOrder, int dataMode)
{
	PIN_SLAVE = slavePin;

	if (bitOrder == 1)
		set = SPISettings(maxSpeed, MSBFIRST, dataMode);
	else
		set = SPISettings(maxSpeed, LSBFIRST, dataMode);

	pinMode(slavePin, OUTPUT);
}

char customSPI::readSPI(char* buff, int bufflen, int msdelay, int delayiter)
{
	SPI.beginTransaction(set);
	delay(100);
	digitalWrite(PIN_SLAVE, LOW);

	for (int i = 0; i < bufflen; i++)
	{
		buff[i] = SPI.transfer(buff[i]);
		if (i < delayiter)
			delay(msdelay);
	}

	digitalWrite(PIN_SLAVE, HIGH);
	SPI.endTransaction();
}