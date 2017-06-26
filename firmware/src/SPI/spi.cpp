#include "spi.h"


// //** alphasensor
// #ifdef ALPHASENSE_INCLUDE
// byte SPI_read_byte = 0;
// SPISettings set1(SPI_MAX_speed, MSBFIRST, SPI_MODE1);
// //** alphasensor which will be moved to down there and initialization (Jun 30)
// uint8_t val1, val2;

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