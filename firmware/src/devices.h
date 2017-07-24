#include <Wire.h>

struct Device {
	const char *name;
	int (*init)();
	int (*read)(int *);
};

void InitDevices();
const Device *FindDevice(const char *name);
void ListDevices();
