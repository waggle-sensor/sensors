#include "i2c.h"
#include <TMP112.h>
#include <HTU21D.h>

static TMP112 tmp112 = TMP112();

static void initTMP112() {
	tmp112.TMP112_CONFIG();
}

static void readTMP112() {
	SerialUSB.print(tmp112.TMP112_read());
}

static HTU21D htu21d = HTU21D();

static void readHTU21D()
{
	SerialUSB.print(htu21d.readTemperature());
	SerialUSB.print(" ");
	SerialUSB.print(htu21d.readHumidity());
}

// static void readBMP180(int* NumVal, int* val)
// {
// 	float sensorValue;
//
// 	bmpp.getEvent(&event);
// 	if (event.pressure)
// 	{
// 		bmpp.getTemperature(&sensorValue);
// 		val[0] = sensorValue * 100;
//
// 		bmpp.getPressure(&sensorValue);
// 		val[1] = (int32_t)sensorValue;
// 	}
//
// 	*NumVal = 2;
// }
//
// static void readPR103J2(int* NumVal, int* val)
// {
// 	val[0] = analogRead(A2D_PRJ103J2);
// 	*NumVal = 1;
// }
//
// static void readTSL250(int* NumVal, int* val)
// {
// 	val[0] = analogRead(A2D_TSL250RD_1);
// 	*NumVal = 1;
// }
//
// static void readMMA8452Q(int* NumVal, int* val)
// {
// 	float accelForce[4];
// 	mmaq.MMA8452_read(accelForce);
//
// 	for (int i = 0; i < 4; i++)
// 		val[i] = accelForce[i] * 100;
//
// 	*NumVal = 4;
// }
//
// static void readSPV1840(int* NumVal, int* val)
// {
// 	val[0] = 0;
// 	long SPV_AMPV[100];
//
// 	for(int i = 0; i < 100; i++)
// 	{
// 		SPV_AMPV[i] = 512 - analogRead(PIN_RAW_MIC);
// 		if (SPV_AMPV[i] < 0)
// 			SPV_AMPV[i] = SPV_AMPV[i] * -1;
// 		delay(1);
// 	}
//
// 	for(int i = 0; i < 100; i++)
// 		val[0] = ((val[0] * i) + SPV_AMPV[i]) / (i+1);
//
// 	*NumVal = 1;
// }
//
// static void readTSYS01(int* NumVal, int* val)
// {
// 	val[0] = tsys.TSYS01GetTemp() * 100;
// 	*NumVal = 1;
// }

void CustomI2C::readI2C(char address, int length, char* out)
{
	Wire.beginTransmission(address); // start transmission to device
	Wire.requestFrom(address, length);// send data n-bytes read
	if (Wire.available() > 0)
	{
		for (int i = 0; i < length; i++)
			out[i] = Wire.read(); // receive DATA
	}
	else
	{
		for (int i = 0; i < length; i++)
			out[i] = 0xff;
	}
	Wire.endTransmission(); // end transmission
}

void CustomI2C::writeI2C(char address, int length, char* in)
{
	Wire.beginTransmission(address); // start transmission to device
	for (int i = 0; i < length; i++)
		Wire.write(in[i]); // sends register address to read from
	Wire.endTransmission();
}

static const I2CDevice devices[] = {
	{"mac", 0x00, NULL, NULL},
	{"tmp112", 0x01, initTMP112, readTMP112},
	{"htu21d", 0x02, NULL, readHTU21D},
	{"bmp180", 0x03, NULL, NULL},
	{"pr103j2", 0x04, NULL, NULL},
	{"tsl250", 0x05, NULL, NULL},
	{"mma8452q", 0x06, NULL, NULL},
	{"spv1840", 0x07, NULL, NULL},
	{"tsys01", 0x08, NULL, NULL},
	{"hmc5883l", 0x10, NULL, NULL},
	{"hih6130", 0x11, NULL, NULL},
	{"apds9006", 0x12, NULL, NULL},
	{"tsl260rd", 0x13, NULL, NULL},
	{"tsl250rd", 0x14, NULL, NULL},
	{"mlx75305", 0x15, NULL, NULL},
	{"ml8511", 0x16, NULL, NULL},
	{"tmp421", 0x17, NULL, NULL},
};

static const int numdevices = sizeof(devices) / sizeof(devices[0]);

void InitI2CDevices() {
	Wire.begin();
	delay(10);

	for (int i = 0; i < numdevices; i++) {
		const I2CDevice *dev = devices+i;

		if (dev->init) {
			dev->init();
		}
	}
}

const I2CDevice *FindI2CDevice(const char *name) {
	for (int i = 0; i < numdevices; i++) {
		const I2CDevice *dev = devices+i;

		if (strcmp(dev->name, name) == 0) {
			return dev;
		}
	}

	return NULL;
}

// Adafruit_BMP085_Unified bmpp = Adafruit_BMP085_Unified(10085);
// sensors_event_t event;
// MMAQ mmaq = MMAQ();
// TSYS01 tsys = TSYS01();
// int32_t coreMac = 30817011;
// bool conf = false;
// bmpp.begin();
// tmpp.TMP112_CONFIG();
// mmaq.MMA8452_CONFIG();
// tsys.TSYS01_CONFIG();
//
// pinMode(PIN_RAW_MIC,INPUT);
// conf = true;
