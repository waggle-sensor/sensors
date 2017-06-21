#include "TMP112.h"

void CTMP112::TMP112_CONFIG()
{
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire.write(0x60);  // write data
    Wire.write(0xB0);  // write data
    Wire.endTransmission(); // end transmission
    delay(100);
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.write(TMP112_CONFIG_REG); // sends register address to read from
    Wire.endTransmission(); // end transmission
    delay(100);
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.requestFrom(I2C_TMP112, 2);// send data n-bytes read
    Temp_byte[0] = Wire.read(); // receive DATA
    Temp_byte[1] = Wire.read();// receive DATA
    Wire.endTransmission(); // end transmission
}

void CTMP112::TMP112_read(char* val)
{
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.write(TMP112_TEMP_REG); // sends register address to read from
    Wire.endTransmission(); // end transmission
    delay(100);
    Wire.beginTransmission(I2C_TMP112); // start transmission to device
    Wire.requestFrom(I2C_TMP112, 2);// send data n-bytes read

    bool able = true;

    if (Wire.available() <= 0)
        able = false;

    val[0] = Wire.read(); // receive DATA
    val[1] = Wire.read();// receive DATA
    Wire.endTransmission(); // end transmission

    // if ((val[0] & 0x80) == 0x00)
    // {
    //     // it is a positive temperature
    //     Temp_uint16 = val[0];
    //     Temp_uint16 = Temp_uint16 << 5;
    //     Temp_uint16 = Temp_uint16 | (val[1] >> 3);
    //     Temp_float = (Temp_uint16 & 0x0FFF) * 0.0625;
    // }
    // else
    // {
    //     val[0] = ~val[0];
    //     val[1] = ~val[1];
    //     Temp_uint16 = val[0];
    //     Temp_uint16 = Temp_uint16 << 5;
    //     Temp_uint16 = Temp_uint16 | (val[1] >> 3);
    //     Temp_float = (Temp_uint16 & 0x0FFF)*-0.0625;
    // }

    if (able == false)
    {
        val[0] = 0xff;
        val[1] = 0xff;
    }

    // return Temp_float;
}