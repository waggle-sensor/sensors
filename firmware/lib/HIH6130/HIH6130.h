#include <Wire.h>

#define HIH_ADDRESS 0x27

class hih6130
{
public:
    void HIH_fetch_humidity_temperature(float* value);

private:
    byte Temp_byte[4];
    int Temp_int[2];
};