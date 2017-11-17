// Coresense firmware version

void InitSensorFF(byte *sensorReading, int *readingLength)
{
	return;
}

void ConfigSensorFF(byte *sensorReading, int *readingLength)
{
	return;
}

void EnableSensorFF(byte *sensorReading, int *readingLength)
{
	EnableSensor(0xFF);
}

void DisableSensorFF(byte *sensorReading, int *readingLength)
{
	DisableSensor(0xFF);
}

void ReadSensorFF(byte *sensorReading, int *readingLength)
{
	int first_byte = (CORESENSE_HW_VER_MAJ << 5) | ((CORESENSE_HW_VER_MIN & 0x07) << 2) | ((CORESENSE_KERNEL_MAJ & 0x0F) >> 2);
	int second_byte = ((CORESENSE_KERNEL_MAJ & 0x0F) << 6) | ((CORESENSE_KERNEL_MIN * 10 + CORESENSE_KERNEL_SUB) & 0x3F);

	int buildinfo_git = (int) strtol(BUILD_GIT, 0, 16);

	sensorReading[0] = first_byte & 0xFF;
	sensorReading[1] = second_byte & 0xFF;
	sensorReading[2] = (BUILD_TIME >> 24) & 0xFF;
	sensorReading[3] = (BUILD_TIME >> 16) & 0xFF;
	sensorReading[4] = (BUILD_TIME >> 8) & 0xFF;
	sensorReading[5] = BUILD_TIME & 0xFF;
	sensorReading[6] = (buildinfo_git >> 8) & 0xFF;
	sensorReading[7] = buildinfo_git & 0xFF;

	*readingLength = 8;
}

void WriteSensorFF(byte *sensorReading, int *readingLength)
{
	return;
}