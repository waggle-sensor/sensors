# 1 "/home/waggle/repo/sensors/vibration_test/firmware/SimpleTimer/SimpleTimer.ino"
# 1 "/home/waggle/repo/sensors/vibration_test/firmware/SimpleTimer/SimpleTimer.ino"
# 2 "/home/waggle/repo/sensors/vibration_test/firmware/SimpleTimer/SimpleTimer.ino" 2
# 3 "/home/waggle/repo/sensors/vibration_test/firmware/SimpleTimer/SimpleTimer.ino" 2
# 4 "/home/waggle/repo/sensors/vibration_test/firmware/SimpleTimer/SimpleTimer.ino" 2




const byte OUT_X_MSB = 0x01;
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

byte sensorReading[6];

void myHandler(){
    sensorReading[0] = 0x53;
    sensorReading[1] = 0x45;
    sensorReading[2] = 0x43;
    sensorReading[3] = 0x4F;
    sensorReading[4] = 0x4E;
    sensorReading[5] = 0x44;

    writeFrame(sensorReading, 6);
}


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


    // Set Due timer
    Timer3.attachInterrupt(myHandler);
    // Timer3.start(1250); // Calls every 1250us
    Timer3.start(1000000); // Calls every second
}



void loop() {
    Wire.requestFrom((uint8_t)0x1C, (uint8_t)6, (uint32_t)OUT_X_MSB, (uint8_t)1, 0x1);
    lastSampleTime = micros();

    while (Wire.available() < 6)
        delayMicroseconds(1);


    for (int i = 0; i < 6; i++)
        sensorReading[i] = Wire.read();

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
