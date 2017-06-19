#include <Arduino.h>
#include <Wire.h>

//TSYS01
#define TSYS01Address 0x76  //address left shifted by arduino as required to match datasheet
#define TSYS01Reset 0x1E //initiates reset
#define TSYS01StartReg 0x48 //commands sensor to begin measurement / output calculation
#define TSYS01TempReg 0x00 //requests most recent output from measurement

typedef enum TSYS_KPoly_E //structure to hold calibration values from temperature sensor registers
{
    TSYS_K4 = 0,
    TSYS_K3,
    TSYS_K2,
    TSYS_K1,
    TSYS_K0
}
TSYS_KPoly_T;

class CTSYS01
{
public:
	void TSYS01_CONFIG();
	void TSYS01INIT();
	void TSYS_Get_Coeff();
	float TSYS_ScaleTemp_C(uint16_t rawAdc);
	void TSYS01_read(float *val);

private:	
	float retVal = 0.0;
	float Temp_float = 0.0;
	uint16_t TSYS_coefficents[5];
	byte Temp_byte[3];
};