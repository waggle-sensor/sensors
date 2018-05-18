// Coresense firmware version

#define CORESENSE_HW_VER_MAJ 3
#define CORESENSE_HW_VER_MIN 1

#define CORESENSE_KERNEL_MAJ 4
#define CORESENSE_KERNEL_MIN 13

void InitSensorFF()
{
	return;
}

void ConfigSensorFF()
{
	return;
}

void EnableSensorFF()
{
	EnableSensor(0xFF);
}

void DisableSensorFF()
{
	DisableSensor(0xFF);
}

void ReadSensorFF(byte *sensorReading, int *readingLength)
{
	int buildinfo_git = (int) strtol(BUILD_GIT, 0, 16);

	sensorReading[0] = CORESENSE_HW_VER_MAJ;
	sensorReading[1] = CORESENSE_HW_VER_MIN;
	sensorReading[2] = CORESENSE_KERNEL_MAJ;
	sensorReading[3] = CORESENSE_KERNEL_MIN;
	
	sensorReading[4] = (BUILD_TIME >> 24) & 0xFF;
	sensorReading[5] = (BUILD_TIME >> 16) & 0xFF;
	sensorReading[6] = (BUILD_TIME >> 8) & 0xFF;
	sensorReading[7] = BUILD_TIME & 0xFF;
	sensorReading[8] = (buildinfo_git >> 8) & 0xFF;
	sensorReading[9] = buildinfo_git & 0xFF;

	*readingLength = 10;
}

void WriteSensorFF(byte *packet)
{
	return;
}
