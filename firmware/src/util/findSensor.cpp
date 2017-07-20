// #include "findSensor.h"

// static const I2CDevice devices[] = {
// 	{"mac", 0x00},
// 	{"tmp112", 0x01},
// 	{"htu21d", 0x02},
// };
//
// static const int numdevices = sizeof(devices) / sizeof(devices[0]);
//
// const I2CDevice *FindI2CDevice(const char *name) {
// 	for (int i = 0; i < numdevices; i++) {
// 		const I2CDevice *device = &devices[i];
//
// 		if (strcmp(device->name, name) == 0) {
// 			return device;
// 		}
// 	}
//
// 	return NULL;
// }

// const char *sArray[NofSensor] = {"mac", "tmp112", "htu21d", "bmp180",
// 								 "pr103j2", "tsl250", "mma8452q", "spv1840",
// 								 "tsys01",
// 								 "hmc5883l", "hih6130", "apds9006", "tsl260rd",
// 								 "tsl250rd", "mlx75305", "ml8511", "tmp421"};
//
//
// const byte bArray[NofSensor] = {0x00, 0x01, 0x02, 0x03,
// 								0x04, 0x05, 0x06, 0x07,
// 								0x08,
// 								0x10, 0x11, 0x12, 0x13,
// 								0x14, 0x15, 0x16, 0x17};

// byte Sensor::sensorID(const char *key) {
// 	for (int i = 0; i < NofSensor; i++)
// 	{
// 		condition = matches(key, sArray[i]);
// 		if (condition)
// 			return bArray[i];
// 	}
//
//     return 0xff;
// }
//
// void Sensor::sensorName(byte sensor_ID, char** sensorNM)
// {
// 	for (int i = 0; i < NofSensor; i++)
// 	{
// 		if (sensor_ID == bArray[i])
// 			*sensorNM = (char*) sArray[i];
// 	}
// }
