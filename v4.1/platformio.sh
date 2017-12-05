#!/bin/bash
cd ./src
./setbuildtime.sh
./buildStruct.sh

echo ' ' > Sensor28-31.h
if [[ $1 == --alpha-in ]]; then
	echo 'bool flagON = false;' >> Sensor28-31.h
elif [[ $1 == --alpha-ex ]]; then
	echo 'bool flagON = true;' >> Sensor28-31.h
else
	echo "ERROR: first input argument --alpha-in if alpha sensor is included, --alpha-ex if not"
fi
echo 'SPISettings setAlpha;' >> Sensor28-31.h

cd ..

if [[ $2 == '-c' ]]; then
	platformio run
elif [[ $2 == '-f' ]]; then
	platformio run -t upload
else
	echo "ERROR: second input argument -c for compiling, -f for flash firmware"
	exit 0
fi
