# How files are related

main_4.ino: main file, initializes communication lines, reads serial
	Calls sorter.ino to figure out what serial has gotten
sorter.ino: sorts serial read to commands, sensor id, and so on and calls relevant functions
	Calls functions in initialization.ino or coresense.ino or bus.ino
initialization.ino: contains initialization functions for all core sensors
	some functions are called when coresense is powered on, and some need to be called 
coresense.ino: contains read functions for all core sensors
	Calls functions in packetassembler.ino


packetassembler.ino:

variables.h:
