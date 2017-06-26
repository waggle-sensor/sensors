#include "HIH6130.h"

void Chih6130::HIH_fetch_humidity_temperature(char* val)
{
    Wire.beginTransmission(HIH_ADDRESS);
    Wire.endTransmission();
    delay(100);

    Wire.requestFrom((int)HIH_ADDRESS, (int) 4);


    bool able = true;
    if (Wire.available() <= 0)
        able = false;

    Temp_byte[1] = Wire.read();
    Temp_byte[2] = Wire.read();
    Temp_byte[3] = Wire.read();
    Temp_byte[4] = Wire.read();
    
    Wire.endTransmission();

    Temp_byte[0] = (Temp_byte[1] >> 6) & 0x03;

    Temp_byte[1] = Temp_byte[1] & 0x3f;
    Temp_int[0] = (((unsigned int)Temp_byte[1]) << 8) | Temp_byte[2];

    Temp_int[1] = (((unsigned int)Temp_byte[3]) << 8) | Temp_byte[4];
    Temp_int[1] = Temp_int[1] / 4;

    // Temperature
    val[0] = Temp_int[1] >> 8;
    val[1] = Temp_int[1] & 0xff;
    // Hummidity
    val[2] = Temp_int[0] >> 8;
    val[3] = Temp_int[0] & 0xff;

    // Humidity
    // val[1] = (float) Temp_int[0] * 6.10e-3;
    // Temperature
    // val[0] = (float) Temp_int[1] * 1.007e-2 - 40.0;

    if (able == false)
    {
        val[0] = 0xff;
        val[1] = 0xff;
        val[2] = 0xff;
        val[3] = 0xff;
    }
}