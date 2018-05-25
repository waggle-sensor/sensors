 
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
    {0x28, InitSensor28, ConfigSensor28, EnableSensor28, DisableSensor28, ReadSensor28, WriteSensor28},
    {0x29, InitSensor29, ConfigSensor29, EnableSensor29, DisableSensor29, ReadSensor29, WriteSensor29},
    {0x2A, InitSensor2A, ConfigSensor2A, EnableSensor2A, DisableSensor2A, ReadSensor2A, WriteSensor2A},
    {0x2B, InitSensor2B, ConfigSensor2B, EnableSensor2B, DisableSensor2B, ReadSensor2B, WriteSensor2B},
    {0x2C, InitSensor2C, ConfigSensor2C, EnableSensor2C, DisableSensor2C, ReadSensor2C, WriteSensor2C},
    {0x2D, InitSensor2D, ConfigSensor2D, EnableSensor2D, DisableSensor2D, ReadSensor2D, WriteSensor2D},
    {0x30, InitSensor30, ConfigSensor30, EnableSensor30, DisableSensor30, ReadSensor30, WriteSensor30},
    {0x31, InitSensor31, ConfigSensor31, EnableSensor31, DisableSensor31, ReadSensor31, WriteSensor31},
    {0x32, InitSensor32, ConfigSensor32, EnableSensor32, DisableSensor32, ReadSensor32, WriteSensor32},
    {0x36, InitSensor36, ConfigSensor36, EnableSensor36, DisableSensor36, ReadSensor36, WriteSensor36},
    {0xFF, InitSensorFF, ConfigSensorFF, EnableSensorFF, DisableSensorFF, ReadSensorFF, WriteSensorFF},
};
 
const int numSensor = sizeof(sensor)/sizeof(sensor[0]);
