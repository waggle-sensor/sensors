#!/bin/bash
cd ./src
./setbuildtime.sh
./buildStruct.sh
cd ..

if [[ $1 == '-c' ]]; then
	platformio run
elif [[ $1 == '-f' ]]; then
	platformio run -t upload
else
	echo "ERROR: input argument -c for compiling, -f for flash firmware"
	exit 0
fi
