#include <Arduino.h>
#include <stdio.h>

#include "../../lib/TMP112/TMP112.h"
#include "../../lib/HTU21D/HTU21D.h"
#include "../../lib/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h"
#include "../../lib/MMA8452Q/MMA8452Q.h"
#include "../../lib/TSYS01/TSYS01.h"

#include "stringutils.h"

//MAC
#define mac 318711

//PR103J2
#define A2D_PRJ103J2 0
//TSL250
#define A2D_TSL250RD_1 1
//SPV1840
#define PIN_RAW_MIC	A9

class CMet
{
public:
	void MetGet(byte id, int *NumVal, char *val);

	void TMP112(int* NumVal, char* val);
	void HTU21D(int* NumVal, char* val);
	void BMP180(int* NumVal, char* val);
	void PR103J2(int* NumVal, char* val);
	void TSL250(int* NumVal, char* val);

	void MMA8452Q(int* NumVal, char* val);
	void SPV1840(int* NumVal, char* val);
	void TSYS01(int* NumVal, char* val);

private:
        
	Adafruit_BMP085_Unified bmpp = Adafruit_BMP085_Unified(10085);
	sensors_event_t event;

	CTMP112 tmpp = CTMP112();
    CHTU21D htuu = CHTU21D();
	CMMAQ mmaq = CMMAQ();
	CTSYS01 tsys = CTSYS01(); 

    int temp;
	long SPV_AMPV[100];
    bool conf = false;
};