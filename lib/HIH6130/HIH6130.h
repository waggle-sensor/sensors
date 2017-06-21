#include <Wire.h>

#define HIH_ADDRESS 0x27

class Chih6130
{
public:
    void HIH_fetch_humidity_temperature(char* val);

private:
    byte Temp_byte[4];
    int Temp_int[2];
};