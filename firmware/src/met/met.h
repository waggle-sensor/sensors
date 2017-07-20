// #include <Arduino.h>
// #include <stdio.h>

#include "../../lib/TMP112/TMP112.h"
#include "../../lib/HTU21D/HTU21D.h"
#include "../../lib/Adafruit_BMP085_Unified-master/Adafruit_BMP085_U.h"
#include <MMA8452Q.h>
#include <TSYS01.h>
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

	void readMet(byte ID, int* NumVal, int* val);
	void readPR103J2(int* NumVal, int* val);
	void readTSL250(int* NumVal, int* val);

	void readMMA8452Q(int* NumVal, int* val);
	void readSPV1840(int* NumVal, int* val);
	void readTSYS01(int* NumVal, int* val);

private:

	Adafruit_BMP085_Unified bmpp = Adafruit_BMP085_Unified(10085);
	sensors_event_t event;
	MMAQ mmaq = MMAQ();
	TSYS01 tsys = TSYS01();
	int32_t coreMac = 30817011;
    bool conf = false;
};
