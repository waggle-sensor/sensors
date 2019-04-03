#include <Arduino.h>
#include <Wire.h>

#define MMA8452_ADDRESS 0x1C
#define maxInputLength 6

const byte MSG_FRAME = 0x7e;
const byte MSG_ESC = 0x7d;

int writeFrame(byte *b, int n) {
  for (int i = 0; i < n; i++) {
    if ((b[i] == MSG_FRAME) || (b[i]) == MSG_ESC) {
      SerialUSB.write(MSG_ESC);
      SerialUSB.write(b[i] ^ 0x20);
    } else {
      SerialUSB.write(b[i]);
    }
  }

  SerialUSB.write(MSG_FRAME);

  return n;
}

unsigned long lastSampleTime;
const unsigned long samplesPerSecond = 800;
const unsigned long sampleInterval = (1000 * 1000) / (samplesPerSecond); 

byte sensorReading[maxInputLength];

void setup() {
  lastSampleTime = micros();

  Wire.begin();
  delay(100);
  SerialUSB.begin(115200);

  // put your setup code here, to run once:
  const byte XYZ_DATA_CFG = 0x0E;
  const byte CTRL_REG1 = 0x2A;
  // const byte WHO_AM_I = 0x0D;
  const byte GSCALE = 2;
  // Sets full-scale range to +/-2, 4, or 8g


  // //** check if the sensor is correct
  // byte writebyte[1] = {WHO_AM_I};
  // byte id[1];
  // WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 1, id, false);
  // if (id[0] != 0x2A) // WHO_AM_I should always be 0x2A
  //  byte MMA8452_validity = 0;

  //*** sensor stand by
  byte readbyte[1];
  byte writebyte[1] = {CTRL_REG1};
  WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 1, readbyte, false);
  
  // Clear the active bit to go into standby
  int a = int(readbyte[0]) & ~(0x01);
  byte writearray[2] = {CTRL_REG1, byte(a)};
  WriteI2C(MMA8452_ADDRESS, 2, writearray);

  //** Set up the full scale range to 2, 4, or 8g.
  byte fsr = GSCALE;
  if(fsr > 8) 
      fsr = 8; //Easy error check
  // Neat trick, see page 22. 00 = 2G, 01 = 4A, 10 = 8G
  fsr >>= 2;
  
  //** set up accelerometer scale as 2G, default data rate 800Hz
  writearray[0] = XYZ_DATA_CFG;
  writearray[1] = fsr;
  WriteI2C(MMA8452_ADDRESS, 2, writearray);

  //*** active sensor--> Set the active bit to begin detection
  writebyte[0] = CTRL_REG1;
  WriteReadI2C(MMA8452_ADDRESS, 1, writebyte, 1, readbyte, false);
  writearray[0] = CTRL_REG1;
  writearray[1] = readbyte[0] | 0x01;
  WriteI2C(MMA8452_ADDRESS, 2, writearray);
}

const byte OUT_X_MSB = 0x01;

void loop() {
//  while (micros() - lastSampleTime < sampleInterval) {
//    delayMicroseconds(1);
//  }

  delayMicroseconds(117); // ~ 975 Hz, which works
  // delayMicroseconds(320); // ~ 800 Hz, which works

  Wire.requestFrom((uint8_t)MMA8452_ADDRESS, (uint8_t)6, (uint32_t)OUT_X_MSB, (uint8_t)1, true);
  lastSampleTime = micros();

  while (Wire.available() < 6) {
    delayMicroseconds(1);
  }

  for (int i = 0; i < 6; i++) {
    sensorReading[i] = Wire.read();
  }

  writeFrame(sensorReading, 6);
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out, int time)
{
  Wire.beginTransmission(address);

  for (int i = 0; i < inlength; i++) {
    Wire.write(in[i]);
  }

  Wire.endTransmission();
  delay(time);

  Wire.requestFrom(address, (byte)outlength);
  if (Wire.available() > 0)
    for (int i = 0; i < outlength; i++)
      out[i] = Wire.read();
  else
    for (int i = 0; i < outlength; i++)
      out[i] = 0xff;
  // Wire.endTransmission();
}

void WriteI2C(byte address, int length, byte *in)
{
  Wire.beginTransmission(address);

  for (int i = 0; i < length; i++)
    Wire.write(in[i]);

  Wire.endTransmission();
}
