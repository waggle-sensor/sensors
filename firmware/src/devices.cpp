#include "devices.h"
#include <TMP112.h>
#include <HTU21D.h>
#include <Adafruit_BMP085_U.h>
#include <MMA8452Q.h>
#include <TSYS01.h>
#include <HMC5883L_waggle.h>
#include <HIH6130.h>
#include <MCP342X.h>
#include <LibTempTMP421.h>

// Analog-to-digital converter used by a number of different devices.
MCP342X mcp3428_1;
MCP342X mcp3428_2;

// TMP112
// Temperature sensor

TMP112 tmp112 = TMP112();

int initTMP112() {
	tmp112.TMP112_CONFIG();
	return 0;
}

int readTMP112() {
	auto temperature = tmp112.TMP112_read();
	SerialUSB.print(temperature);
	return 0;
}

// HTU21D
// Temperature and humidity sensor

HTU21D htu21d = HTU21D();

int initHTU21D() {
	return 0;
}

int readHTU21D() {
	auto temperature = htu21d.readTemperature();
	auto humidity = htu21d.readHumidity();

	SerialUSB.print(temperature);
	SerialUSB.print(" ");
	SerialUSB.print(humidity);

	return 0;
}

// BMP180
// Temperature and pressure sensor

Adafruit_BMP085_Unified bmp180 = Adafruit_BMP085_Unified(10085);

int initBMP180() {
	bmp180.begin();
	return 0;
}

int readBMP180() {
	sensors_event_t event;
	bmp180.getEvent(&event);

	if (event.pressure)
	{
		float temperature;
		bmp180.getTemperature(&temperature);

		float pressure;
		bmp180.getPressure(&pressure);

		SerialUSB.print(temperature);
		SerialUSB.print(" ");
		SerialUSB.print(pressure);
	}

	return 0;
}

// PR103J2
// ???

const int PR103J2_PIN = 0;

int initPR103J2() {
	pinMode(PR103J2_PIN, INPUT);
	return 0;
}

int readPR103J2() {
	auto value = analogRead(PR103J2_PIN);
	SerialUSB.print(value);
	return 0;
}

// TSL250
// ???

const int TSL250_PIN = 1;

int initTSL250() {
	pinMode(TSL250_PIN, INPUT);
	return 0;
}

int readTSL250() {
	auto value = analogRead(TSL250_PIN);
	SerialUSB.print(value);
	return 0;
}

// MMA8452Q
// Acceleration sensor

MMAQ mmaq = MMAQ();

int initMMA8452Q() {
	mmaq.MMA8452_CONFIG();
	return 0;
}

int readMMA8452Q() {
	float accelForce[4];
	mmaq.MMA8452_read(accelForce);

	for (int i = 0; i < 4; i++) {
		SerialUSB.print(accelForce[i]);
		SerialUSB.print(" ");
	}

	return 0;
}

// SPV1840
// ???

const int PIN_RAW_MIC = A9;

int initSPV1840() {
	pinMode(PIN_RAW_MIC, INPUT);
	return 0;
}

int readSPV1840() {
	long sum = 0;

	for (int i = 0; i < 100; i++) {
		long value = abs(512 - analogRead(PIN_RAW_MIC));
		sum += value;
		delay(1);
	}

	long avg = sum / 100L;

	SerialUSB.print(avg);

	return 0;
}

// TSYS01
// Temperature sensor

TSYS01 tsys = TSYS01();

int initTSYS01() {
	tsys.TSYS01_CONFIG();
	return 0;
}

int readTSYS01() {
	auto value = tsys.TSYS01GetTemp();
	SerialUSB.print(value);
	return 0;
}

// HMC5883L
// Magnetic field sensor

HMC5883_Sensor hmc5883 = HMC5883_Sensor(&Wire);

int initHMC5883L() {
	hmc5883.begin();
	return 0;
}

int readHMC5883L() {
	sensors_event_t event;
	hmc5883.getEvent(&event);

	SerialUSB.print(event.magnetic.x);
	SerialUSB.print(" ");
	SerialUSB.print(event.magnetic.y);
	SerialUSB.print(" ");
	SerialUSB.print(event.magnetic.z);

	return 0;
}

// HIH6130
// Temperature and humidity sensor

hih6130 hih6 = hih6130();

int initHIH6130() {
	return 0;
}

