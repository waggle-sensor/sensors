struct Sensor
{
    const byte sensorid;
    void (*initFunc)(byte*, int*);
    void (*configFunc)(byte*, int*);
    void (*enableFunc)(byte*, int*);
    void (*disableFunc)(byte*, int*);
    void (*readFunc)(byte*, int*);
    void (*writeFunc)(byte*, int*);
};
const Sensor sensor[] = {
    {0x00, InitSensor00, ConfigSensor00, EnableSensor00, DisableSensor00, ReadSensor00, WriteSensor00},
};
