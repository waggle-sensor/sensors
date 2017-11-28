// variables for all ino files...
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <OneWire.h>
#include "./DueTimer/DueTimer.h" //** TIMER3 library
#include "./buildinfo.h"

#include "./Sensor0D-11.h"
#include "./Sensor2A.h"
#include "./Sensor28-31.h"
// Wire
OneWire ds2401(48);

bool flagON;

/* bus ADDRESSES of sensors, PIN configuration for analog/sensor power */