int readHIH6130() {
	float sensorValue[2];
	hih6.HIH_fetch_humidity_temperature(sensorValue);

	SerialUSB.print(sensorValue[0]);
	SerialUSB.print(" ");
	SerialUSB.print(sensorValue[1]);

	return 0;
}

// APDS9006
// ???

int initAPDS9006() {
	return 0;
}

int readAPDS9006() {
	mcp3428_2.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);

	auto value = mcp3428_2.readADC();
	SerialUSB.print(value);

	return 0;
}

// TSL260RD
// ???

int initTSL260RD() {
	return 0;
}

int readTSL260RD() {
	mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);

	auto value = mcp3428_1.readADC();
	SerialUSB.print(value);

	return 0;
}

// TSL250RD
// ???

int initTSL250RD() {
	return 0;
}

int readTSL250RD() {
	mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);

	auto value = mcp3428_1.readADC();
	SerialUSB.print(value);

	return 0;
}

// MLX75305
// ???

int initMLX75305() {
	return 0;
}

int readMLX75305() {
	mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);

	auto value = mcp3428_1.readADC();
	SerialUSB.print(value);

	return 0;
}

// ML8511
// ???

int initML8511() {
	return 0;
}

int readML8511() {
	mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);

	auto value = mcp3428_1.readADC();
	SerialUSB.print(value);

	return 0;
}

// TMP421
// Temperature sensor

LibTempTMP421 tmp421 = LibTempTMP421();

int initTMP421() {
	return 0;
}

int readTMP421() {
	auto value = tmp421.GetTemperature();
	SerialUSB.print(value);

	return 0;
}

int initChemsense() {
	Serial3.begin(115200);
}

bool isprefix(const char *str, const char *pre) {
	while (*pre != 0) {
		if (*pre != *str) {
			return false;
		}

		pre++;
		str++;
	}

	return true;
}

void sanitize(char *s) {
	while (*s != 0) {
		if (isspace(*s)) {
			*s = ' ';
		}

		s++;
	}
}

int readChemsense() {
	char buffer[256];
	int numlines = 0;
	Serial3.setTimeout(2500);

	while (1) {
		int len = Serial3.readBytesUntil('\n', buffer, 255);
		buffer[len] = 0;

		if (len < 10) {
			break;
		}

		if (!isprefix(buffer, "BAD=")) {
			continue;
		}

		numlines++;
		sanitize(buffer);
		SerialUSB.print(buffer);
	}

	if (numlines == 0) {
		SerialUSB.println();
		SerialUSB.println("! timed out");
	}
}

static const Device devices[] = {
	{"tmp112", initTMP112, readTMP112},
	{"htu21d", initHTU21D, readHTU21D},
	{"bmp180", initBMP180, readBMP180},
	{"pr103j2", initPR103J2, readPR103J2},
	{"tsl250", initTSL250, readTSL250},
	{"mma8452q", initMMA8452Q, readMMA8452Q},
	{"spv1840", initSPV1840, readSPV1840},
	{"tsys01", initTSYS01, readTSYS01},
	{"hmc5883l", initHMC5883L, readHMC5883L},
	{"hih6130", initHIH6130, readHIH6130},
	{"apds9006", initAPDS9006, readAPDS9006},
	{"tsl260rd", initTSL260RD, readTSL260RD},
	{"tsl250rd", initTSL250RD, readTSL250RD},
	{"mlx75305", initMLX75305, readMLX75305},
	{"ml8511", initML8511, readML8511},
	{"tmp421", initTMP421, readTMP421},
	{"chem", initChemsense, readChemsense},
};

static const int numdevices = sizeof(devices) / sizeof(devices[0]);

void InitDevices() {
	mcp3428_1.init(MCP342X::L, MCP342X::L);
	mcp3428_2.init(MCP342X::L, MCP342X::F);

	for (int i = 0; i < numdevices; i++) {
		const Device *dev = devices+i;

		if (dev->init != NULL) {
			dev->init();
		}
	}
}

const Device *FindDevice(const char *name) {
	for (int i = 0; i < numdevices; i++) {
		const Device *dev = devices+i;

		if (strcmp(dev->name, name) == 0) {
			return dev;
		}
	}

	return NULL;
}

void ListDevices() {
	SerialUSB.println("devices");

	for (int i = 0; i < numdevices; i++) {
		const Device *dev = devices+i;
		SerialUSB.println(dev->name);
	}

	SerialUSB.println();
}
