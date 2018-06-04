// Soil moisture sensor

#define TRIDENT_POWER  38 // one of any ditial pins
#define DECAGON_DATARATE  1200

float dielectric = 0.0;
float conductivity = 0.0;
float temperature = 0.0;

void InitSensor2D()
{
	Serial1.begin(DECAGON_DATARATE);	// begin serial3
	Serial1.setTimeout(5000);	// set timeout of serial1 as 5 sec
	pinMode(TRIDENT_POWER, OUTPUT);    // pin for providing power to soil moisture sensor, Decagon sensor
	delay(100);

	digitalWrite(TRIDENT_POWER, true); 	// power on the device --> LOW means power on
	delay(100);

	for (int i = 0; i < 5; i++)
	{
		if (Serial1.available() > 0)
			return;
	}

	Serial1.end();
	digitalWrite(TRIDENT_POWER, false);
	DisableSensor2D();
}

void ConfigSensor2D()
{
	return;
}

void EnableSensor2D()
{
	EnableSensor(0x2D);
}	

void DisableSensor2D()
{
	DisableSensor(0x2D);
}

void ReadSensor2D(byte *sensorReading, int *readingLength)
{
	char data_string[25];

	int checksum = 0;
	char crc_from = 0;
	bool checkZ = true;
	bool crc_byte = false;
	int input_num = 0;
	int param = 0;
	int last = 0;

	count = 0;

	digitalWrite(TRIDENT_POWER, true);
	delay(100);

	while (count == 0) // Theoratically, work below will be done in 16ms
	{
		if (Serial1.available() > 0)
		{
			int data_int = Serial1.read();
			char data_char = char(data_int);

			data_string[input_num] = data_char;
			input_num++;

			if (data_int == 32)
			{
				parameters(input_num, param, last, data_string, sensorReading);
				param++;
				last = input_num;
			}

			if (crc_byte == true)
			{
				crc_from = data_char;
				crc_byte = false;
			}

			if (data_int == 122)
			{
				parameters(input_num, param, last, 	data_string, sensorReading);
				param++;
				last = input_num;

				checksum += data_int;
				checkZ = false;
				crc_byte = true;
			}

			if (checkZ == true)
				checksum += data_int;
		}
	}

	*readingLength = 6;

	char crc_char = calc_crc(checksum);

	if (crc_char != crc_from)
		ReadSensor2D(sensorReading, readingLength);
		
	digitalWrite(TRIDENT_POWER, false);
}

void WriteSensor2D(byte *packet)
{
	return;
}

char calc_crc(int checksum)
{
	int crc_int = checksum % 64 + 32;
	char crc_char = char(crc_int);

	return crc_char;
}

void parameters(int input_num, int param, int last, char *data_string, byte *sensorReading)
{
	int Temp_uint16 = 0;

	for (int i = last; i < (input_num - 1); i++)
	{
		if (data_string[i] < '0' || data_string[i] > '9')
			continue;

		data_string[i] = data_string[i] - '0';
		Temp_uint16 = (Temp_uint16 * 10) + data_string[i];
	}

	if (param == 0)
	{
		sensorReading[0] = (Temp_uint16 >> 8);
		sensorReading[1] = (Temp_uint16 & 0xFF);

		// dielectric = float(Temp_uint16) / 50.000000;

		// SerialUSB.print("dielectric");
		// SerialUSB.print("\t");
		// SerialUSB.println(dielectric);
	}
	else if (param == 1)
	{
		sensorReading[2] = (Temp_uint16 >> 8);
		sensorReading[3] = (Temp_uint16 & 0xFF);


		// if (Temp_uint16 < 700)
		// 	conductivity = float(Temp_uint16) / 100.0;
		// else
		// 	conductivity = (float(Temp_uint16) - 700.0) * 5.0 + 700.0;

		// SerialUSB.print("conductivity");
		// SerialUSB.print("\t");
		// SerialUSB.println(conductivity);
	}
	else if (param == 2)
	{
		sensorReading[4] = (Temp_uint16 >> 8);
		sensorReading[5] = (Temp_uint16 & 0xFF);

		// if (Temp_uint16 < 900)
		// 	temperature = (float(Temp_uint16) - 400.0) / 10.0;
		// else
		// 	temperature = (float(Temp_uint16) - 900.0) * 5.0 + 900.0;

		// SerialUSB.print("temperature");
		// SerialUSB.print("\t");
		// SerialUSB.println(temperature);
	}

}


