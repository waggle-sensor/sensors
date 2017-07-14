// #include <Arduino.h>
// #include <stdio.h>

#include "../../lib/TMP112/TMP112.h"
#include "../../lib/HTU21D/HTU21D.h"
#include "../../lib/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h"
#include "../../lib/MMA8452Q/MMA8452Q.h"
#include "../../lib/TSYS01/TSYS01.h"

#include "stringutils.h"

//MAC
// #define Mac 3087011

//PR103J2
#define A2D_PRJ103J2 0
//TSL250
#define A2D_TSL250RD_1 1
//SPV1840
#define PIN_RAW_MIC	A9

class Metsense
{
public:
	void readMet(byte id, int *NumVal, char *val);

	void writeMac(int32_t MLMac);

	void readMac(int* NumVal, char* val);
	void readTMP112(int* NumVal, char* val);
	void readHTU21D(int* NumVal, char* val);
	void readBMP180(int* NumVal, char* val);
	void readPR103J2(int* NumVal, char* val);
	void readTSL250(int* NumVal, char* val);

	void readMMA8452Q(int* NumVal, char* val);
	void readSPV1840(int* NumVal, char* val);
	void readTSYS01(int* NumVal, char* val);

private:
        
	Adafruit_BMP085_Unified bmpp = Adafruit_BMP085_Unified(10085);
	sensors_event_t event;

	TMP112 tmpp = TMP112();
    HTU21D htu = HTU21D();
	MMAQ mmaq = MMAQ();
	TSYS01 tsys = TSYS01(); 

	int32_t coreMac = 30817011;
	int reference;

    bool conf = false;
};