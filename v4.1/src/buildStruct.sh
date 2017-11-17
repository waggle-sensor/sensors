#!/bin/bash

## CoreSensor
echo ' ' >> SensorStruct.h
echo 'struct Sensor' > SensorStruct.h
echo '{' >> SensorStruct.h
echo '    const byte sensorid;' >> SensorStruct.h
echo '    void (*initFunc)();' >> SensorStruct.h
echo '    void (*configFunc)();' >> SensorStruct.h
echo '    void (*enableFunc)();' >> SensorStruct.h
echo '    void (*disableFunc)();' >> SensorStruct.h
echo '    void (*readFunc)(byte*, int*);' >> SensorStruct.h
echo '    void (*writeFunc)(byte*, int*);' >> SensorStruct.h
echo '};' >> SensorStruct.h
echo ' ' >> SensorStruct.h
echo 'const Sensor sensor[] = {' >> SensorStruct.h


## Bus
echo ' ' >> BusStruct.h
echo 'struct Bus' > BusStruct.h
echo '{' >> BusStruct.h
echo '    const byte busid;' >> BusStruct.h
echo '    void (*initFunc)(byte*, int*);' >> BusStruct.h
echo '    void (*configFunc)(byte*, int*);' >> BusStruct.h
echo '    void (*enableFunc)(byte*, int*);' >> BusStruct.h
echo '    void (*disableFunc)(byte*, int*);' >> BusStruct.h
echo '    void (*readFunc)(byte*, int*);' >> BusStruct.h
echo '    void (*writeFunc)(byte*, int*);' >> BusStruct.h
echo '};' >> BusStruct.h
echo ' ' >> BusStruct.h
echo 'const Bus bus[] = {' >> BusStruct.h


## Enable table
echo 'struct EnabledTable' > EnabledStruct.h
echo '{' >> EnabledStruct.h
echo '    const byte enabledsensorid;' >> EnabledStruct.h
echo '    bool enabled;' >> EnabledStruct.h
echo '};' >> EnabledStruct.h
echo ' ' >> EnabledStruct.h
echo 'EnabledTable enabledtable[] = {' >> EnabledStruct.h


ls | while read line
do
    if [[ $line == *".ino" && $line == *"Sensor"* ]]; then
        f=$(echo $line | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1)
        n=$(echo $f | cut -d 'r' -f 2)
        echo '    {0x'$n', InitSensor'$n', ConfigSensor'$n', EnableSensor'$n', DisableSensor'$n', ReadSensor'$n', WriteSensor'$n'},' >> SensorStruct.h
        echo '    {0x'$n', false}' >> EnabledTable.h
        # echo $line | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1 >> SensorStruct.h
    elif [[ $line == *".ino" && $line == *"Bus"* ]]; then
        f=$(echo $line | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1)
        n=$(echo $f | cut -d 'r' -f 2)
        echo '    {0x'$n', InitBus'$f', ConfigBus'$f', EnableBus'$f', DisableBus'$f', ReadBus'$f', WriteBus'$f'},' >> BusStruct.h
        # echo $line | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1 >> SensorStruct.h
    fi
done

echo '};' >> SensorStruct.h
echo '};' >> BusStruct.h
echo '};' >> EnabledTable.h
