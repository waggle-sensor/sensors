#include <Arduino.h>
#include <SPI.h>

// #define PIN_ALPHASENSE_SLAVE 40
// #define SPI_MAX_speed 500000

class CustomSPI
{
public:
	// void alphaSetting();
	// void alphaStartTrans();
	// void alphaEndTrans();
	// char readSPI(char Input);

	void configSPI(int slavePin, long maxSpeed, int bitOrder, int dataMode);

	void readSPI(char* buff, int bufflen, int msdelay, int delayiter, int* slavePin);

private:
	// long SPI_MAX_speed = 500000;
	// long SPI_MAX_speed = 11;

	int PIN_SLAVE;
	SPISettings set;

	// SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);

// //** alphasensor
// #ifdef ALPHASENSE_INCLUDE
// byte SPI_read_byte = 0;
// //** alphasensor which will be moved to down there and initialization (Jun 30)
// uint8_t val1, val2;

};