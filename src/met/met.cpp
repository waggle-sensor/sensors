#include "met.h"

void CMet::MetGet(byte ID, int* NumVal, float* val, char** unit) 
{
	if (conf == false)
	{
		bmpp.begin();
		tmpp.TMP112_CONFIG();
		mmaq.MMA8452_CONFIG();
		tsys.TSYS01_CONFIG();

		pinMode(PIN_RAW_MIC,INPUT);
		conf = true;
	}

	// float_data[0] = .0;
	// float_data[1] = .0&;
	// long_data = 0;

	// SerialUSB.println("metsense board");
	
	// if (ID == 0x00)
	// 	MAC(NumVal, val, unit);
	// else if (ID == 0x01)
	if (ID == 0x01)
		TMP112(NumVal, val, unit);
	else if (ID == 0x02)
		HTU21D(NumVal, val, unit);
	else if (ID == 0x03)
		BMP180(NumVal, val, unit);
	else if (ID == 0x04)
		PR103J2(NumVal, val, unit);
	else if (ID == 0x05)
		TSL250(NumVal, val, unit);
	else if (ID == 0x06)
		MMA8452Q(NumVal, val, unit);
	else if (ID == 0x07)
		SPV1840(NumVal, val, unit);
	else if (ID == 0x08)
		TSYS01(NumVal, val, unit);
	else
		NumVal = 0;
}

// void CMet::MAC(int* NumVal, float* val, char** unit)
// {
// 	*NumVal = 1;
// 	unit[0] = "No unit";
// 	val[0] = 3087011;
// }

void CMet::TMP112(int* NumVal, float* val, char** unit) 
{
	*NumVal = 1;
	unit[0] = "C";
	val[0] = tmpp.TMP112_read();
}

void CMet::HTU21D(int* NumVal, float* val, char** unit) 
{
	*NumVal = 2;
	unit[0] = "C";
	unit[1] = "RH";
	val[0] = htuu.readTemperature();
	val[1] = htuu.readHumidity();
}

void CMet::BMP180(int* NumVal, float* val, char** unit) 
{
	*NumVal = 2;
	unit[0] = "C";
	unit[1] = "Pa";

	bmpp.getEvent(&event);
	if (event.pressure)
	{
		bmpp.getTemperature(&val[0]);
		val[1] = long(event.pressure);
	}
}

void CMet::PR103J2(int* NumVal, float* val, char** unit) 
{
	*NumVal = 1;
	unit[0] = "Raw";
	val[0] = analogRead(A2D_PRJ103J2);
}

void CMet::TSL250(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "Raw";
	val[0] = analogRead(A2D_TSL250RD_1);
	// SrlPrint(int_data, " VL Raw");
}

void CMet::MMA8452Q(int* NumVal, float* val, char** unit)
{
	*NumVal = 4;
	unit[0] = "gx";
	unit[1] = "gy";
	unit[2] = "gz";
	unit[3] = "avg g";

	mmaq.MMA8452_read(val); 
}

void CMet::SPV1840(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "sound Raw";
	val[0] = 0;

	for(int i = 0; i < 100; i++)
	{
		SPV_AMPV[i] = 512 - analogRead(PIN_RAW_MIC);
		if (SPV_AMPV[i] < 0)
			SPV_AMPV[i] = SPV_AMPV[i] * -1;
		delay(1);
	}

	for(int i = 0; i < 100; i++)
		val[0] = ((val[0] * i) + SPV_AMPV[i]) / (i+1);
}

void CMet::TSYS01(int* NumVal, float* val, char** unit)
{
	*NumVal = 1;
	unit[0] = "C";
	tsys.TSYS01_read(&val[0]);
}