#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
// #include <OneWire.h>

#include "scanner.h"
#include "stringutils.h"
#include "fmt.h"

#include "./util/findSensor.h"
#include "./met/met.h"
#include "./light/light.h"
#include "./chem/chem.h"
#include "./SPI/spi.h"
// OneWire ds(48);

#define PRINTF_BUF 256

#define PIN_CHEMSENSE_POW 47
#define CHEMSENSE_DATARATE 115200

#define MetSenNum 0x09
#define LightSenNum 0x08

long SensorBoardsMac;
int NumVal = 0;
char dataReading[PRINTF_BUF];
char InputComm;

Scanner scanner;
CSensor sensor;
CMet cmet;
CLight clight;
Cchem chem;
Cspi cspi;
