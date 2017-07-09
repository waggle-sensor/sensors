#include "met.h"

void Metsense::readMet(byte ID, int* NumVal, char* val) 
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
		readTMP112(NumVal, val);
	else if (ID == 0x02)
		readHTU21D(NumVal, val);
	else if (ID == 0x03)
		readBMP180(NumVal, val);
	else if (ID == 0x04)
		readPR103J2(NumVal, val);
	else if (ID == 0x05)
		readTSL250(NumVal, val);
	else if (ID == 0x06)
		readMMA8452Q(NumVal, val);
	else if (ID == 0x07)
		readSPV1840(NumVal, val);
	else if (ID == 0x08)
		readTSYS01(NumVal, val);
	else
		NumVal = 0;
}

void Metsense::writeMac(long MLMac)
{
	coreMac = MLMac;
}

void Metsense::readMac(long* MLMac)
{
	*MLMac = coreMac;
}

void Metsense::readTMP112(int* NumVal, char* val) 
{
	reference = tmpp.TMP112_read() * 100;
    val[0] = reference >> 8;
    val[1] = reference & 0xff;

	*NumVal = 2;
}

void Metsense::readHTU21D(int* NumVal, char* val) 
{
	reference = htu.readTemperature() * 100;
    val[0] = reference >> 8;
    val[1] = reference & 0xff;

	reference = htu.readHumidity() * 100;
    val[2] = reference >> 8;
    val[3] = reference & 0xff;

	*NumVal = 4;
}

void Metsense::readBMP180(int* NumVal, char* val) 
{
	float sensorValue;

	bmpp.getEvent(&event);
	if (event.pressure)
	{
		bmpp.getTemperature(&sensorValue);
		reference = sensorValue * 100;
	    val[0] = reference >> 8;
	    val[1] = reference & 0xff;
	    
		// long temp_press = long(event.pressure);
		bmpp.getPressure(&sensorValue);
		reference = (int)sensorValue;
		val[2] = reference >> 24;
		val[3] = reference >> 16;
		val[4] = reference >> 8;
		val[5] = reference & 0xff;		
	}

	*NumVal = 6;
}

void Metsense::readPR103J2(int* NumVal, char* val) 
{
	reference = analogRead(A2D_PRJ103J2);
	val[0] = reference >> 8;
	val[1] = reference & 0xff;	

	*NumVal = 2;
}

void Metsense::readTSL250(int* NumVal, char* val)
{
	reference = analogRead(A2D_TSL250RD_1);
	val[0] = reference >> 8;
	val[1] = reference & 0xff;	

	*NumVal = 2;
}

void Metsense::readMMA8452Q(int* NumVal, char* val)
{
	float magField[4];
	mmaq.MMA8452_read(magField);

	for (int i = 0; i < 4; i++)
	{
		reference = magField[i] * 100;

		val[i * 2] = reference >> 8;
		val[i * 2 + 1] = reference & 0xff;
	}

	*NumVal = 8;
}

void Metsense::readSPV1840(int* NumVal, char* val)
{
	for(int i = 0; i < 100; i++)
	{
		SPV_AMPV[i] = 512 - analogRead(PIN_RAW_MIC);
		if (SPV_AMPV[i] < 0)
			SPV_AMPV[i] = SPV_AMPV[i] * -1;
		delay(1);
	}

	for(int i = 0; i < 100; i++)
		reference = ((reference * i) + SPV_AMPV[i]) / (i+1);

	val[0] = reference >> 8;
	val[1] = reference & 0xff;

	*NumVal = 2;
}

void Metsense::readTSYS01(int* NumVal, char* val)
{
	reference = tsys.TSYS01GetTemp() * 100;
    val[0] = reference >> 8;
    val[1] = reference & 0xff;

	*NumVal = 2;
}