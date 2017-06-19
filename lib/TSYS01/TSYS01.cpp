#include "TSYS01.h"

void CTSYS01::TSYS01_CONFIG()
{
    TSYS01INIT();
    TSYS_Get_Coeff();
}

void CTSYS01::TSYS01INIT()
{
    Wire.beginTransmission(TSYS01Address);
    Wire.write(0x1E);
    Wire.endTransmission();
    delay(50);
}


void CTSYS01::TSYS_Get_Coeff()  //gathers calibration coefficients to array
{
    for (uint8_t n = 0; n < 5; n++)
    {
        Wire.beginTransmission(TSYS01Address);
        Wire.write(0xA2 + (n * 2));
        Wire.endTransmission();
        Wire.requestFrom(TSYS01Address, 2);
        uint8_t Ai = Wire.read();
        uint8_t Bi = Wire.read();
        uint16_t x = (uint16_t)Ai << 8;
        x += Bi;
        TSYS_coefficents[n] = x;
    }
}


float CTSYS01::TSYS_ScaleTemp_C(uint16_t rawAdc)
{

    retVal =
    (-2) * (float)TSYS_coefficents[TSYS_K4] * (float)pow(10, -21) * pow(rawAdc, 4) +
    4 * (float)TSYS_coefficents[TSYS_K3] * (float)pow(10, -16) * pow(rawAdc, 3) +
    (-2) * (float)TSYS_coefficents[TSYS_K2] * (float)pow(10, -11) * pow(rawAdc, 2) +
    1 * (float)TSYS_coefficents[TSYS_K1] * (float)pow(10, -6) * rawAdc +
    (-1.5) * (float)TSYS_coefficents[TSYS_K0] * (float)pow(10, -2);

    return retVal;
}


void CTSYS01::TSYS01_read(float *val)
{
    Wire.beginTransmission(TSYS01Address);
    Wire.write(TSYS01StartReg); //Start measurement process
    Wire.endTransmission();
    delay(10);

    Wire.beginTransmission(TSYS01Address);
    Wire.write(TSYS01TempReg); //Request measurement
    Wire.endTransmission();

    Wire.requestFrom(TSYS01Address,3); //read in 24 bit output

    bool able = true;
    if (Wire.available() <= 0)
        able = false;

    Temp_byte[0] = Wire.read();
    Temp_byte[1] = Wire.read();
    Temp_byte[2] = Wire.read(); //not used but necessary if 24bit conversion method is found (shifts below return 24bit output / 256 per TSYS01 datasheet conversion equations

    if (able == false)
    {
        for (int i = 0; i < 3; i++)
            Temp_byte[i] = 255;
    }

    *val = TSYS_ScaleTemp_C((((unsigned long)Temp_byte[0] << 8) | ((unsigned long)Temp_byte[1]))); //convert and cast to Temp with scaling equation
}