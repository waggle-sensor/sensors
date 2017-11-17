struct Bus
{
    const byte sensorid;
    void (*initFunc)(byte*, int*);
    void (*configFunc)(byte*, int*);
    void (*enableFunc)(byte*, int*);
    void (*disableFunc)(byte*, int*);
    void (*readFunc)(byte*, int*);
    void (*writeFunc)(byte*, int*);
};
const Bus bus[] = {
};
