#include "spi.h"

// // Function to talk with alpha sensor
// void customSPI::alphaSetting()
// {
// 	// SPI begin
//     SPI.begin();
//     delay(10);

//     // Set a GPIO pin for alpha sensor slave select pin
//     pinMode(PIN_ALPHASENSE_SLAVE, OUTPUT);

//     set = SPISettings(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
// }

// // Function to talk with alpha sensor
// void customSPI::alphaStartTrans()
// {
// 	// SPI.beginTransaction(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
// 	SPI.beginTransaction(set);
// 	delay(100);
// 	digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
	
// }

// // Function to talk with alpha sensor
// void customSPI::alphaEndTrans()
// {
// 	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
// 	SPI.endTransaction();
// }

// char customSPI::readSPI(char Input)
// {
// 	return SPI.transfer(Input);
// }



void CustomSPI::configSPI(int slavePin, long maxSpeed, int bitOrder, int dataMode)
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

void CustomSPI::readSPI(char* buff, int bufflen, int msdelay, int delayiter, int* pin)
{
	*pin = PIN_SLAVE;
	
	SPI.beginTransaction(set);
	delay(400);
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