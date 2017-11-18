// HMC Magnetometer

void InitSensor0A()
{
	const byte HMC5883_REGISTER_MAG_CRB_REG_M = 0x01;
	const byte HMC5883_REGISTER_MAG_MR_REG_M = 0x02;
	const byte HMC5883_MAGGAIN_1_3 = 0x20;

	// Enable the magnetometer
	byte writearray[2] = {HMC5883_REGISTER_MAG_MR_REG_M, 0x00};
	WriteI2C(HMC5883_ADDESS, 2, writearray);

	//** Set the gain to a known level
	writearray[0] = HMC5883_REGISTER_MAG_CRB_REG_M;
	writearray[1] = HMC5883_MAGGAIN_1_3;
	WriteI2C(HMC5883_ADDESS, 2, writearray);
	// _magGain = gain;

	// //** TODO: Where to store, how to send, sensor ID?????
	// int coefficient_Gauss_LSB_XY = 1100;
	// int coefficient_Gauss_LSB_Z  = 980;

	// HMC5883_COEFFICIENTS[0] = (coefficient_Gauss_LSB_XY >> 8) & 0xFF;
	// HMC5883_COEFFICIENTS[1] = coefficient_Gauss_LSB_XY & 0xFF;
	// HMC5883_COEFFICIENTS[2] = (coefficient_Gauss_LSB_Z >> 8) & 0xFF;
	// HMC5883_COEFFICIENTS[3] = coefficient_Gauss_LSB_Z & 0xFF;
}

void ConfigSensor0A()
{
	return;
}

void EnableSensor0A()
{
	EnableSensor(0x0A);
}

void DisableSensor0A()
{
	DisableSensor(0x0A);
}

void ReadSensor0A(byte *sensorReading, int *readingLength)
{
	const byte HMC5883_REGISTER_MAG_OUT_X_H_M = 0x03;

	byte writebyte[1] = {HMC5883_REGISTER_MAG_OUT_X_H_M};
	byte readarray[6];
	WriteReadI2C(HMC5883_ADDESS, 1, writebyte, 6, readarray);

	for (int i = 0; i < 6; i++)
	{
		sensorReading[i] = readarray[i];
		*readingLength += 1;
	}

	// int a = (sensorReading[0] << 8) | sensorReading[1];
	// int b = (sensorReading[2] << 8) | sensorReading[3];
	// int c = (sensorReading[4] << 8) | sensorReading[5];


	// SerialUSB.print("HMCx ");
	// SerialUSB.println(a);
	// SerialUSB.print("HMCy ");
	// SerialUSB.println(b);
	// SerialUSB.print("HMCz ");
	// SerialUSB.println(c);

	// int startCoeff = *readingLength;
	// int a = sizeof(HMC5883_COEFFICIENTS);
	// for (int i = 0; i < a; i++)
	// {
	// 	sensorReading[startCoeff + i] = HMC5883_COEFFICIENTS[i];
	// 	*readingLength += 1;
	// }
}

void WriteSensor0A(byte *sensorReading, int *readingLength)
{
	return;
}