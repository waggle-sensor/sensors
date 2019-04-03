#!/bin/bash

port=$1

if [ -z "$port" ]; then
	echo no target device provided
	exit 1
fi

arduino-cli upload -b arduino:sam:arduino_due_x -i bin/firmware.ino.bin -p "$port"
