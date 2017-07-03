#include "spi.h"

void Cspi::AlphaSetting()
{
	// SPI begin
    SPI.begin();
    delay(10);

    // Set a GPIO pin for alpha sensor slave select pin
    pinMode(PIN_ALPHASENSE_SLAVE, OUTPUT);

    set = SPISettings(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
}

void Cspi::writeMaxSpeed(long val)
{
	SPI_MAX_speed = val;
}

void Cspi::AlstartTrans()
{
	// SPI.beginTransaction(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
	SPI.beginTransaction(set);
	delay(100);
	digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
	
}

void Cspi::AlendTrans()
{
	digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
	SPI.endTransaction();
}

char Cspi::readSPI(char comm)
{
	return SPI.transfer(comm);
}


// #ifdef ALPHASENSE_INCLUDE    
//     SPI.begin();
//     delay(5000);
//     alphasense_off();
//     delay(5000);
//     alphasense_read_fan_laser_power();
//     delay(5000);
//     alphasense_on();    // power on laser and fan: Laser and fan must be on to get correct data
//     delay(10000);
//     alphasense_read_fan_laser_power();
//     alphasense_firmware();
//     alphasense_config();
//     delay(1000);

//     flag_alpha = true;

// #ifdef ALPHASENSE_INCLUDE
// void alphasense_on() 
// {
//     SPI.beginTransaction(set1);
//     digitalWrite(PIN_ALPHASENSE_SLAVE, LOW);
//     delay(100);

//     val1 = SPI.transfer(0x03);
//     delay(100);
//     val2 = SPI.transfer(0x00);
//     delay(100);
    
//     digitalWrite(PIN_ALPHASENSE_SLAVE, HIGH);
//     SPI.endTransaction();

// #ifdef ALPHA_DEBUG
//     SerialUSB.println("Powering OPC ON");
//     SerialUSB.println(val1, HEX);
//     SerialUSB.println(val2, HEX);
// #endif
// }