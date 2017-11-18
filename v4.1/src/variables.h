// variables for all ino files...
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <OneWire.h>
#include "./buildinfo.h"

/* Only library among sensors */
#include "./MCP342X/MCP342X.h"
MCP342X mcp3428_1;
MCP342X mcp3428_2;
bool flagMCP1 = false;

// Wire
OneWire ds2401(48);

/* Firmware version */
// 4.1 1.00 initial version of v4.1
#define CORESENSE_HW_VER_MAJ 3 // 4 bits
#define CORESENSE_HW_VER_MIN 1 // 4 bits

#define CORESENSE_KERNEL_MAJ 4 // 8 bits
#define CORESENSE_KERNEL_MIN 1 // 4 bits
#define CORESENSE_KERNEL_SUB 0 // 4 bits


/* bus ADDRESSES of sensors, PIN configuration for analog/sensor power */
#define HBT_PIN 8  // HBEAT PIN (ON/OFF)
// Metsense
#define TMP112_ADDRESS 0x48
#define HTDU21D_ADDRESS 0x40
#define HIH4030_PIN A10
#define BMP180_ADDRESS 0x77
#define PRJ103J2_PIN 0
#define TSL250RDms_PIN 1
#define MMA8452_ADDRESS 0x1C
// below three lines are for sound level sensor
#define SPV_AMP_PIN A5
#define SPV_SPL_PIN A6
#define SPV_RAW_MIC_PIN A9
#define TSYS01_ADDRESS 0x76

// Lightsense
#define HMC5883_ADDESS 0x1E //byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x
#define HIH6130_ADDRESS 0x27
// below two lines are addresses for sensors using MCP3428 chip
byte MCP3428_1_ADDRESS = 0;
byte MCP3428_2_ADDRESS = 0;
#define TMP421_ADDRESS 0x4C

// Chemsense
#define CHEM_POWER_PIN 47

// Alphasensor
#define ALPHA_SLAVE_PIN 40

/* COEFFICIENTS */
byte BMP180_COEFFICIENTS[22];
byte TSYS01_COEFFICIENTS[10];
// byte HMC5883_COEFFICIENTS[4];  
//** coefficient for MHC is fixed as 1100 for x and y and 980 for z 
//** with regard to gain, which is also fixed as 0x20

/* store configuration info of Chemsense */
byte chemConfigReading[1516];
int chemConfigLength;

/* SPI setting for alpha sensor */
SPISettings setAlpha; //(SPI_MAX_speed, MSBFIRST, SPI_MODE1);