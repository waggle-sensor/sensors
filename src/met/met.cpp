#include "met.h"

void CMet::MetGet(byte ID, int* NumVal, char* val) 
{
	// initialize libraries
	if (conf == false)
	{
		bmpp.begin();
		tmpp.TMP112_CONFIG();
		mmaq.MMA8452_CONFIG();
		tsys.TSYS01_CONFIG();

		pinMode(PIN_RAW_MIC,INPUT);
		conf = true;
	}
	
	// Call a function in accordance of sensor ID
	if (ID == 0x01)
		TMP112(NumVal, val);
	else if (ID == 0x02)
		HTU21D(NumVal, val);
	else if (ID == 0x03)
		BMP180(NumVal, val);
	else if (ID == 0x04)
		PR103J2(NumVal, val);
	else if (ID == 0x05)
		TSL250(NumVal, val);
	else if (ID == 0x06)
		MMA8452Q(NumVal, val);
	else if (ID == 0x07)
		SPV1840(NumVal, val);
	else if (ID == 0x08)
		TSYS01(NumVal, val);
	else
		NumVal = 0;
}

void CMet::TMP112(int* NumVal, char* val) 
{
	*NumVal = 2;
	tmpp.TMP112_read(val);
}

void CMet::HTU21D(int* NumVal, char* val) 
{
	*NumVal = 4;
	htuu.readTemperature(val);
	htuu.readHumidity(val);
}

void CMet::BMP180(int* NumVal, char* val) 
{
	*NumVal = 8;

	bmpp.getEvent(&event);
	if (event.pressure)
	{
		bmpp.getTemperature(val);
		long temp_press = long(event.pressure);
		// bmpp.getPressure(val);
	
		val[4] = temp_press >> 24;
		val[5] = temp_press >> 16;
		val[6] = temp_press >> 8;
		val[7] = temp_press & 0xff;		
	}
}

void CMet::PR103J2(int* NumVal, char* val) 
{
	*NumVal = 2;
	temp = analogRead(A2D_PRJ103J2);

	val[0] = temp >> 8;
	val[1] = temp & 0xff;	
}

void CMet::TSL250(int* NumVal, char* val)
{
	*NumVal = 2;
	temp = analogRead(A2D_TSL250RD_1);

	val[0] = temp >> 8;
	val[1] = temp & 0xff;	
}

void CMet::MMA8452Q(int* NumVal, char* val)
{
	*NumVal = 6;
	mmaq.MMA8452_read(val); 
}

void CMet::SPV1840(int* NumVal, char* val)
{
	*NumVal = 2;
	temp = 0;

	for(int i = 0; i < 100; i++)
	{
		SPV_AMPV[i] = 512 - analogRead(PIN_RAW_MIC);
		if (SPV_AMPV[i] < 0)
			SPV_AMPV[i] = SPV_AMPV[i] * -1;
		delay(1);
	}

	for(int i = 0; i < 100; i++)
		temp = ((temp * i) + SPV_AMPV[i]) / (i+1);

	val[0] = temp >> 8;
	val[1] = temp & 0xff;
}

void CMet::TSYS01(int* NumVal, char* val)
{
	*NumVal = 4;
	tsys.TSYS01_read(&val[0]);
}