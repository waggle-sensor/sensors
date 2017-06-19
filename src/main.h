#include <Arduino.h>
#include <Wire.h>
// #include <OneWire.h>
#include "scanner.h"
#include "stringutils.h"
#include "fmt.h"

#include "./util/findSensor.h"
#include "./met/met.h"
#include "./light/light.h"
#include "./chem/chem.h"
// OneWire ds(48);

#define PRINTF_BUF 256

#define PIN_CHEMSENSE_POW 47
#define CHEMSENSE_DATARATE 115200

#define MetLightMAC 3087011
#define MetSenNum 0x09
#define LightSenNum 0x08

#define TempSense 7
#define HumidSense 2
#define PresSense 1

float float_data[4];
int NumVal = 0;

char* unit[4];
char* sensorNM;

char chem_reading[PRINTF_BUF];
// bool chem_endline;
// const char* boardNM;

const byte tArray[TempSense] = {0x01, 0x02, 0x03, 0x04, 0x08, 0x11, 0x17};
const byte hArray[HumidSense] = {0x02, 0x11};
const byte pArray[PresSense] = {0x03};


Scanner scanner;
CSensor sensor;
CMet cmet;
CLight clight;
Cchem chem;