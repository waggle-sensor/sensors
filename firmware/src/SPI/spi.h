#include <Arduino.h>
#include <SPI.h>

#define PIN_ALPHASENSE_SLAVE 40


// #define SPI_MAX_speed 500000

class Cspi
{
public:
	void setting();
	void startTrans();
	void endTrans();
	void readSPI(char comm, char* val);

private:
	long SPI_MAX_speed = 500000;
	SPISettings set1;

	// SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);

// //** alphasensor
// #ifdef ALPHASENSE_INCLUDE
// byte SPI_read_byte = 0;
// //** alphasensor which will be moved to down there and initialization (Jun 30)
// uint8_t val1, val2;

};