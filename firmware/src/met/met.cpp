#include "met.h"

void Metsense::readMet(byte ID, int* NumVal, int* val)
{
	// initialize libraries
	if (conf == false)
	{
		mmaq.MMA8452_CONFIG();
		tsys.TSYS01_CONFIG();

		pinMode(PIN_RAW_MIC,INPUT);
		conf = true;
	}

	// Call a function in accordance of sensor ID
	if (ID == 0x04)
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

void Metsense::readPR103J2(int* NumVal, int* val)
{
	val[0] = analogRead(A2D_PRJ103J2);
	*NumVal = 1;
}

void Metsense::readTSL250(int* NumVal, int* val)
{
	val[0] = analogRead(A2D_TSL250RD_1);
	*NumVal = 1;
}

void Metsense::readMMA8452Q(int* NumVal, int* val)
{
	float accelForce[4];
	mmaq.MMA8452_read(accelForce);

	for (int i = 0; i < 4; i++)
		val[i] = accelForce[i] * 100;

	*NumVal = 4;
}

void Metsense::readSPV1840(int* NumVal, int* val)
{
	val[0] = 0;
	long SPV_AMPV[100];

	for(int i = 0; i < 100; i++)
	{
		SPV_AMPV[i] = 512 - analogRead(PIN_RAW_MIC);
		if (SPV_AMPV[i] < 0)
			SPV_AMPV[i] = SPV_AMPV[i] * -1;
		delay(1);
	}

	for(int i = 0; i < 100; i++)
		val[0] = ((val[0] * i) + SPV_AMPV[i]) / (i+1);

	*NumVal = 1;
}

void Metsense::readTSYS01(int* NumVal, int* val)
{
	val[0] = tsys.TSYS01GetTemp() * 100;
	*NumVal = 1;
}
