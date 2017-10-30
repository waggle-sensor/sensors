/*
  HIH6130.h - Library for reading relative humidity and temperature data 
  Created by David H Hagan, November 22, 2014
  
  Use as you like. MIT license.
*/

#ifndef HIH6130_h
#define HIH6130_h

#include <Arduino.h>

class HIH6130
{
  public:
    HIH6130(uint8_t address);
    void begin();
    void readRHT();

    double humidity;
    double temperature;

    
  private:
    uint8_t _address;
    uint8_t _humidity_lo, _humidity_hi;
    uint8_t _temp_lo, _temp_hi;
    uint8_t _status;
    //unsigned int _humidity_data, _temp_data;
};

#endif
