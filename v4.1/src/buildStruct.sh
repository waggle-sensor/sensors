#!/bin/bash

# CoreSensor
echo ' ' >> SensorStruct.ino
echo 'struct Sensor' > SensorStruct.ino
echo '{' >> SensorStruct.ino
echo '    const byte sensorid;' >> SensorStruct.ino
echo '    void (*initFunc)();' >> SensorStruct.ino
echo '    void (*configFunc)();' >> SensorStruct.ino
echo '    void (*enableFunc)();' >> SensorStruct.ino
echo '    void (*disableFunc)();' >> SensorStruct.ino
echo '    void (*readFunc)(byte*, int*);' >> SensorStruct.ino
echo '    void (*writeFunc)(byte*, int*);' >> SensorStruct.ino
echo '};' >> SensorStruct.ino
echo ' ' >> SensorStruct.ino
echo 'const Sensor sensor[] = {' >> SensorStruct.ino


## Bus
echo ' ' >> BusStruct.ino
echo 'struct Bus' > BusStruct.ino
echo '{' >> BusStruct.ino
echo '    const byte bustype;' >> BusStruct.ino
echo '    const byte busid;' >> BusStruct.ino
echo '    void (*initFunc)(byte*, int*);' >> BusStruct.ino
echo '    void (*configFunc)(byte*, int*);' >> BusStruct.ino
echo '    void (*enableFunc)(byte*, int*);' >> BusStruct.ino
echo '    void (*disableFunc)(byte*, int*);' >> BusStruct.ino
echo '    void (*readFunc)(byte*, int*);' >> BusStruct.ino
echo '    void (*writeFunc)(byte*, int*);' >> BusStruct.ino
echo '};' >> BusStruct.ino
echo ' ' >> BusStruct.ino
echo 'const Bus bus[] = {' >> BusStruct.ino


## Enable table
echo ' ' >> EnabledStruct.ino
echo 'struct EnabledTable' > EnabledStruct.ino
echo '{' >> EnabledStruct.ino
echo '    const byte enabledsensorid;' >> EnabledStruct.ino
echo '    bool enabled;' >> EnabledStruct.ino
echo '};' >> EnabledStruct.ino
echo ' ' >> EnabledStruct.ino
echo 'EnabledTable enabledtable[] = {' >> EnabledStruct.ino

echo 'start'

ls | grep -i Sensor'[0-9,a-f][0-9,a-f]'.ino | while read line
do
    f=$(echo $line | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1)
    n=$(echo $f | cut -d 'r' -f 2)
    echo '    {0x'$n', InitSensor'$n', ConfigSensor'$n', EnableSensor'$n', DisableSensor'$n', ReadSensor'$n', WriteSensor'$n'},' >> SensorStruct.ino
    echo '    {0x'$n', false},' >> EnabledStruct.ino
done

ls | grep Bus.*.[0-9,A-F][0-9,A-F].ino | while read line
do
        f=$(echo $line | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1)
        t=${f:3:-2}
        n=${f:(-2)}
        if [[ $t == 'Serial' ]]; then
            b=00
        elif [[ $t == 'I2C' ]]; then
            b=01
        elif [[ $t == 'SPI' ]]; then
            b=02
        fi
        echo '    {0x'$b', 0x'$n', InitBus'$n$f', ConfigBus'$n$f', EnableBus'$n$f', DisableBus'$n$f', ReadBus'$n$f', WriteBus'$n$f'},' >> BusStruct.ino
done

echo '};' >> SensorStruct.ino
echo '};' >> BusStruct.ino
echo '};' >> EnabledStruct.ino

echo ' ' >> SensorStruct.ino
echo ' ' >> BusStruct.ino
echo ' ' >> EnabledStruct.ino

echo 'const int numSensor = sizeof(sensor)/sizeof(sensor[0]);' >> SensorStruct.ino
echo 'const int numBus = sizeof(bus)/sizeof(bus[0]);' >> BusStruct.ino
echo 'const int numEnabled = sizeof(enabledtable)/sizeof(enabledtable[0]);' >> EnabledStruct.ino
