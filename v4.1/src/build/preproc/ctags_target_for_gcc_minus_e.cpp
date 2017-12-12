# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog00.ino"
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog00.ino"
// PR103J2 reading using bus function



void InitBusAnalog00(byte *parameters)
{
 return;
}

void ConfigBusAnalog00(byte *parameters)
{
 return;
}

void EnableBusAnalog00()
{
 return;
}

void DisableBusAnalog00()
{
 return;
}

void ReadBusAnalog00(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A0);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog00(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog01.ino"
// TSL250RD on metsense board reading using bus function



void InitBusAnalog01(byte *parameters)
{
 return;
}

void ConfigBusAnalog01(byte *parameters)
{
 return;
}

void EnableBusAnalog01()
{
 return;
}

void DisableBusAnalog01()
{
 return;
}

void ReadBusAnalog01(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A1);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog01(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog02.ino"
// Bus function for sensor reading using analogRead() through pin A02



void InitBusAnalog02(byte *parameters)
{
 return;
}

void ConfigBusAnalog02(byte *parameters)
{
 return;
}

void EnableBusAnalog02()
{
 return;
}

void DisableBusAnalog02()
{
 return;
}

void ReadBusAnalog02(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A2);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog02(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog03.ino"
// Bus function for sensor reading using analogRead() through pin A03



void InitBusAnalog03(byte *parameters)
{
 return;
}

void ConfigBusAnalog03(byte *parameters)
{
 return;
}

void EnableBusAnalog03()
{
 return;
}

void DisableBusAnalog03()
{
 return;
}

void ReadBusAnalog03(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A3);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog03(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog04.ino"
// GP2Y in using bus function



void InitBusAnalog04(byte *parameters)
{
 return;
}

void ConfigBusAnalog04(byte *parameters)
{
 return;
}

void EnableBusAnalog04()
{
 return;
}

void DisableBusAnalog04()
{
 return;
}

void ReadBusAnalog04(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A4);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog04(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog05.ino"
// SPV Raw AMP reading using bus function



void InitBusAnalog05(byte *parameters)
{
 return;
}

void ConfigBusAnalog05(byte *parameters)
{
 return;
}

void EnableBusAnalog05()
{
 return;
}

void DisableBusAnalog05()
{
 return;
}

void ReadBusAnalog05(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A5);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog05(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog06.ino"
// SPV Raw SPL reading using bus function



void InitBusAnalog06(byte *parameters)
{
 return;
}

void ConfigBusAnalog06(byte *parameters)
{
 return;
}

void EnableBusAnalog06()
{
 return;
}

void DisableBusAnalog06()
{
 return;
}

void ReadBusAnalog06(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A6);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog06(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog07.ino"
// GP2Y out reading using bus function



void InitBusAnalog07(byte *parameters)
{
 return;
}

void ConfigBusAnalog07(byte *parameters)
{
 return;
}

void EnableBusAnalog07()
{
 return;
}

void DisableBusAnalog07()
{
 return;
}

void ReadBusAnalog07(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A7);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog07(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog08.ino"
// Bus function for sensor reading using analogRead() through pin A08



void InitBusAnalog08(byte *parameters)
{
 return;
}

void ConfigBusAnalog08(byte *parameters)
{
 return;
}

void EnableBusAnalog08()
{
 return;
}

void DisableBusAnalog08()
{
 return;
}

void ReadBusAnalog08(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A8);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog08(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog09.ino"
// SPV Raw MIC reading using bus function



void InitBusAnalog09(byte *parameters)
{
 return;
}

void ConfigBusAnalog09(byte *parameters)
{
 return;
}

void EnableBusAnalog09()
{
 return;
}

void DisableBusAnalog09()
{
 return;
}

void ReadBusAnalog09(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A9);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog09(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog10.ino"
// HIH4030 Humidity sensor reading using bus function



void InitBusAnalog10(byte *parameters)
{
 return;
}

void ConfigBusAnalog10(byte *parameters)
{
 return;
}

void EnableBusAnalog10()
{
 return;
}

void DisableBusAnalog10()
{
 return;
}

void ReadBusAnalog10(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A10);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog10(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusAnalog11.ino"
// Bus function for sensor reading using analogRead() through pin A11



void InitBusAnalog11(byte *parameters)
{
 return;
}

void ConfigBusAnalog11(byte *parameters)
{
 return;
}

void EnableBusAnalog11()
{
 return;
}

void DisableBusAnalog11()
{
 return;
}

void ReadBusAnalog11(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A11);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteBusAnalog11(byte *parameters)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital33.ino"
// Bus functions to read value through digital pin 33



void InitBusDigital33(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(33, 0x0);
 else if (mode == 1)
  pinMode(33, 0x1);
}

void ConfigBusDigital33(byte *parameters)
{
 return;
}

void EnableBusDigital33()
{
 return;
}

void DisableBusDigital33()
{
 return;
}

void ReadBusDigital33(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(33);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital33(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(33, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital34.ino"
// Bus functions to read value through digital pin 34



void InitBusDigital34(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(34, 0x0);
 else if (mode == 1)
  pinMode(34, 0x1);
}

void ConfigBusDigital34(byte *parameters)
{
 return;
}

void EnableBusDigital34()
{
 return;
}

void DisableBusDigital34()
{
 return;
}

void ReadBusDigital34(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(34);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital34(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(34, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital35.ino"
// Bus functions to read value through digital pin 35



void InitBusDigital35(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(35, 0x0);
 else if (mode == 1)
  pinMode(35, 0x1);
}

void ConfigBusDigital35(byte *parameters)
{
 return;
}

void EnableBusDigital35()
{
 return;
}

void DisableBusDigital35()
{
 return;
}

void ReadBusDigital35(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(35);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital35(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(35, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital36.ino"
// Bus functions to read value through digital pin 36



void InitBusDigital36(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(36, 0x0);
 else if (mode == 1)
  pinMode(36, 0x1);
}

void ConfigBusDigital36(byte *parameters)
{
 return;
}

void EnableBusDigital36()
{
 return;
}

void DisableBusDigital36()
{
 return;
}

void ReadBusDigital36(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(36);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital36(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(36, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital37.ino"
// Bus functions to read value through digital pin 37



void InitBusDigital37(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(37, 0x0);
 else if (mode == 1)
  pinMode(37, 0x1);
}

void ConfigBusDigital37(byte *parameters)
{
 return;
}

void EnableBusDigital37()
{
 return;
}

void DisableBusDigital37()
{
 return;
}

void ReadBusDigital37(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(37);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital37(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(37, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital38.ino"
// Bus functions to read value through digital pin 38



void InitBusDigital38(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(38, 0x0);
 else if (mode == 1)
  pinMode(38, 0x1);
}

void ConfigBusDigital38(byte *parameters)
{
 return;
}

void EnableBusDigital38()
{
 return;
}

void DisableBusDigital38()
{
 return;
}

void ReadBusDigital38(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(38);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital38(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(38, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital39.ino"
// Bus functions to read value through digital pin 39



void InitBusDigital39(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(39, 0x0);
 else if (mode == 1)
  pinMode(39, 0x1);
}

void ConfigBusDigital39(byte *parameters)
{
 return;
}

void EnableBusDigital39()
{
 return;
}

void DisableBusDigital39()
{
 return;
}

void ReadBusDigital39(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(39);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital39(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(39, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusDigital40.ino"
// Bus functions to read value through digital pin 40



void InitBusDigital40(byte *parameters)
{
 byte mode = parameters[0];
 if (mode == 0)
  pinMode(40, 0x0);
 else if (mode == 1)
  pinMode(40, 0x1);
}

void ConfigBusDigital40(byte *parameters)
{
 return;
}

void EnableBusDigital40()
{
 return;
}

void DisableBusDigital40()
{
 return;
}

void ReadBusDigital40(byte *sensorReading, int *readingLength)
{
 int value = digitalRead(40);

 sensorReading[0] = value & 0xFF;
 *readingLength = 1;
}

void WriteBusDigital40(byte *parameters)
{
 byte value = parameters[0]; // 0 or 1
 digitalWrite(40, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusI2C40.ino"
// HTU21D Temperature sensor through bus function

const byte i2c40address = 0x40;

void InitBusI2C40(byte *parameters)
{
 return;
}

void ConfigBusI2C40(byte *parameters)
{
 return;
}

void EnableBusI2C40()
{
 return;
}

void DisableBusI2C40()
{
 return;
}

void ReadBusI2C40(byte *parameters, byte *sensorReading, int *readingLength)
{
 // Read Temprature, Hang out while measurement is taken 50mS max
 byte readarray[3];
 byte writebyte[1] = {parameters[0]};
 WriteReadI2C(i2c40address, 1, writebyte, 3, readarray, 55);

 for (int i = 0; i < 2; i++)
  sensorReading[i] = readarray[i];
 *readingLength += 2;

 //Request a humidity reading
 writebyte[0] = parameters[1];
 WriteReadI2C(i2c40address, 1, writebyte, 3, readarray, 55);

 for (int i = 0; i < 2; i++)
  sensorReading[i + 2] = readarray[i];
 *readingLength += 2;
}

void WriteBusI2C40(byte *sensorReading)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusI2C48.ino"
// TMP112 Temperature sensor through bus function

const byte i2c48address = 0x48;

void InitBusI2C48(byte *parameters)
{
 byte writearray[3] = {parameters[0], parameters[1], parameters[2]};

 WriteI2C(i2c48address, 3, writearray);
 delay(100);

 byte writebyte[1] = {parameters[0]};
 WriteI2C(i2c48address, 1, writebyte);
 delay(100);

 byte readarray[2];
 ReadI2C(i2c48address, 2, readarray);
}

void ConfigBusI2C48(byte *parameters)
{
 return;
}

void EnableBusI2C48()
{
 return;
}

void DisableBusI2C48()
{
 return;
}

void ReadBusI2C48(byte *parameters, byte *sensorReading, int *readingLength)
{
 byte writebyte[1] = {parameters[0]};
 byte readarray[2];

 WriteI2C(i2c48address, 1, writebyte);
 delay(100);
 ReadI2C(i2c48address, 2, readarray);

 int length = 2;
 for (int i = 0; i < length; i++)
  sensorReading[i] = readarray[i];
 *readingLength = length;
}

void WriteBusI2C48(byte *sensorReading)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM01.ino"
// Bus functions to set PWM through pin 01



void InitBusPWM01(byte *parameters)
{
 pinMode(01, 0x1);
}

void ConfigBusPWM01(byte *parameters)
{
 return;
}

void EnableBusPWM01()
{
 return;
}

void DisableBusPWM01()
{
 return;
}

void ReadBusPWM01(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM01(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(01, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM02.ino"
// Bus functions to set PWM through pin 02



void InitBusPWM02(byte *parameters)
{
 pinMode(2, 0x1);
}

void ConfigBusPWM02(byte *parameters)
{
 return;
}

void EnableBusPWM02()
{
 return;
}

void DisableBusPWM02()
{
 return;
}

void ReadBusPWM02(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM02(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(2, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM03.ino"
// Bus functions to set PWM through pin 03



void InitBusPWM03(byte *parameters)
{
 pinMode(3, 0x1);
}

void ConfigBusPWM03(byte *parameters)
{
 return;
}

void EnableBusPWM03()
{
 return;
}

void DisableBusPWM03()
{
 return;
}

void ReadBusPWM03(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM03(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(3, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM04.ino"
// Bus functions to set PWM through pin 04



void InitBusPWM04(byte *parameters)
{
 pinMode(4, 0x1);
}

void ConfigBusPWM04(byte *parameters)
{
 return;
}

void EnableBusPWM04()
{
 return;
}

void DisableBusPWM04()
{
 return;
}

void ReadBusPWM04(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM04(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(4, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM05.ino"
// Bus functions to set PWM through pin 05



void InitBusPWM05(byte *parameters)
{
 pinMode(5, 0x1);
}

void ConfigBusPWM05(byte *parameters)
{
 return;
}

void EnableBusPWM05()
{
 return;
}

void DisableBusPWM05()
{
 return;
}

void ReadBusPWM05(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM05(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(5, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM06.ino"
// Bus functions to set PWM through pin 06



void InitBusPWM06(byte *parameters)
{
 pinMode(6, 0x1);
}

void ConfigBusPWM06(byte *parameters)
{
 return;
}

void EnableBusPWM06()
{
 return;
}

void DisableBusPWM06()
{
 return;
}

void ReadBusPWM06(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM06(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(6, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM07.ino"
// Bus functions to set PWM through pin 07



void InitBusPWM07(byte *parameters)
{
 pinMode(7, 0x1);
}

void ConfigBusPWM07(byte *parameters)
{
 return;
}

void EnableBusPWM07()
{
 return;
}

void DisableBusPWM07()
{
 return;
}

void ReadBusPWM07(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM07(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(7, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM08.ino"
// Bus functions to set PWM through pin 08



void InitBusPWM08(byte *parameters)
{
 pinMode(8, 0x1);
}

void ConfigBusPWM08(byte *parameters)
{
 return;
}

void EnableBusPWM08()
{
 return;
}

void DisableBusPWM08()
{
 return;
}

void ReadBusPWM08(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM08(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(8, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM09.ino"
// Bus functions to set PWM through pin 09



void InitBusPWM09(byte *parameters)
{
 pinMode(9, 0x1);
}

void ConfigBusPWM09(byte *parameters)
{
 return;
}

void EnableBusPWM09()
{
 return;
}

void DisableBusPWM09()
{
 return;
}

void ReadBusPWM09(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM09(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(9, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM10.ino"
// Bus functions to set PWM through pin 10



void InitBusPWM10(byte *parameters)
{
 pinMode(10, 0x1);
}

void ConfigBusPWM10(byte *parameters)
{
 return;
}

void EnableBusPWM10()
{
 return;
}

void DisableBusPWM10()
{
 return;
}

void ReadBusPWM10(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM10(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(10, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM11.ino"
// Bus functions to set PWM through pin 11



void InitBusPWM11(byte *parameters)
{
 pinMode(11, 0x1);
}

void ConfigBusPWM11(byte *parameters)
{
 return;
}

void EnableBusPWM11()
{
 return;
}

void DisableBusPWM11()
{
 return;
}

void ReadBusPWM11(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM11(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(11, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusPWM12.ino"
// Bus functions to set PWM through pin 12



void InitBusPWM12(byte *parameters)
{
 pinMode(12, 0x1);
}

void ConfigBusPWM12(byte *parameters)
{
 return;
}

void EnableBusPWM12()
{
 return;
}

void DisableBusPWM12()
{
 return;
}

void ReadBusPWM12(byte *sensorReading, int *readingLength)
{
 return;
}

void WriteBusPWM12(byte *parameters)
{
 int value = (parameters[0] * 255) / 100; // duty cycle * 255
 analogWrite(12, value);
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusParamStruct.ino"

struct paramBus
{
    const byte bustype;
    const byte busid;
    void (*initFunc)(byte*);
    void (*configFunc)(byte*);
    void (*enableFunc)();
    void (*disableFunc)();
    void (*readFunc)(byte*, byte*, int*);
    void (*writeFunc)(byte*);
};

const paramBus parambus[] = {
    {0x00, 0x40, InitBusI2C40, ConfigBusI2C40, EnableBusI2C40, DisableBusI2C40, ReadBusI2C40, WriteBusI2C40},
    {0x00, 0x48, InitBusI2C48, ConfigBusI2C48, EnableBusI2C48, DisableBusI2C48, ReadBusI2C48, WriteBusI2C48},
    {0x01, 0x33, InitBusSPI33, ConfigBusSPI33, EnableBusSPI33, DisableBusSPI33, ReadBusSPI33, WriteBusSPI33},
    {0x01, 0x34, InitBusSPI34, ConfigBusSPI34, EnableBusSPI34, DisableBusSPI34, ReadBusSPI34, WriteBusSPI34},
    {0x01, 0x35, InitBusSPI35, ConfigBusSPI35, EnableBusSPI35, DisableBusSPI35, ReadBusSPI35, WriteBusSPI35},
    {0x01, 0x36, InitBusSPI36, ConfigBusSPI36, EnableBusSPI36, DisableBusSPI36, ReadBusSPI36, WriteBusSPI36},
    {0x01, 0x37, InitBusSPI37, ConfigBusSPI37, EnableBusSPI37, DisableBusSPI37, ReadBusSPI37, WriteBusSPI37},
    {0x01, 0x38, InitBusSPI38, ConfigBusSPI38, EnableBusSPI38, DisableBusSPI38, ReadBusSPI38, WriteBusSPI38},
    {0x01, 0x39, InitBusSPI39, ConfigBusSPI39, EnableBusSPI39, DisableBusSPI39, ReadBusSPI39, WriteBusSPI39},
    {0x01, 0x40, InitBusSPI40, ConfigBusSPI40, EnableBusSPI40, DisableBusSPI40, ReadBusSPI40, WriteBusSPI40},
};

const int numParamBus = sizeof(parambus)/sizeof(parambus[0]);
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI33.ino"
// Bus function for SPI reading using GPIO 33 as slave select pin

SPISettings setSPI33;
byte spi33slavePin = 0x33;

void InitBusSPI33(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI33 = SetSPI(maxCommunicationSpeed, type, mode, spi33slavePin);
}

void ConfigBusSPI33(byte *parameters)
{
 return;
}

void EnableBusSPI33()
{
 return;
}

void DisableBusSPI33()
{
 return;
}

void ReadBusSPI33(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 // User can put const parameters if necessary
 int delayTime = parameters[2];
 int iterNum = parameters[3];

 ReadSPI(writearray, callLength, spi33slavePin, setSPI33, delayTime, iterNum);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI33(byte *parameters)
{
 // WriteSPI(readarray, callLength, spi33slavePin, setSPI33, delayTime, iterNum);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI34.ino"
// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI34;
byte spi34slavePin = 0x34;

void InitBusSPI34(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI34 = SetSPI(maxCommunicationSpeed, type, mode, spi34slavePin);
}

void ConfigBusSPI34(byte *parameters)
{
 return;
}

void EnableBusSPI34()
{
 return;
}

void DisableBusSPI34()
{
 return;
}

void ReadBusSPI34(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 // User can put const parameters if necessary
 int delayTime = parameters[2];
 int iterNum = parameters[3];

 ReadSPI(writearray, callLength, spi34slavePin, setSPI34, delayTime, iterNum);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI34(byte *parameters)
{
 // WriteSPI(readarray, callLength, SPI34SlavePin, setSPI34, delayTime, iterNum);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI35.ino"
// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI35;
byte spi35slavePin = 0x35;

void InitBusSPI35(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI35 = SetSPI(maxCommunicationSpeed, type, mode, spi35slavePin);
}

void ConfigBusSPI35(byte *parameters)
{
 return;
}

void EnableBusSPI35()
{
 return;
}

void DisableBusSPI35()
{
 return;
}

void ReadBusSPI35(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 // User can put const parameters if necessary
 int delayTime = parameters[2];
 int iterNum = parameters[3];

 ReadSPI(writearray, callLength, spi35slavePin, setSPI35, delayTime, iterNum);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI35(byte *parameters)
{
 // WriteSPI(readarray, callLength, SPI35SlavePin, setSPI35, delayTime, iterNum);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI36.ino"
// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI36;
byte spi36slavePin = 0x36;

void InitBusSPI36(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI36 = SetSPI(maxCommunicationSpeed, type, mode, spi36slavePin);
}

void ConfigBusSPI36(byte *parameters)
{
 return;
}

void EnableBusSPI36()
{
 return;
}

void DisableBusSPI36()
{
 return;
}

void ReadBusSPI36(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 // User can put const parameters if necessary
 int delayTime = parameters[2];
 int iterNum = parameters[3];

 ReadSPI(writearray, callLength, spi36slavePin, setSPI36, delayTime, iterNum);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI36(byte *parameters)
{
 // WriteSPI(readarray, callLength, SPI36SlavePin, setSPI36, delayTime, iterNum);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI37.ino"
// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI37;
byte spi37slavePin = 0x37;

void InitBusSPI37(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI37 = SetSPI(maxCommunicationSpeed, type, mode, spi37slavePin);
}

void ConfigBusSPI37(byte *parameters)
{
 return;
}

void EnableBusSPI37()
{
 return;
}

void DisableBusSPI37()
{
 return;
}

void ReadBusSPI37(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 // User can put const parameters if necessary
 int delayTime = parameters[2];
 int iterNum = parameters[3];

 ReadSPI(writearray, callLength, spi37slavePin, setSPI37, delayTime, iterNum);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI37(byte *parameters)
{
 // WriteSPI(readarray, callLength, SPI37SlavePin, setSPI37, delayTime, iterNum);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI38.ino"
// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI38;
byte spi38slavePin = 0x38;

void InitBusSPI38(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI38 = SetSPI(maxCommunicationSpeed, type, mode, spi38slavePin);
}

void ConfigBusSPI38(byte *parameters)
{
 return;
}

void EnableBusSPI38()
{
 return;
}

void DisableBusSPI38()
{
 return;
}

void ReadBusSPI38(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 // User can put const parameters if necessary
 int delayTime = parameters[2];
 int iterNum = parameters[3];

 ReadSPI(writearray, callLength, spi38slavePin, setSPI38, delayTime, iterNum);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI38(byte *parameters)
{
 // WriteSPI(readarray, callLength, SPI38SlavePin, setSPI38, delayTime, iterNum);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI39.ino"
// Bus function for SPI reading using GPIO 39 as slave select pin

SPISettings setSPI39;
byte spi39slavePin = 0x39;

void InitBusSPI39(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI39 = SetSPI(maxCommunicationSpeed, type, mode, spi39slavePin);
}

void ConfigBusSPI39(byte *parameters)
{
 return;
}

void EnableBusSPI39()
{
 return;
}

void DisableBusSPI39()
{
 return;
}

void ReadBusSPI39(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 // User can put const parameters if necessary
 int delayTime = parameters[2];
 int iterNum = parameters[3];

 ReadSPI(writearray, callLength, spi39slavePin, setSPI39, delayTime, iterNum);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI39(byte *parameters)
{
 // WriteSPI(readarray, callLength, SPI39SlavePin, setSPI39, delayTime, iterNum);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSPI40.ino"
// Alpha sensor reading through bus functions

SPISettings setSPI40;
byte spi40slavePin = 0x40;

void InitBusSPI40(byte *parameters)
{
 long maxCommunicationSpeed = (parameters[0] << 16) | (parameters[1] << 8) | parameters[2];
 byte type = parameters[3];
 byte mode = parameters[4];

 // set SPI params, begin device
 setSPI40 = SetSPI(maxCommunicationSpeed, type, mode, spi40slavePin);
}

void ConfigBusSPI40(byte *parameters)
{
 return;
}

void EnableBusSPI40()
{
 return;
}

void DisableBusSPI40()
{
 return;
}

void ReadBusSPI40(byte *parameters, byte *sensorReading, int *readingLength)
{
 int callLength = parameters[0];

 byte writearray[callLength];
 for (int i = 0; i < callLength; i++)
  writearray[i] = parameters[1];

 ReadSPI(writearray, callLength, spi40slavePin, setSPI40, 10, 1);

 for (int i = 0; i < callLength; i++)
  sensorReading[i] = writearray[i];
 *readingLength = callLength;
}

void WriteBusSPI40(byte *parameters)
{
 // WriteSPI(readarray, callLength, spi40slavePin, setSPI40, 10, 1);
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSerial02.ino"
// Bus function for Serial2 reading

void InitBusSerial02(byte *parameters)
{
 byte serial02powerPin = parameters[0];
 int baudrate = (parameters[1] << 16) | (parameters[2] << 8) | parameters[3];
 int timeout = parameters[4] * 1000; // parameter[4] in sec


 Serial2.begin(baudrate); // begin serial3
 Serial2.setTimeout(timeout); // set timeout of serial3 as 5 sec
 pinMode(serial02powerPin, 0x1); // pin for chemsense power is 47
 digitalWrite(serial02powerPin, 0x0); // power on the device --> LOW means power on
 delay(1000);

 if (Serial2.available() <= 0)
  Serial2.end();
}

void ConfigBusSerial02(byte *parameters)
{
 return;
}

void EnableBusSerial02()
{
 return;
}

void DisableBusSerial02()
{
 return;
}

void ReadBusSerial02(byte *sensorReading, int *readingLength)
{
 ReadRS232(sensorReading, readingLength, 2);
}

void WriteBusSerial02(byte *sensorReading)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusSerial03.ino"
// Chem sensor reading through bus functions

int ConfigLength;
byte ConfigReading[1516];

void InitBusSerial03(byte *parameters)
{
 byte powerPin = parameters[0];
 int baudrate = (parameters[1] << 16) | (parameters[2] << 8) | parameters[3];
 int timeout = parameters[4] * 1000;


 Serial3.begin(baudrate); // begin serial3
 Serial3.setTimeout(timeout); // set timeout of serial3 as 5 sec
 pinMode(powerPin, 0x1); // pin for chemsense power is 47
 digitalWrite(powerPin, 0x0); // power on the device --> LOW means power on
 delay(1000);

 if (Serial3.available() > 0)
  ConfigLength = Serial3.readBytesUntil(36, ConfigReading, 1516);
 else
  Serial3.end();
}

void ConfigBusSerial03(byte *parameters)
{
 return;
}

void EnableBusSerial03()
{
 return;
}

void DisableBusSerial03()
{
 return;
}

void ReadBusSerial03(byte *sensorReading, int *readingLength)
{
 ReadRS232(sensorReading, readingLength, 3);
}

void WriteBusSerial03(byte *sensorReading)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/BusStruct.ino"

struct Bus
{
    const byte bustype;
    const byte busid;
    void (*initFunc)(byte*);
    void (*configFunc)(byte*);
    void (*enableFunc)();
    void (*disableFunc)();
    void (*readFunc)(byte*, int*);
    void (*writeFunc)(byte*);
};

const Bus bus[] = {
    {0x03, 0x00, InitBusAnalog00, ConfigBusAnalog00, EnableBusAnalog00, DisableBusAnalog00, ReadBusAnalog00, WriteBusAnalog00},
    {0x03, 0x01, InitBusAnalog01, ConfigBusAnalog01, EnableBusAnalog01, DisableBusAnalog01, ReadBusAnalog01, WriteBusAnalog01},
    {0x03, 0x02, InitBusAnalog02, ConfigBusAnalog02, EnableBusAnalog02, DisableBusAnalog02, ReadBusAnalog02, WriteBusAnalog02},
    {0x03, 0x03, InitBusAnalog03, ConfigBusAnalog03, EnableBusAnalog03, DisableBusAnalog03, ReadBusAnalog03, WriteBusAnalog03},
    {0x03, 0x04, InitBusAnalog04, ConfigBusAnalog04, EnableBusAnalog04, DisableBusAnalog04, ReadBusAnalog04, WriteBusAnalog04},
    {0x03, 0x05, InitBusAnalog05, ConfigBusAnalog05, EnableBusAnalog05, DisableBusAnalog05, ReadBusAnalog05, WriteBusAnalog05},
    {0x03, 0x06, InitBusAnalog06, ConfigBusAnalog06, EnableBusAnalog06, DisableBusAnalog06, ReadBusAnalog06, WriteBusAnalog06},
    {0x03, 0x07, InitBusAnalog07, ConfigBusAnalog07, EnableBusAnalog07, DisableBusAnalog07, ReadBusAnalog07, WriteBusAnalog07},
    {0x03, 0x08, InitBusAnalog08, ConfigBusAnalog08, EnableBusAnalog08, DisableBusAnalog08, ReadBusAnalog08, WriteBusAnalog08},
    {0x03, 0x09, InitBusAnalog09, ConfigBusAnalog09, EnableBusAnalog09, DisableBusAnalog09, ReadBusAnalog09, WriteBusAnalog09},
    {0x03, 0x10, InitBusAnalog10, ConfigBusAnalog10, EnableBusAnalog10, DisableBusAnalog10, ReadBusAnalog10, WriteBusAnalog10},
    {0x03, 0x11, InitBusAnalog11, ConfigBusAnalog11, EnableBusAnalog11, DisableBusAnalog11, ReadBusAnalog11, WriteBusAnalog11},
    {0x04, 0x33, InitBusDigital33, ConfigBusDigital33, EnableBusDigital33, DisableBusDigital33, ReadBusDigital33, WriteBusDigital33},
    {0x04, 0x34, InitBusDigital34, ConfigBusDigital34, EnableBusDigital34, DisableBusDigital34, ReadBusDigital34, WriteBusDigital34},
    {0x04, 0x35, InitBusDigital35, ConfigBusDigital35, EnableBusDigital35, DisableBusDigital35, ReadBusDigital35, WriteBusDigital35},
    {0x04, 0x36, InitBusDigital36, ConfigBusDigital36, EnableBusDigital36, DisableBusDigital36, ReadBusDigital36, WriteBusDigital36},
    {0x04, 0x37, InitBusDigital37, ConfigBusDigital37, EnableBusDigital37, DisableBusDigital37, ReadBusDigital37, WriteBusDigital37},
    {0x04, 0x38, InitBusDigital38, ConfigBusDigital38, EnableBusDigital38, DisableBusDigital38, ReadBusDigital38, WriteBusDigital38},
    {0x04, 0x39, InitBusDigital39, ConfigBusDigital39, EnableBusDigital39, DisableBusDigital39, ReadBusDigital39, WriteBusDigital39},
    {0x04, 0x40, InitBusDigital40, ConfigBusDigital40, EnableBusDigital40, DisableBusDigital40, ReadBusDigital40, WriteBusDigital40},
    {0x05, 0x01, InitBusPWM01, ConfigBusPWM01, EnableBusPWM01, DisableBusPWM01, ReadBusPWM01, WriteBusPWM01},
    {0x05, 0x02, InitBusPWM02, ConfigBusPWM02, EnableBusPWM02, DisableBusPWM02, ReadBusPWM02, WriteBusPWM02},
    {0x05, 0x03, InitBusPWM03, ConfigBusPWM03, EnableBusPWM03, DisableBusPWM03, ReadBusPWM03, WriteBusPWM03},
    {0x05, 0x04, InitBusPWM04, ConfigBusPWM04, EnableBusPWM04, DisableBusPWM04, ReadBusPWM04, WriteBusPWM04},
    {0x05, 0x05, InitBusPWM05, ConfigBusPWM05, EnableBusPWM05, DisableBusPWM05, ReadBusPWM05, WriteBusPWM05},
    {0x05, 0x06, InitBusPWM06, ConfigBusPWM06, EnableBusPWM06, DisableBusPWM06, ReadBusPWM06, WriteBusPWM06},
    {0x05, 0x07, InitBusPWM07, ConfigBusPWM07, EnableBusPWM07, DisableBusPWM07, ReadBusPWM07, WriteBusPWM07},
    {0x05, 0x08, InitBusPWM08, ConfigBusPWM08, EnableBusPWM08, DisableBusPWM08, ReadBusPWM08, WriteBusPWM08},
    {0x05, 0x09, InitBusPWM09, ConfigBusPWM09, EnableBusPWM09, DisableBusPWM09, ReadBusPWM09, WriteBusPWM09},
    {0x05, 0x10, InitBusPWM10, ConfigBusPWM10, EnableBusPWM10, DisableBusPWM10, ReadBusPWM10, WriteBusPWM10},
    {0x05, 0x11, InitBusPWM11, ConfigBusPWM11, EnableBusPWM11, DisableBusPWM11, ReadBusPWM11, WriteBusPWM11},
    {0x05, 0x12, InitBusPWM12, ConfigBusPWM12, EnableBusPWM12, DisableBusPWM12, ReadBusPWM12, WriteBusPWM12},
    {0x02, 0x02, InitBusSerial02, ConfigBusSerial02, EnableBusSerial02, DisableBusSerial02, ReadBusSerial02, WriteBusSerial02},
    {0x02, 0x03, InitBusSerial03, ConfigBusSerial03, EnableBusSerial03, DisableBusSerial03, ReadBusSerial03, WriteBusSerial03},
};

const int numBus = sizeof(bus)/sizeof(bus[0]);
# 1 "/home/sager/repos/sensors/v4.1/src/EnabledStruct.ino"

struct EnabledTable
{
    const byte enabledsensorid;
    bool enabled;
};

EnabledTable enabledtable[] = {
    {0x00, 0x0},
    {0x01, 0x0},
    {0x02, 0x0},
    {0x03, 0x0},
    {0x04, 0x0},
    {0x05, 0x0},
    {0x06, 0x0},
    {0x07, 0x0},
    {0x08, 0x0},
    {0x09, 0x0},
    {0x0A, 0x0},
    {0x0B, 0x0},
    {0x0C, 0x0},
    {0x0D, 0x0},
    {0x0E, 0x0},
    {0x0F, 0x0},
    {0x10, 0x0},
    {0x13, 0x0},
    {0x16, 0x0},
    {0x28, 0x0},
    {0x29, 0x0},
    {0x2A, 0x0},
    {0x2B, 0x0},
    {0x2C, 0x0},
    {0x30, 0x0},
    {0x31, 0x0},
    {0xFF, 0x0},
};

const int numEnabled = sizeof(enabledtable)/sizeof(enabledtable[0]);
# 1 "/home/sager/repos/sensors/v4.1/src/FunctionType.ino"

struct FunctionType
{
 const byte funcid;
 void (*func)(byte*, byte);
};


const FunctionType functype[] = {
 {0x01, SensorInit},
 {0x02, SensorConfig},
 {0x03, SensorEnable},
 {0x04, SensorDisable},
 {0x05, SensorRead},
 {0x06, SensorWrite},

 {0x11, BusInit},
 {0x12, BusConfig},
 {0x13, BusEnable},
 {0x14, BusDisable},
 {0x15, BusRead},
 {0x16, BusWrite},
};

const int numType = sizeof(functype)/sizeof(functype[0]);
# 1 "/home/sager/repos/sensors/v4.1/src/Mandatory.ino"

struct MandatorySensor
{
 const byte funcid;
 void (*enableFunc)();
};


const MandatorySensor mandsensor[] = {
 {0x00, EnableSensor00},
 {0x01, EnableSensor01},
 {0x02, EnableSensor02},
 {0x03, EnableSensor03},
 {0x04, EnableSensor04},
 {0x05, EnableSensor05},
 {0x06, EnableSensor06},
 {0x07, EnableSensor07},
 {0x08, EnableSensor08},
 {0x09, EnableSensor09},
 {0x0A, EnableSensor0A},
 {0x0B, EnableSensor0B},
 {0x0C, EnableSensor0C},
 {0x0D, EnableSensor0D},
 {0x0E, EnableSensor0E},
 {0x0F, EnableSensor0F},
 {0x10, EnableSensor10},
 {0x13, EnableSensor13},
 {0x2A, EnableSensor2A}, // Chem
 {0x30, EnableSensor28}, // Alpha
 {0xFF, EnableSensorFF}, // FW ver
};

const int numMand = sizeof(mandsensor)/sizeof(mandsensor[0]);
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor00.ino"
// Met and Light macaddress

void InitSensor00()
{
 return;
}

void ConfigSensor00()
{
 return;
}

void EnableSensor00()
{
 EnableSensor(0x00);
}

void DisableSensor00()
{
 DisableSensor(0x00);
}

void ReadSensor00(byte *sensorReading, int *readingLength)
{
 byte id[8];

 if (!ds2401.reset())
 {
  sensorReading[0] = 0xFF;
  *readingLength += 1;
  // SerialUSB.print("device is not ready");
  // return any sign that this device is not ready!!
 }

 ds2401.write(0x33);

 for (int i = 0; i < 8; i++)
 {
  id[i] = ds2401.read();
  sensorReading[i] = id[i];
  *readingLength += 1;
 }

 if (OneWire::crc8(id, 8) != 0)
 {
  sensorReading[0] = 0xFF;
  *readingLength += 1;
  // SerialUSB.print("failed to pass crc check");
  // return any sign that it is failed to checi crc
 }
}

void WriteSensor00(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor01.ino"
// TMP112 Temperature sensor



void InitSensor01()
{
 const byte TMP112_CONFIG_REG = 0x01;
 // const byte TMP112_TEMP_REG = 0x00;

 byte writearray[3] = {TMP112_CONFIG_REG, 0x60, 0xB0};
 WriteI2C(0x48, 3, writearray);
 delay(100);

 byte writebyte[1] = {TMP112_CONFIG_REG};
 WriteI2C(0x48, 1, writebyte);
 delay(100);

 byte readarray[2];
 ReadI2C(0x48, 2, readarray);
}

void ConfigSensor01()
{
 return;
}

void EnableSensor01()
{
 EnableSensor(0x01);
}

void DisableSensor01()
{
 DisableSensor(0x01);
}

void ReadSensor01(byte *sensorReading, int *readingLength)
{
 const byte TMP112_TEMP_REG = 0x00;

 byte writebyte[1] = {TMP112_TEMP_REG};
 byte readarray[2];
 WriteI2C(0x48, 1, writebyte);
 delay(100);
 ReadI2C(0x48, 2, readarray);

 sensorReading[0] = readarray[0];
 sensorReading[1] = readarray[1];
 *readingLength = 2;
}

void WriteSensor01(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor02.ino"
// HTU21D Temperature and relative humidity sensor



void InitSensor02()
{
 return;
}

void ConfigSensor02()
{
 return;
}

void EnableSensor02()
{
 EnableSensor(0x02);
}

void DisableSensor02()
{
 DisableSensor(0x02);
}

void ReadSensor02(byte *sensorReading, int *readingLength)
{
 const byte TRIGGER_TEMP_MEASURE_NOHOLD = 0xF3;
 const byte TRIGGER_HUMD_MEASURE_NOHOLD = 0xF5;

 // Read Temprature, Hang out while measurement is taken 50mS max
 byte readarray[3];
 byte writebyte[1] = {TRIGGER_TEMP_MEASURE_NOHOLD};
 WriteReadI2C(0x40, 1, writebyte, 3, readarray, 55);

 int raw = (readarray[0] << 8) | readarray[1];
 if (check_crc(raw, int(readarray[2])) != 0)
 {
  readarray[0] = 0xFF;
  readarray[1] = 0xFF;
 }

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 //Request a humidity reading
 writebyte[0] = TRIGGER_HUMD_MEASURE_NOHOLD;
 WriteReadI2C(0x40, 1, writebyte, 3, readarray, 55);

 raw = (readarray[0] << 8) | readarray[1];
 if (check_crc(raw, int(readarray[2])) != 0)
 {
  readarray[0] = 0xFF;
  readarray[1] = 0xFF;
 }

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i + 2] = readarray[i];
  *readingLength += 1;
 }
}

void WriteSensor02(byte *packet)
{
 return;
}


const int SHIFTED_DIVISOR = 0x988000;
byte check_crc(int message_from_sensor, int check_value_from_sensor)
{
 uint32_t remainder = (uint32_t)message_from_sensor << 8; //Pad with 8 bits because we have to add in the check value
 remainder |= check_value_from_sensor; //Add on the check value

 uint32_t divsor = (uint32_t)0x988000;

 for (int i = 0 ; i < 16 ; i++) //Operate on only 16 positions of max 24. The remaining 8 are our remainder and should be zero when we're done.
 {
 if( remainder & (uint32_t)1<<(23 - i) ) //Check if there is a one in the left position
  remainder ^= divsor;

 divsor >>= 1; //Rotate the divsor max 16 times so that we have 8 bits left of a remainder
 }

 return (byte)remainder;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor03.ino"
// HIH4030 Relative Humidity sensor



void InitSensor03()
{
 return;
}

void ConfigSensor03()
{
 return;
}

void EnableSensor03()
{

 EnableSensor(0x03);
}

void DisableSensor03()
{

 DisableSensor(0x03);
}

void ReadSensor03(byte *sensorReading, int *readingLength)
{
 int value = analogRead(A10);

 sensorReading[0] = (value >> 8) & 0xFF;
 sensorReading[1] = value & 0xFF;

 *readingLength = 2;
}

void WriteSensor03(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor04.ino"
// BMP180 Temperature and Barometric Pressure sensor


byte BMP180_COEFFICIENTS[22];

void InitSensor04()
{
 byte BMP180_REGISTER_CHIPID = 0xD0;
 byte writebyte[1] = {BMP180_REGISTER_CHIPID};
 //** ultra high resolution
 // int _bmp180Mode = 3;

 // // make sure we have the right device
 // byte id[1];
 // WriteReadI2C(BMP180_ADDRESS, 1, writebyte, 1, id);
 // if (id[1] != 0x55)
 // 	byte BMP180_validity = 0;

 //** read coefficients
 byte BMP180register[11] = {0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB6, 0xB8, 0xBA, 0xBC, 0xBE};

 byte temp_coeff[2];
 for (int i = 0; i < 11; i++)
 {
  writebyte[0] = BMP180register[i];
  WriteReadI2C(0x77, 1, writebyte, 2, temp_coeff);
  BMP180_COEFFICIENTS[i * 2] = temp_coeff[0];
  BMP180_COEFFICIENTS[i * 2 + 1] = temp_coeff[1];
  // uint16_t uco = (temp_coeff[0] << 8) | temp_coeff[1];
 }
}

void ConfigSensor04()
{
 return;
}

void EnableSensor04()
{
 EnableSensor(0x04);
}

void DisableSensor04()
{
 DisableSensor(0x04);
}

void ReadSensor04(byte *sensorReading, int *readingLength)
{
 const byte BMP180_REGISTER_CONTROL = 0xF4;
 const byte BMP180_REGISTER_TEMPDATA = 0xF6;
 const byte BMP180_REGISTER_PRESSUREDATA = 0xF6;
 const byte BMP180_REGISTER_READTEMPCMD = 0x2E;
 const byte BMP180_REGISTER_READPRESSURECMD = 0x34;

 // Read temprature
 byte writearray[2] = {BMP180_REGISTER_CONTROL, BMP180_REGISTER_READTEMPCMD};
 WriteI2C(0x77, 2, writearray);
 delay(5);
 byte writebyte[1] = {BMP180_REGISTER_TEMPDATA};
 byte readarray[2];
 WriteReadI2C(0x77, 1, writebyte, 2, readarray);

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 // Read pressure
 byte _bmp180Mode = 3;
 writearray[0] = BMP180_REGISTER_CONTROL;
 writearray[1] = BMP180_REGISTER_READPRESSURECMD + (_bmp180Mode << 6);
 WriteI2C(0x77, 2, writearray);
 delay(26);
 writebyte[0] = BMP180_REGISTER_PRESSUREDATA;
 WriteReadI2C(0x77, 1, writebyte, 2, readarray);
 writebyte[0] = BMP180_REGISTER_PRESSUREDATA + 2;
 byte readbyte[1];
 WriteReadI2C(0x77, 1, writebyte, 1, readbyte);

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i + 2] = readarray[i];
  *readingLength += 1;
 }
 sensorReading[*readingLength] = readbyte[0];
 *readingLength += 1;

 // int startCoeff = *readingLength;
 // int a = sizeof(BMP180_COEFFICIENTS);
 // for (int i = 0; i < a; i++)
 // {
 // 	sensorReading[startCoeff + i] = BMP180_COEFFICIENTS[i];
 // 	*readingLength += 1;
 // }
}

void WriteSensor04(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor05.ino"
// PR103J2 Temperature sensor



void InitSensor05()
{
 return;
}

void ConfigSensor05()
{
 return;
}

void EnableSensor05()
{
 EnableSensor(0x05);
}

void DisableSensor05()
{
 DisableSensor(0x05);
}

void ReadSensor05(byte *sensorReading, int *readingLength)
{
 int PR = analogRead(0);

 sensorReading[0] = (PR >> 8) & 0xFF;
 sensorReading[1] = PR & 0xFF;

 *readingLength = 2;
}

void WriteSensor05(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor06.ino"
// TSL250 Light sensor



void InitSensor06()
{
 return;
}

void ConfigSensor06()
{
 return;
}

void EnableSensor06()
{
 EnableSensor(0x06);
}

void DisableSensor06()
{
 DisableSensor(0x06);
}

void ReadSensor06(byte *sensorReading, int *readingLength)
{
 int TSL250_1 = analogRead(1);

 sensorReading[0] = (TSL250_1 >> 8) & 0xFF;
 sensorReading[1] = TSL250_1 & 0xFF;

 *readingLength = 2;
}

void WriteSensor06(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor07.ino"
// MMA accelerometer



void InitSensor07()
{
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
 // 	byte MMA8452_validity = 0;

 //*** sensor stand by
 byte readbyte[1];
 byte writebyte[1] = {CTRL_REG1};
 WriteReadI2C(0x1C, 1, writebyte, 1, readbyte, 0x0);
 // Clear the active bit to go into standby
 int a = int(readbyte[0]) & ~(0x01);
 byte writearray[2] = {CTRL_REG1, byte(a)};
 WriteI2C(0x1C, 2, writearray);

 //** Set up the full scale range to 2, 4, or 8g.
 byte fsr = GSCALE;
 if(fsr > 8)
  fsr = 8; //Easy error check
 // Neat trick, see page 22. 00 = 2G, 01 = 4A, 10 = 8G
 fsr >>= 2;

 //** set up accelerometer scale as 2G, default data rate 800Hz
 writearray[0] = XYZ_DATA_CFG;
 writearray[1] = fsr;
 WriteI2C(0x1C, 2, writearray);

 //*** active sensor--> Set the active bit to begin detection
 writebyte[0] = CTRL_REG1;
 WriteReadI2C(0x1C, 1, writebyte, 1, readbyte, 0x0);
 writearray[0] = CTRL_REG1;
 writearray[1] = readbyte[0] | 0x01;
 WriteI2C(0x1C, 2, writearray);
}

void ConfigSensor07()
{
 return;
}

void EnableSensor07()
{
 EnableSensor(0x07);
}

void DisableSensor07()
{
 DisableSensor(0x07);
}

void ReadSensor07(byte *sensorReading, int *readingLength)
{
 const byte OUT_X_MSB = 0x01;
 // const byte XYZ_DATA_CFG = 0x0E;
 // const byte CTRL_REG1 = 0x2A;

 Wire.requestFrom((uint8_t) 0x1C, (uint8_t) 6, (uint32_t) OUT_X_MSB, (uint8_t) 1, TRUE);
 for (int i = 0; i < 6; i++)
 {
  sensorReading[i] = Wire.read();
  *readingLength += 1;
 }
}

void WriteSensor07(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor08.ino"
// SPV sound level sensor

// below three lines are for sound level sensor




void InitSensor08()
{
 pinMode(A5,0x0); // Does this pin really work?
 pinMode(A6,0x0); // Does this pin really work?
 pinMode(A9,0x0);
}

void ConfigSensor08()
{
 return;
}

void EnableSensor08()
{
 EnableSensor(0x08);
}

void DisableSensor08()
{
 DisableSensor(0x08);
}

void ReadSensor08(byte *sensorReading, int *readingLength)
{
 int buff = 0;
 for (int i = 0; i < 63; i++)
 {
  buff = analogRead(A9);
  sensorReading[i * 2] = (buff >> 8) & 0xFF;
  sensorReading[i * 2 + 1] = buff & 0xFF;
  *readingLength += 2;
 }
}

void WriteSensor08(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor09.ino"
// TSYS01 Temperature sensor


byte TSYS01_COEFFICIENTS[10];

void InitSensor09()
{
 byte writebyte[1] = {0x1E};
 WriteI2C(0x76, 1, writebyte);
 delay(50);

 //gathers calibration coefficients to array
 byte readarray[2];
 for (int i = 0; i < 5; i++)
 {
  writebyte[0] = 0xA2 + (i * 2);
  WriteReadI2C(0x76, 1, writebyte, 2, readarray);
  TSYS01_COEFFICIENTS[i * 2] = readarray[0];
  TSYS01_COEFFICIENTS[i * 2 + 1] = readarray[1];
  // int co = ((uint16_t)readarray[0] << 8) + readarray[1];

  // SerialUSB.print("TSYS ");
  // SerialUSB.println(co);
 }
}

void ConfigSensor09()
{
 return;
}

void EnableSensor09()
{
 EnableSensor(0x09);
}

void DisableSensor09()
{
 DisableSensor(0x09);
}

void ReadSensor09(byte *sensorReading, int *readingLength)
{
 const byte TSYS01StartReg = 0x48; //commands sensor to begin measurement / output calculation
 const byte TSYS01TempReg = 0x00; //requests most recent output from measurement

 byte writebyte[1] = {TSYS01StartReg};
 WriteI2C(0x76, 1, writebyte);
 delay(10);
 writebyte[0] = {TSYS01TempReg};
 byte readarray[3];
 WriteReadI2C(0x76, 1, writebyte, 3, readarray);
 // the last read is not used

 for (int i = 0; i < 3; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 // int startCoeff = *readingLength;
 // int a = sizeof(TSYS01_COEFFICIENTS);
 // for (int i = 0; i < a; i++)
 // {
 // 	sensorReading[startCoeff + i] = TSYS01_COEFFICIENTS[i];
 // 	*readingLength += 1;
 // }
}

void WriteSensor09(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor0A.ino"
// HMC Magnetometer



void InitSensor0A()
{
 const byte HMC5883_REGISTER_MAG_CRB_REG_M = 0x01;
 const byte HMC5883_REGISTER_MAG_MR_REG_M = 0x02;
 const byte HMC5883_MAGGAIN_1_3 = 0x20;

 // Enable the magnetometer
 byte writearray[2] = {HMC5883_REGISTER_MAG_MR_REG_M, 0x00};
 WriteI2C(0x1E /*byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x*/, 2, writearray);

 //** Set the gain to a known level
 writearray[0] = HMC5883_REGISTER_MAG_CRB_REG_M;
 writearray[1] = HMC5883_MAGGAIN_1_3;
 WriteI2C(0x1E /*byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x*/, 2, writearray);
 // _magGain = gain;

 // //** TODO: Where to store, how to send, sensor ID?????
 // int coefficient_Gauss_LSB_XY = 1100;
 // int coefficient_Gauss_LSB_Z  = 980;

 // HMC5883_COEFFICIENTS[0] = (coefficient_Gauss_LSB_XY >> 8) & 0xFF;
 // HMC5883_COEFFICIENTS[1] = coefficient_Gauss_LSB_XY & 0xFF;
 // HMC5883_COEFFICIENTS[2] = (coefficient_Gauss_LSB_Z >> 8) & 0xFF;
 // HMC5883_COEFFICIENTS[3] = coefficient_Gauss_LSB_Z & 0xFF;
}

void ConfigSensor0A()
{
 return;
}

void EnableSensor0A()
{
 EnableSensor(0x0A);
}

void DisableSensor0A()
{
 DisableSensor(0x0A);
}

void ReadSensor0A(byte *sensorReading, int *readingLength)
{
 const byte HMC5883_REGISTER_MAG_OUT_X_H_M = 0x03;

 byte writebyte[1] = {HMC5883_REGISTER_MAG_OUT_X_H_M};
 byte readarray[6];
 WriteReadI2C(0x1E /*byte HMC5883_ADDRESS_MAG = 0x3C >> 1;  // 0011110x*/, 1, writebyte, 6, readarray);

 for (int i = 0; i < 6; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 // int a = (sensorReading[0] << 8) | sensorReading[1];
 // int b = (sensorReading[2] << 8) | sensorReading[3];
 // int c = (sensorReading[4] << 8) | sensorReading[5];


 // SerialUSB.print("HMCx ");
 // SerialUSB.println(a);
 // SerialUSB.print("HMCy ");
 // SerialUSB.println(b);
 // SerialUSB.print("HMCz ");
 // SerialUSB.println(c);

 // int startCoeff = *readingLength;
 // int a = sizeof(HMC5883_COEFFICIENTS);
 // for (int i = 0; i < a; i++)
 // {
 // 	sensorReading[startCoeff + i] = HMC5883_COEFFICIENTS[i];
 // 	*readingLength += 1;
 // }
}

void WriteSensor0A(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor0B.ino"

// HIH6130 Temperature and relative humidity sensor



void InitSensor0B()
{
 return;
}

void ConfigSensor0B()
{
 return;
}

void EnableSensor0B()
{
 EnableSensor(0x0B);
}

void DisableSensor0B()
{
 DisableSensor(0x0B);
}

void ReadSensor0B(byte *sensorReading, int *readingLength)
{
 byte readarray[4];
 DirectReadI2C(0x27, 4, readarray, 10);

 for (int i = 0; i < 4; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }
}

void WriteSensor0B(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor0C.ino"
// APDS Light sensor

void InitSensor0C()
{
 mcp3428_2.init(MCP342X::L, MCP342X::F);
 MCP3428_2_ADDRESS = mcp3428_2.returnAddress();
}

void ConfigSensor0C()
{
 return;
}

void EnableSensor0C()
{
 EnableSensor(0x0C);
}

void DisableSensor0C()
{
 DisableSensor(0x0C);
}

void ReadSensor0C(byte *sensorReading, int *readingLength)
{
 // byte address = mcp3428_2.returnAddress();
 byte writebyte[1] = {mcp3428_2.returnRegister(MCP342X::CHANNEL_0)};
 byte readarray[3];
 WriteReadI2C(MCP3428_2_ADDRESS, 1, writebyte, 3, readarray, 100);

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 // the last read is not used

 // selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
 // int APDS = mcp3428_2.readADC();
}

void WriteSensor0C(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor0D.ino"
// TSL260RD Light sensor

void InitSensor0D()
{
 if (flagMCP1 == 0x0)
 {
  mcp3428_1.init(MCP342X::L, MCP342X::L);
  MCP3428_1_ADDRESS = mcp3428_1.returnAddress();
  flagMCP1 = 0x1;
 }
}

void ConfigSensor0D()
{
 return;
}

void EnableSensor0D()
{
 EnableSensor(0x0D);
}

void DisableSensor0D()
{
 DisableSensor(0x0D);
}

void ReadSensor0D(byte *sensorReading, int *readingLength)
{
 // byte address = mcp3428_1.returnAddress();
 byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_1)};
 byte readarray[3];
 WriteReadI2C(MCP3428_1_ADDRESS, 1, writebyte, 3, readarray, 10);

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 // the last read is not used

 // mcp3428_1.selectChannel(MCP342X::CHANNEL_1, MCP342X::GAIN_1);
 // int TSL260 = mcp3428_1.readADC();
}

void WriteSensor0D(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor0E.ino"
// TSL250RD Light sensor

void InitSensor0E()
{
 if (flagMCP1 == 0x0)
 {
  mcp3428_1.init(MCP342X::L, MCP342X::L);
  MCP3428_1_ADDRESS = mcp3428_1.returnAddress();
  flagMCP1 = 0x1;
 }
}

void ConfigSensor0E()
{
 return;
}

void EnableSensor0E()
{
 EnableSensor(0x0E);
}

void DisableSensor0E()
{
 DisableSensor(0x0E);
}

void ReadSensor0E(byte *sensorReading, int *readingLength)
{
 // byte address = mcp3428_1.returnAddress();
 byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_3)};
 byte readarray[3];
 WriteReadI2C(MCP3428_1_ADDRESS, 1, writebyte, 3, readarray, 10.);

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 // the last read is not used

 // mcp3428_1.selectChannel(MCP342X::CHANNEL_3, MCP342X::GAIN_1);
 // int TSL250_2 = mcp3428_1.readADC();
}

void WriteSensor0E(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor0F.ino"
// MLX Light sensor

void InitSensor0F()
{
 if (flagMCP1 == 0x0)
 {
  mcp3428_1.init(MCP342X::L, MCP342X::L);
  MCP3428_1_ADDRESS = mcp3428_1.returnAddress();
  flagMCP1 = 0x1;
 }
}

void ConfigSensor0F()
{
 return;
}

void EnableSensor0F()
{
 EnableSensor(0x0F);
}

void DisableSensor0F()
{
 DisableSensor(0x0F);
}

void ReadSensor0F(byte *sensorReading, int *readingLength)
{
 // byte address = mcp3428_1.returnAddress();
 byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_0)};
 byte readarray[3];
 WriteReadI2C(MCP3428_1_ADDRESS, 1, writebyte, 3, readarray, 100);

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i] = readarray[i];
  *readingLength += 1;
 }

 // the last read is not used

 // mcp3428_1.selectChannel(MCP342X::CHANNEL_0, MCP342X::GAIN_1);
 // int MLX = mcp3428_1.readADC();
}

void WriteSensor0F(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor10.ino"
// ML8511 Light sensor -- UV

void InitSensor10()
{
 if (flagMCP1 == 0x0)
 {
  mcp3428_1.init(MCP342X::L, MCP342X::L);
  MCP3428_1_ADDRESS = mcp3428_1.returnAddress();
  flagMCP1 = 0x1;
 }
}

void ConfigSensor10()
{
 return;
}

void EnableSensor10()
{
 EnableSensor(0x10);
}

void DisableSensor10()
{
 DisableSensor(0x10);
}

void ReadSensor10(byte *sensorReading, int *readingLength)
{
 // byte address = mcp3428_1.returnAddress();
 byte writebyte[1] = {mcp3428_1.returnRegister(MCP342X::CHANNEL_2)};
 byte readarray[3];
 WriteReadI2C(MCP3428_1_ADDRESS, 1, writebyte, 3, readarray, 100);

 for (int i = 0; i < 2; i++)
    {
  sensorReading[i] = readarray[i];
     *readingLength += 1;
    }

 // the last read is not used

 // mcp3428_1.selectChannel(MCP342X::CHANNEL_2, MCP342X::GAIN_1);
 // int ML8511 = mcp3428_1.readADC();
}

void WriteSensor10(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor13.ino"
// TMP421 Temperature sensor



void InitSensor13()
{
 return;
}

void ConfigSensor13()
{
 return;
}

void EnableSensor13()
{
 EnableSensor(0x13);
}

void DisableSensor13()
{
 DisableSensor(0x13);
}

void ReadSensor13(byte *sensorReading, int *readingLength)
{
 byte readbyte[1];

 // high-byte
 byte writebyte[1] = {0x00};
 WriteReadI2C(0x4C, 1, writebyte, 1, readbyte);

 sensorReading[0] = readbyte[0];
 *readingLength += 1;

 // low-byte
 writebyte[0] = 0x10;
 WriteReadI2C(0x4C, 1, writebyte, 1, readbyte);

 sensorReading[1] = readbyte[0];
 *readingLength += 1;

 // byte testdata[2];
 // WriteI2C(TMP421_ADDRESS, char(0x13));
 // ReadI2C(TMP421_ADDRESS, testdata[0]); // high-byte

 // WriteI2C(TMP421_ADDRESS, char(0x10));
 // ReadI2C(TMP421_ADDRESS, testdata[1]); // low-byte
}

void WriteSensor13(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor16.ino"
// Chemconfig

void InitSensor16()
{
 return;
}

void ConfigSensor16()
{
 return;
}

void EnableSensor16()
{
 EnableSensor(0x16);
}

void DisableSensor16()
{
 DisableSensor(0x16);
}

void ReadSensor16(byte *sensorReading, int *readingLength)
{
 SerialUSB.print("Start sending Chemsense FW configuration");
 for (int i = 0; i < chemConfigLength; i++)
  SerialUSB.write(chemConfigReading[i]);
 SerialUSB.print("End sending Chemsense FW configuration");
 SerialUSB.println("");
}

void WriteSensor16(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor28.ino"
// Alpha sensor histogram

// Alphasensor


void InitSensor28()
{
 if (!flagON)
 {
  // begin SPI
  setAlpha = SPISettings(5000000, MSBFIRST, SPI_MODE1);
  pinMode(40, 0x1);

  // SPI begin
  SPI.begin();
  delay(1000);

  alpha_onagain();
 }
 flagON = 0x1;
}

void ConfigSensor28()
{
 return;
}

void EnableSensor28()
{
 EnableSensor(0x28);
}

void DisableSensor28()
{
 DisableSensor(0x28);
}

void ReadSensor28(byte *sensorReading, int *readingLength)
{
 delay(1000);
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);
 delay(100);

 SPI.transfer(0x30); // 0xF3
 delay(10);

 for (int i = 0; i < 62; i++)
 {
  sensorReading[i] = SPI.transfer(0x30);
  *readingLength += 1;
  delay(1);
 }

 digitalWrite(40, 0x1);
 SPI.endTransaction();
}

void WriteSensor28(byte *packet)
{
 return;
}

byte returnbyte;
void alpha_onagain()
{
 alphasense_on();
 alpha_status();

 // byte alphaStatusid = 0x2B;

 int repeat = 0;
 while ((returnbyte != 0x31) && (repeat < 10))
 {
  if (repeat != 0)
   delay(5000);
  repeat++;
  alphasense_on();
  delay(100);
  alpha_status();
 }
 // delay(1000);

 byte thisid = 0x28;
 if (returnbyte == 0x31)
  SensorEnable(thisid);
 else
  SensorDisable(thisid);
}

// Alphasense
void alphasense_on() // initialization
{
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);

 returnbyte = SPI.transfer(0x03);
 delay(10);
 returnbyte = SPI.transfer(0x00);

 digitalWrite(40, 0x1);
 SPI.endTransaction();
}

void alpha_status() // initialization
{
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);

 returnbyte = SPI.transfer(0xCF);
 digitalWrite(40, 0x1);
 SPI.endTransaction();
}

void alphasense_off() // disenable
{
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);

 returnbyte = SPI.transfer(0x03);
 delay(10);
 returnbyte = SPI.transfer(0x01);

 digitalWrite(40, 0x1);
 SPI.endTransaction();
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor29.ino"
// Alpha sensor serial

void InitSensor29()
{
 InitSensor28();
}

void ConfigSensor29()
{
 return;
}

void EnableSensor29()
{
 EnableSensor(0x29);
}

void DisableSensor29()
{
 DisableSensor(0x29);
}

void ReadSensor29(byte *sensorReading, int *readingLength)
{
 delay(1000);
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);
 delay(100);

 SPI.transfer(0x10); // 0xF3
 delay(10);

 for (int i = 0; i < 20; i++)
 {
  sensorReading[i] = SPI.transfer(0x10);
  *readingLength += 1;
  delay(1);
 }

 digitalWrite(40, 0x1);
 SPI.endTransaction();
}

void WriteSensor29(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor2A.ino"
// Chem sensor reading



void InitSensor2A()
{
 Serial3.begin(115200); // begin serial3
 Serial3.setTimeout(5000); // set timeout of serial3 as 5 sec
 pinMode(47, 0x1); // pin for chemsense power is 47
 digitalWrite(47, 0x0); // power on the device --> LOW means power on
 delay(1000);

 if (Serial3.available() > 0)
  chemConfigLength = Serial3.readBytesUntil(36, chemConfigReading, 1516);
 else
 {
  Serial3.end();
  DisableSensor(0x2A);
 }
}

void ConfigSensor2A()
{
 return;
}

void EnableSensor2A()
{
 EnableSensor(0x2A);
}

void DisableSensor2A()
{
 DisableSensor(0x2A);
}

void ReadSensor2A(byte *sensorReading, int *readingLength)
{
 ReadRS232(sensorReading, readingLength);
}

void WriteSensor2A(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor2B.ino"
// Alpha sensor serial



void InitSensor2B()
{
 InitSensor28();
}

void ConfigSensor2B()
{
 return;
}

void EnableSensor2B()
{
 EnableSensor(0x2B);
}

void DisableSensor2B()
{
 DisableSensor(0x2B);
}

void ReadSensor2B(byte *sensorReading, int *readingLength)
{
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);
 delay(100);

 returnbyte = SPI.transfer(0xCF);
 delay(10);

 for (int i = 0; i < 5; i++)
 {
  sensorReading[i] = SPI.transfer(0xCF);
  *readingLength += 1;
 }

 digitalWrite(40, 0x1);
 SPI.endTransaction();
}

void WriteSensor2B(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor2C.ino"
// Rain gauge

void InitSensor2C()
{
 // pinMode(RAIN_INTERRUPT_PIN, INPUT_PULLUP);
 // attachInterrupt(digitalPinToInterrupt(RAIN_INTERRUPT_PIN), blink, RISING);
 // delay(5);
 // pin_signal = 0;
 return;
}

void ConfigSensor2C()
{
 return;
}

void EnableSensor2C()
{
 EnableSensor(0x2C);
}

void DisableSensor2C()
{
 DisableSensor(0x2C);
}

void ReadSensor2C(byte *sensorReading, int *readingLength)
{
    return;
}

void WriteSensor2C(byte *packet)
{
 return;
}

void blink()
{
 // pin_signal++;
 // if (pin_signal == 2)
 // {
 // 	count_num++;
 // 	pin_signal = 0;
 // }
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor30.ino"
// Alpha sensor firmware version

void InitSensor30()
{
 InitSensor28();
}

void ConfigSensor30()
{
 EnableSensor(0x30);
}

void EnableSensor30()
{
 DisableSensor(0x30);
}

void DisableSensor30()
{
 return;
}

void ReadSensor30(byte *sensorReading, int *readingLength)
{
 delay(1000);
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);
 delay(100);

 returnbyte = SPI.transfer(0x12); // 0xF3
 delay(10);

 for (int i = 0; i < 2; i++)
 {
  sensorReading[i] = SPI.transfer(0x12);
  *readingLength += 1;
  delay(1);
 }

 digitalWrite(40, 0x1);
 SPI.endTransaction();
}

void WriteSensor30(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/Sensor31.ino"
// Alpha sensor configuration

void InitSensor31()
{
 InitSensor28();
}

void ConfigSensor31()
{
 return;
}

void EnableSensor31()
{
 EnableSensor(0x31);
}

void DisableSensor31()
{
 DisableSensor(0x31);
}

void ReadSensor31(byte *sensorReading, int *readingLength)
{
 SerialUSB.print("Start sending Alpha sensor configuration");
 delay(1000);
 SPI.beginTransaction(setAlpha);
 digitalWrite(40, 0x0);
 delay(100);

 SPI.transfer(0x3C); // 0xF3
 delay(10);

 for (int i = 0; i < 256; i++)
 {
  returnbyte = SPI.transfer(0x3C);
  delay(10);
  SerialUSB.write(returnbyte);
 }

 digitalWrite(40, 0x1);
 SPI.endTransaction();
 SerialUSB.print("End sending Alpha sensor configuration");
 SerialUSB.println("");
}

void WriteSensor31(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/SensorFF.ino"
// Coresense firmware version
# 10 "/home/sager/repos/sensors/v4.1/src/SensorFF.ino"
void InitSensorFF()
{
 return;
}

void ConfigSensorFF()
{
 return;
}

void EnableSensorFF()
{
 EnableSensor(0xFF);
}

void DisableSensorFF()
{
 DisableSensor(0xFF);
}

void ReadSensorFF(byte *sensorReading, int *readingLength)
{
 int first_byte = (3 /* 4 bits*/ << 5) | ((1 /* 4 bits*/ & 0x07) << 2) | ((4 /* 8 bits*/ & 0x0F) >> 2);
 int second_byte = ((4 /* 8 bits*/ & 0x0F) << 6) | ((1 /* 4 bits*/ * 10 + 0 /* 4 bits*/) & 0x3F);

 int buildinfo_git = (int) strtol(BUILD_GIT, 0, 16);

 sensorReading[0] = first_byte & 0xFF;
 sensorReading[1] = second_byte & 0xFF;
 sensorReading[2] = (BUILD_TIME >> 24) & 0xFF;
 sensorReading[3] = (BUILD_TIME >> 16) & 0xFF;
 sensorReading[4] = (BUILD_TIME >> 8) & 0xFF;
 sensorReading[5] = BUILD_TIME & 0xFF;
 sensorReading[6] = (buildinfo_git >> 8) & 0xFF;
 sensorReading[7] = buildinfo_git & 0xFF;

 *readingLength = 8;
}

void WriteSensorFF(byte *packet)
{
 return;
}
# 1 "/home/sager/repos/sensors/v4.1/src/SensorStruct.ino"

struct Sensor
{
    const byte sensorid;
    void (*initFunc)();
    void (*configFunc)();
    void (*enableFunc)();
    void (*disableFunc)();
    void (*readFunc)(byte*, int*);
    void (*writeFunc)(byte*);
};

const Sensor sensor[] = {
    {0x00, InitSensor00, ConfigSensor00, EnableSensor00, DisableSensor00, ReadSensor00, WriteSensor00},
    {0x01, InitSensor01, ConfigSensor01, EnableSensor01, DisableSensor01, ReadSensor01, WriteSensor01},
    {0x02, InitSensor02, ConfigSensor02, EnableSensor02, DisableSensor02, ReadSensor02, WriteSensor02},
    {0x03, InitSensor03, ConfigSensor03, EnableSensor03, DisableSensor03, ReadSensor03, WriteSensor03},
    {0x04, InitSensor04, ConfigSensor04, EnableSensor04, DisableSensor04, ReadSensor04, WriteSensor04},
    {0x05, InitSensor05, ConfigSensor05, EnableSensor05, DisableSensor05, ReadSensor05, WriteSensor05},
    {0x06, InitSensor06, ConfigSensor06, EnableSensor06, DisableSensor06, ReadSensor06, WriteSensor06},
    {0x07, InitSensor07, ConfigSensor07, EnableSensor07, DisableSensor07, ReadSensor07, WriteSensor07},
    {0x08, InitSensor08, ConfigSensor08, EnableSensor08, DisableSensor08, ReadSensor08, WriteSensor08},
    {0x09, InitSensor09, ConfigSensor09, EnableSensor09, DisableSensor09, ReadSensor09, WriteSensor09},
    {0x0A, InitSensor0A, ConfigSensor0A, EnableSensor0A, DisableSensor0A, ReadSensor0A, WriteSensor0A},
    {0x0B, InitSensor0B, ConfigSensor0B, EnableSensor0B, DisableSensor0B, ReadSensor0B, WriteSensor0B},
    {0x0C, InitSensor0C, ConfigSensor0C, EnableSensor0C, DisableSensor0C, ReadSensor0C, WriteSensor0C},
    {0x0D, InitSensor0D, ConfigSensor0D, EnableSensor0D, DisableSensor0D, ReadSensor0D, WriteSensor0D},
    {0x0E, InitSensor0E, ConfigSensor0E, EnableSensor0E, DisableSensor0E, ReadSensor0E, WriteSensor0E},
    {0x0F, InitSensor0F, ConfigSensor0F, EnableSensor0F, DisableSensor0F, ReadSensor0F, WriteSensor0F},
    {0x10, InitSensor10, ConfigSensor10, EnableSensor10, DisableSensor10, ReadSensor10, WriteSensor10},
    {0x13, InitSensor13, ConfigSensor13, EnableSensor13, DisableSensor13, ReadSensor13, WriteSensor13},
    {0x16, InitSensor16, ConfigSensor16, EnableSensor16, DisableSensor16, ReadSensor16, WriteSensor16},
    {0x28, InitSensor28, ConfigSensor28, EnableSensor28, DisableSensor28, ReadSensor28, WriteSensor28},
    {0x29, InitSensor29, ConfigSensor29, EnableSensor29, DisableSensor29, ReadSensor29, WriteSensor29},
    {0x2A, InitSensor2A, ConfigSensor2A, EnableSensor2A, DisableSensor2A, ReadSensor2A, WriteSensor2A},
    {0x2B, InitSensor2B, ConfigSensor2B, EnableSensor2B, DisableSensor2B, ReadSensor2B, WriteSensor2B},
    {0x2C, InitSensor2C, ConfigSensor2C, EnableSensor2C, DisableSensor2C, ReadSensor2C, WriteSensor2C},
    {0x30, InitSensor30, ConfigSensor30, EnableSensor30, DisableSensor30, ReadSensor30, WriteSensor30},
    {0x31, InitSensor31, ConfigSensor31, EnableSensor31, DisableSensor31, ReadSensor31, WriteSensor31},
    {0xFF, InitSensorFF, ConfigSensorFF, EnableSensorFF, DisableSensorFF, ReadSensorFF, WriteSensorFF},
};

const int numSensor = sizeof(sensor)/sizeof(sensor[0]);
# 1 "/home/sager/repos/sensors/v4.1/src/bus.ino"

//** I2C
void ReadI2C(byte address, int length, byte *out)
{
 ReadI2C(address, length, out, 0);
}

void ReadI2C(byte address, int length, byte *out, int time)
{
 Wire.beginTransmission(address);
 Wire.requestFrom(address, (byte)length);
 delay(time);

 if (Wire.available() > 0)
 {
  for (int i = 0; i < length; i++)
   out[i] = Wire.read();
 }
 else
 {
  for (int i = 0; i < length; i++)
   out[i] = 0xff;
 }
 Wire.endTransmission();
}

void DirectReadI2C(byte address, int length, byte *out, int time)
{
 Wire.requestFrom(address, (byte)length);
 delay(time);

 if (Wire.available() > 0)
 {
  for (int i = 0; i < length; i++)
   out[i] = Wire.read();
 }
 else
 {
  for (int i = 0; i < length; i++)
   out[i] = 0xff;
 }
}

void WriteI2C(byte address, int length, byte *in)
{
 Wire.beginTransmission(address);

 for (int i = 0; i < length; i++)
  Wire.write(in[i]);

 Wire.endTransmission();
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out)
{
 WriteReadI2C(address, inlength, in, outlength, out, 0);
}

void WriteReadI2C(byte address, int inlength, byte *in, int outlength, byte *out, int time)
{
 Wire.beginTransmission(address);
 for (int i = 0; i < inlength; i++)
  Wire.write(in[i]);
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


//** RS232
void InitRS232(int port, int powerPin, long datarate, long timeout)
{
 if (port == 3)
 {
  Serial3.begin(datarate);
  Serial3.setTimeout(timeout); //ms
  pinMode(powerPin, 0x1); // Set a GPIO pin
  digitalWrite(powerPin, 0x0); // LOW means power on
  delay(500);
 }
 else if (port == 2)
 {
  Serial2.begin(datarate);
  Serial2.setTimeout(timeout);
  pinMode(powerPin, 0x1);
  digitalWrite(powerPin, 0x0);
  delay(500);
 }
 else if (port == 1)
 {
  Serial1.begin(datarate);
  Serial1.setTimeout(timeout);
  pinMode(powerPin, 0x1);
  digitalWrite(powerPin, 0x0);
  delay(500);
 }
}


byte inputbyte;
void ReadRS232(byte* reading, int* NumVal, int port)
{
 int len = 0;

 if (port == 3)
 {
  while (Serial3.available() > 0)
   inputbyte = Serial3.read();

  len = Serial3.readBytesUntil('\n', reading, 256);
 }

 else if (port == 2)
 {
  while (Serial2.available() > 0)
   inputbyte = Serial2.read();

  len = Serial2.readBytesUntil('\n', reading, 256);
 }

 else if (port == 1)
 {
  while (Serial1.available() > 0)
   inputbyte = Serial1.read();
  len = Serial1.readBytesUntil('\n', reading, 256);
 }

 reading[len] = '\0';
 *NumVal = len;
}

void ReadRS232(byte* reading, int *sumlen)
{
 while (Serial3.available() > 0)
  inputbyte = Serial3.read();

 int len = 0;
 len = Serial3.readBytesUntil('\n', reading, 256);
 *sumlen = len;

 reading[len - 1] = ' ';

 // int len = 0;
 // for (int i = 0; i < 3; i++)
 // {
 // 	len = Serial3.readBytesUntil('\n', reading, 256);
 // 	*sumlen += len;

 // 	SerialUSB.print("this is :");
 // 	SerialUSB.print(i);
 // 	SerialUSB.print("th reading, with length ");
 // 	SerialUSB.println(len);
 // 	for (int i = 0; i < len; i++)
 // 		SerialUSB.println(reading[i]);
 // }
 // SerialUSB.println("EEENNNNNDDDDD");
}

void WriteRS232(byte* writing, int length, int port)
{
 if (port == 3)
  Serial3.write(writing, length);
 else if (port == 2)
  Serial3.write(writing, length);
 else if (port == 1)
  Serial3.write(writing, length);
}

//** SPI


SPISettings SetSPI(long maxSpeed, byte bitOrder, byte dataMode, byte pin)
{
 SPISettings set;
 if (bitOrder == 1)
 {
  if (dataMode == 0)
   set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE0);
  else if (dataMode == 1)
   set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE1);
  else if (dataMode == 2)
   set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE2);
  else if (dataMode == 3)
   set = SPISettings(maxSpeed, MSBFIRST, SPI_MODE3);
 }
 else if (bitOrder == 0)
 {
  if (dataMode == 0)
   set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE0);
  else if (dataMode == 1)
   set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE1);
  else if (dataMode == 2)
   set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE2);
  else if (dataMode == 3)
   set = SPISettings(maxSpeed, LSBFIRST, SPI_MODE3);
 }
 pinMode(pin, 0x1);

 return set;
}

void ReadSPI(byte* buff, int bufflen, byte pin, SPISettings set)
{
 ReadSPI(buff, bufflen, pin, set, 0, 0);
}

void ReadSPI(byte* buff, int bufflen, byte pin, SPISettings set, int msdelay, int delayiter)
{
 SPI.beginTransaction(set);
 delay(400);
 digitalWrite(pin, 0x0);

 for (int i = 0; i < bufflen; i++)
 {
  SPI.transfer(buff[i]);

  if (i < delayiter)
   delay(msdelay);
 }

 digitalWrite(pin, 0x1);
 SPI.endTransaction();
}

void WriteSPI(byte* buff, int bufflen, byte pin, SPISettings set)
{
 WriteSPI(buff, bufflen, pin, set, 0, 0);
}

void WriteSPI(byte* buff, int bufflen, byte pin, SPISettings set, int msdelay, int delayiter)
{
 SPI.beginTransaction(set);
 delay(400);
 digitalWrite(pin, 0x0);

 for (int i = 0; i < bufflen; i++)
 {
  buff[i] = SPI.transfer(buff[i]);

  if (i < delayiter)
   delay(msdelay);
 }

 digitalWrite(pin, 0x1);
 SPI.endTransaction();
}



//** EEPROM


void writeEEPROM (unsigned int memory_address, byte data_byte )
{
    Wire.beginTransmission(0x50);
    Wire.write((int)(memory_address >> 8)); // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.write(data_byte);
    Wire.endTransmission();
    delay(5);
}

byte readEEPROM (unsigned int memory_address )
{
    byte recv_data = 0xff;

    Wire.beginTransmission(0x50);
    Wire.write((int)(memory_address >> 8)); // MSB
    Wire.write((int)(memory_address & 0xFF)); // LSB
    Wire.endTransmission();
    Wire.requestFrom(0x50,1);

    if (Wire.available())
        recv_data = Wire.read();

    return recv_data;
}
# 1 "/home/sager/repos/sensors/v4.1/src/crc8waggle.ino"
/** Calculate CRC8 ********************************************************************/
byte CRCcalc(byte dataLength, byte *packet)
{
    byte crc = 0x00;

    for (int i = 0x03; i < (dataLength + 0x03); i++) // 0x03 accounts for header
        crc = CRC8Waggle(packet[i], crc);

    return crc;
}
/**************************************************************************************/


/** Calculate CRC, byte by byte *******************************************************/
byte CRC8Waggle(byte data, byte crc)
{
    byte i;
    crc ^= data;

    for (i = 0x00; i < 0x08; i++)
    {
        if (crc & 0x01)
            crc = (crc >> 0x01) ^ 0x8C;
        else
            crc = crc >> 0x01;
    }

    return(crc);
}
/**************************************************************************************/
# 1 "/home/sager/repos/sensors/v4.1/src/enabletable.ino"

void EnableSensor(byte thisid)
{
 thisid = Checkid(thisid);

 for (int i = 0; i < numEnabled; i++)
 {
  EnabledTable *et = enabledtable + i;
  if (et->enabledsensorid == thisid)
  {
   et->enabled = 0x1;
   break;
  }
 }
}
void DisableSensor(byte thisid)
{
 for (int i = 0; i < numEnabled; i++)
 {
  EnabledTable *et = enabledtable + i;
  if (et->enabledsensorid == thisid)
  {
   et->enabled = 0x0;
   break;
  }
 }
}
bool GetEnable(byte thisid)
{
 thisid = Checkid(thisid);

 for (int i = 0; i < numEnabled; i++)
 {
  EnabledTable *et = enabledtable + i;
  if (et->enabledsensorid == thisid)
   return et->enabled;
 }
 return 0x0;
}
byte Checkid(byte thisid)
{
 if (0x28 <= thisid && thisid <= 0x31)
  thisid = 0x28; // option for alpha sensor
 else if (thisid == 0x16)
  thisid = 0x2A; // option for chem config

 return thisid;
}
# 1 "/home/sager/repos/sensors/v4.1/src/main.ino"
// variables for firmware
# 3 "/home/sager/repos/sensors/v4.1/src/main.ino" 2

/* for main loop */




int bufferIndex = 0;
byte inputarray[1024 /* possible data bytes 256, 4 headers, 2 footers*/]; // Length of this byte array has to be the same with MaxInputLength
byte input = '\0';

// Heart beat

bool UP_DOWN;

void setup()
{
 pinMode(8 /* HBEAT PIN (ON/OFF)*/, 0x1);

 delay(2000);
 SerialUSB.begin(115200);
 delay(100);

 // wire for sensors on met/lightsense boards
 // AND initialization for sensors on met/lightsense boards
 Wire.begin();
 delay(100);

 // What sensors does this initialize?
 SensorInit();
 PacketInit();
 BusPacketInit();

 Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start(); //every 1000ms
}

void loop()
{
 while (SerialUSB.available())
 {
  inputarray[bufferIndex] = SerialUSB.read();
  if (bufferIndex == 1024 /* possible data bytes 256, 4 headers, 2 footers*/)
   break;
  bufferIndex++;
 }

 int startByteIndex = 0;
 for (int i = 0; i < bufferIndex; i++)
 {
  if (inputarray[i] == 0xAA)
  {
   startByteIndex = i;
   break;
  }
 }

 for (int i = startByteIndex; i < bufferIndex; i++)
  inputarray[i - startByteIndex] = inputarray[i];
 bufferIndex -= startByteIndex;

 if (bufferIndex > 4)
 {
  int dataLength = inputarray[2];
  int packetLength = dataLength + 3 + 2;
  if (bufferIndex >= packetLength)
  {
   byte packet[packetLength];
   for (int i = 0; i < bufferIndex; i++)
   {
    if (i < packetLength)
     packet[i] = inputarray[i];
    else
     inputarray[i - packetLength] = inputarray[i];
   }
   bufferIndex -= packetLength;

   byte checkcrc = CRCcalc(dataLength, packet);
   int request = (packet[1] >> 4) & 0x0F;
   int protocol = packet[1] & 0x0F;
   if ((checkcrc == packet[dataLength + 3]) && (request == 0) && (protocol == 2))
   // if ((request == 0) && (protocol == 2))   // For simple debug using corepacketTalker.py
    SortReading(packet, dataLength);
  }
 }
}

void handler()
{
    UP_DOWN =! UP_DOWN;
    digitalWrite(8 /* HBEAT PIN (ON/OFF)*/, UP_DOWN);
}
# 1 "/home/sager/repos/sensors/v4.1/src/packetassembler.ino"

int packetseq = 0;
int outLength = 4; // start at 4 to account for header and sequence

int protocolver = 0x02;
int packetType = 0x01;

byte sequenceValidity = 0x00;

byte packet[2048];


///////// Bus seperately --> different packet type
int busPacketSeq = 0;
int busOutLength = 4; // start at 4 to account for header and sequence
int busPacketType = 0x02;

byte busSequenceValidity = 0x00;

byte busPacket[2048];


void Packetization(byte thisid, byte *sensorReading, int readingLength)
{
    PacketLengthCheck(readingLength);

    int sensorReadingValidity = 1;

    packet[outLength++] = thisid;
    packet[outLength++] = (sensorReadingValidity << 7) | readingLength; // valid data

    for (int i = 0; i < readingLength; i++)
        packet[outLength++] = sensorReading[i];
}

void PacketLengthCheck(int readingLength)
{
    if (((outLength - 1 + readingLength) > 128) && (outLength > 4))
    {
        PacketSender(0x00); // not the last packet for this request
        packetseq++;
        MultiPacketInit(); // for the last packet of this request
    }
}

void PacketSender(byte sequenceValidity)
{
    if (busOutLength > 4)
        sequenceValidity = 0x00;

    packet[2] = outLength - 3; // data length - header (means including seq byte)
    packet[3] = (sequenceValidity << 7) | packetseq;
    byte crc = CRCcalc(outLength - 3, packet);
    packet[outLength++] = crc; // Append CRC8
    packet[outLength++] = 0x55; // postscript

    SerialUSB.write(packet, outLength);
    SerialUSB.println("");
    // SerialUSB.flush();

    outLength = 0;
}

void MultiPacketInit()
{
    outLength = 4;
    byte lastPacket = 0x01;

    packet[0] = 0xAA; // preamble
    packet[1] = (packetType << 4) | protocolver; // data type --> sensor reading = 0x01 | protocol
    packet[2] = outLength; // data length
    packet[3] = (lastPacket << 7) | packetseq; // seq, MSB of first sequence is 1
}

void PacketInit()
{
    outLength = 4;
    packetseq = 0;
    byte lastPacket = 0x01;

    packet[0] = 0xAA; // preamble
    packet[1] = (packetType << 4) | protocolver; // data type --> sensor reading = 0x01 | protocol
    packet[2] = outLength; // data length
    packet[3] = (lastPacket << 7) | packetseq; // seq, MSB of first sequence is 1
}

int ReturnPacketLength()
{
    return outLength;
}


/////////////////////////////////////////////////////////////////////////////
void BusPacketization(byte thisid, byte address, byte *sensorReading, int readingLength)
{
    BusPacketLengthCheck(readingLength);

    int BusSensorReadingValidity = 1;

    busPacket[busOutLength++] = 0x11;
    busPacket[busOutLength++] = (BusSensorReadingValidity << 7) | (readingLength + 2); // valid data
    busPacket[busOutLength++] = thisid;
    busPacket[busOutLength++] = address;

    for (int i = 0; i < readingLength; i++)
        busPacket[busOutLength++] = sensorReading[i];
}

void BusPacketLengthCheck(int readingLength)
{
    if ((busOutLength - 1 + readingLength) > 128)
    {
        BusPacketSender(0x00); // not the last busPacket for this request
        busPacketSeq++;
        BusMultiPacketInit(); // for the last busPacket of this request
    }
}

void BusPacketSender(byte sequenceValidity)
{
    if (outLength > 4)
        busSequenceValidity = 0x00;

    busPacket[2] = busOutLength - 3; // data length - header (means including seq byte)
    busPacket[3] = (sequenceValidity << 7) | busPacketSeq;
    byte crc = CRCcalc(busOutLength - 3, busPacket);
    busPacket[busOutLength++] = crc; // Append CRC8
    busPacket[busOutLength++] = 0x55; // postscript

    for (int i = 0; i < busOutLength; i++)
        SerialUSB.write(busPacket[i]);
    SerialUSB.println("");

    busOutLength = 0;
}

void BusMultiPacketInit()
{
    busOutLength = 4;
    byte lastPacket = 0x01;

    busPacket[0] = 0xAA; // preamble
    busPacket[1] = (busPacketType << 4) | protocolver; // data type --> sensor reading = 0x01 | protocol
    busPacket[2] = busOutLength; // data length
    busPacket[3] = (lastPacket << 7) | busPacketSeq; // seq, MSB of first sequence is 1
}

void BusPacketInit()
{
    busOutLength = 4;
    busPacketSeq = 0;
    byte lastPacket = 0x01;

    busPacket[0] = 0xAA; // preamble
    busPacket[1] = (busPacketType << 4) | protocolver; // data type --> sensor reading = 0x01 | protocol
    busPacket[2] = busOutLength; // data length
    busPacket[3] = (lastPacket << 7) | busPacketSeq; // seq, MSB of first sequence is 1
}

int BusReturnPacketLength()
{
    return busOutLength;
}
# 1 "/home/sager/repos/sensors/v4.1/src/sorter.ino"

byte sensorReading[1024];
int readingLength = 0;

void SortReading(byte *packet, int dataLength)
{
 PacketInit();
 BusPacketInit();
 byte *subpacket = packet + 4; // put subpacket value as address of last packet byte
 while (subpacket < &packet[dataLength + 3])
 {
  byte type = subpacket[0];
  // byte ack = subpacket[1] & 0x80;
  byte paramLength = subpacket[1] & 0x7F;
  byte id = subpacket[2];

  byte Asubpacket[paramLength + 1];
  for (int i = 0; i < paramLength + 1; i++)
   Asubpacket[i] = subpacket[i + 1];

  for (int i = 0; i < numType; i++)
  {
   const FunctionType *ft = functype + i;
   if (ft->funcid == type)
   {
    ft->func(Asubpacket, id);
    break;
   }
  }
  subpacket += paramLength + 2;
 }
 int SensorReadingLength = ReturnPacketLength();
 int BusReadingLength = BusReturnPacketLength();
 if (SensorReadingLength > 4)
  PacketSender(0x01);
 if (BusReadingLength > 4)
  BusPacketSender(0x01);

}

void SensorInit()
{
 // Enable mandatory sensors
 for (int i = 0; i < numMand; i++)
 {
  const MandatorySensor *ms = mandsensor + i;
  ms->enableFunc();
 }

 for (int i = 0; i < numSensor; i++)
 {
  const Sensor *s = sensor + i;
  s->initFunc();
 }
}

void SensorInit(byte *data, byte id)
{
 for (int i = 0; i < numSensor; i++)
 {
  const Sensor *s = sensor + i;
  if (s->sensorid == id)
  {
   s->initFunc();
   break;
  }
 }
}

void SensorConfig(byte *data, byte id)
{
 for (int i = 0; i < numSensor; i++)
 {
  const Sensor *s = sensor + i;
  if (s->sensorid == id)
  {
   s->configFunc();
   break;
  }
 }
}

void SensorEnable(byte id)
{
 for (int i = 0; i < numSensor; i++)
 {
  const Sensor *s = sensor + i;
  if (s->sensorid == id)
  {
   s->enableFunc();
   break;
  }
 }
}

void SensorEnable(byte *data, byte id)
{
 SensorEnable(id);
}

void SensorDisable(byte id)
{
 for (int i = 0; i < numSensor; i++)
 {
  const Sensor *s = sensor + i;
  if (s->sensorid == id)
  {
   s->disableFunc();
   break;
  }
 }
}

void SensorDisable(byte *data, byte id)
{
 SensorDisable(id);
}

void SensorRead(byte *data, byte id)
{
 bool enable = GetEnable(id);

 if (!enable)
  return;

 int paramLength = data[0] & 0x7F;
 int repeat = 0;
 int interval = 0;
 if (paramLength == 2)
  repeat = data[1];
 else if (paramLength == 3)
 {
  repeat = data[1];
  interval = 1000 / data[2];
 }

 for (int i = 0; i < numSensor; i++)
 {
  const Sensor *s = sensor + i;
  if (s->sensorid == id)
  {
   if (id == 0x2A)
    repeat = 3;

   if (paramLength > 1 || id == 0x2A)
   {
    for (int i = 0; i < repeat; i++)
    {
     s->readFunc(sensorReading, &readingLength);
     Packetization(id, sensorReading, readingLength);
     delay(interval);
    }
    break;
   }

   s->readFunc(sensorReading, &readingLength);
   Packetization(id, sensorReading, readingLength);
   break;
  }
 }
 readingLength = 0;
}


void SensorWrite(byte *data, byte id)
{
 for (int i = 0; i < numSensor; i++)
 {
  const Sensor *s = sensor + i;
  if (s->sensorid == id)
  {
   s->writeFunc(data);
   break;
  }
 }
}





void BusInit(byte *data, byte id)
{
 for (int i = 0; i < numBus; i++)
 {
  const Bus *b = bus + i;
  if (b->busid == id)
  {
   b->initFunc(data);
   break;
  }
 }
}

void BusConfig(byte *data, byte id)
{
 for (int i = 0; i < numBus; i++)
 {
  const Bus *b = bus + i;
  if (b->busid == id)
  {
   b->configFunc(data);
   break;
  }
 }
}
void BusEnable(byte *data, byte id)
{
 for (int i = 0; i < numBus; i++)
 {
  const Bus *b = bus + i;
  if (b->busid == id)
  {
   b->enableFunc();
   break;
  }
 }
}
void BusDisable(byte *data, byte id)
{
 for (int i = 0; i < numBus; i++)
 {
  const Bus *b = bus + i;
  if (b->busid == id)
  {
   b->disableFunc();
   break;
  }
 }
}
void BusRead(byte *data, byte id)
{
 byte subLength = data[0] & 0x7F;
 // byte busType = data[1];  // receives as "id"
 byte busAddressId = data[2];

 byte params[subLength];
 for (int i = 0; i < subLength - 2; i++)
  params[i] = data[i + 3];

 if (id < 0x02)
 {
  for (int i = 0; i < numParamBus; i++)
  {
   const paramBus *pb = parambus + i;
   if (pb->bustype == id)
   {
    if (pb->busid == busAddressId)
    {
     pb->readFunc(params, sensorReading, &readingLength);
     BusPacketization(id, busAddressId, sensorReading, readingLength);
    }
   }
  }
 }
 else if (id >= 0x02)
 {
  for (int i = 0; i < numBus; i++)
  {
   const Bus *b = bus + i;
   if (b->bustype == id)
   {
    if (b->busid == busAddressId)
    {
     b->readFunc(sensorReading, &readingLength);
     BusPacketization(id, busAddressId, sensorReading, readingLength);
     break;
    }
   }
  }
 }
 readingLength = 0;
}
void BusWrite(byte *data, byte id)
{
 for (int i = 0; i < numSensor; i++)
 {
  const Bus *b = bus + i;
  if (b->busid == id)
  {
   b->writeFunc(data);
   break;
  }
 }
}
