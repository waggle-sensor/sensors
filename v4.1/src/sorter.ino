
struct FunctionType
{
	const byte funcid;
	void (*func)(byte*, int);
};


const FunctionType functype[] = {
	{0x01, configure_sensor},
	{0x02, init_sensor},
	{0x03, enable_sensor},
	{0x04, write_sensor},
	{0x05, read_sensor},
	{0x06, disable_sensor},

	{0x11, configure_bus},
	{0x12, init_bus},
	{0x13, enable_bus},
	{0x14, write_bus},
	{0x15, read_bus},
	{0x16, disable_bus},
};

const read_sensor read_sensor_value[] = {
	{01, read_sensor_01},
    {02, read_sensor_02},
    {03, read_sensor_03},
    {04, read_sensor_04},
    {05, read_sensor_05},
    {06, read_sensor_06},
    {07, read_sensor_07},
    {08, read_sensor_08},
    {09, read_sensor_09},
    {0A, read_sensor_0A},
    {0B, read_sensor_0B},
    {0C, read_sensor_0C},
    {0D, read_sensor_0D},
    {0E, read_sensor_0E},
    {0F, read_sensor_0F},
    {10, read_sensor_10},
    {11, read_sensor_11},
    {12, read_sensor_12},
    {13, read_sensor_13},
    {14, read_sensor_14},
    {15, read_sensor_15},
    {16, read_sensor_16},
    {17, read_sensor_17},
    {18, read_sensor_18},
    {19, read_sensor_19},
    {1A, read_sensor_1A},
    {1B, read_sensor_1B},
    {1C, read_sensor_1C},
    {1D, read_sensor_1D},
    {1E, read_sensor_1E},
    {1F, read_sensor_1F},
    {20, read_sensor_20},
    {21, read_sensor_21},
    {22, read_sensor_22},
    {23, read_sensor_23},
    {24, read_sensor_24},
    {25, read_sensor_25},
    {26, read_sensor_26},
    {27, read_sensor_27},
    {28, read_sensor_28},
    {29, read_sensor_29},
    {2A, read_sensor_2A},
    {2B, read_sensor_2B},
    {2C, read_sensor_2C},
    {2D, read_sensor_2D},
    {2E, read_sensor_2E},
    {2F, read_sensor_2F},
    {30, read_sensor_30},
    {31, read_sensor_31},
    {32, read_sensor_32},
    {33, read_sensor_33},
    {34, read_sensor_34},
    {35, read_sensor_35},
    {36, read_sensor_36},
    {37, read_sensor_37},
    {38, read_sensor_38},
    {39, read_sensor_39},
    {3A, read_sensor_3A},
    {3B, read_sensor_3B},
    {3C, read_sensor_3C},
    {3D, read_sensor_3D},
    {3E, read_sensor_3E},
    {3F, read_sensor_3F},
    {40, read_sensor_40},
    {41, read_sensor_41},
    {42, read_sensor_42},
    {43, read_sensor_43},
    {44, read_sensor_44},
    {45, read_sensor_45},
    {46, read_sensor_46},
    {47, read_sensor_47},
    {48, read_sensor_48},
    {49, read_sensor_49},
    {4A, read_sensor_4A},
    {4B, read_sensor_4B},
    {4C, read_sensor_4C},
    {4D, read_sensor_4D},
    {4E, read_sensor_4E},
    {4F, read_sensor_4F},
    {50, read_sensor_50},
    {51, read_sensor_51},
    {52, read_sensor_52},
    {53, read_sensor_53},
    {54, read_sensor_54},
    {55, read_sensor_55},
    {56, read_sensor_56},
    {57, read_sensor_57},
    {58, read_sensor_58},
    {59, read_sensor_59},
    {5A, read_sensor_5A},
    {5B, read_sensor_5B},
    {5C, read_sensor_5C},
    {5D, read_sensor_5D},
    {5E, read_sensor_5E},
    {5F, read_sensor_5F},
    {60, read_sensor_60},
    {61, read_sensor_61},
    {62, read_sensor_62},
    {63, read_sensor_63},
    {64, read_sensor_64},
    {65, read_sensor_65},
    {66, read_sensor_66},
    {67, read_sensor_67},
    {68, read_sensor_68},
    {69, read_sensor_69},
    {6A, read_sensor_6A},
    {6B, read_sensor_6B},
    {6C, read_sensor_6C},
    {6D, read_sensor_6D},
    {6E, read_sensor_6E},
    {6F, read_sensor_6F},
    {70, read_sensor_70},
    {71, read_sensor_71},
    {72, read_sensor_72},
    {73, read_sensor_73},
    {74, read_sensor_74},
    {75, read_sensor_75},
    {76, read_sensor_76},
    {77, read_sensor_77},
    {78, read_sensor_78},
    {79, read_sensor_79},
    {7A, read_sensor_7A},
    {7B, read_sensor_7B},
    {7C, read_sensor_7C},
    {7D, read_sensor_7D},
    {7E, read_sensor_7E},
    {7F, read_sensor_7F},
    {80, read_sensor_80},
    {81, read_sensor_81},
    {82, read_sensor_82},
    {83, read_sensor_83},
    {84, read_sensor_84},
    {85, read_sensor_85},
    {86, read_sensor_86},
    {87, read_sensor_87},
    {88, read_sensor_88},
    {89, read_sensor_89},
    {8A, read_sensor_8A},
    {8B, read_sensor_8B},
    {8C, read_sensor_8C},
    {8D, read_sensor_8D},
    {8E, read_sensor_8E},
    {8F, read_sensor_8F},
    {90, read_sensor_90},
    {91, read_sensor_91},
    {92, read_sensor_92},
    {93, read_sensor_93},
    {94, read_sensor_94},
    {95, read_sensor_95},
    {96, read_sensor_96},
    {97, read_sensor_97},
    {98, read_sensor_98},
    {99, read_sensor_99},
    {9A, read_sensor_9A},
    {9B, read_sensor_9B},
    {9C, read_sensor_9C},
    {9D, read_sensor_9D},
    {9E, read_sensor_9E},
    {9F, read_sensor_9F},
    {A0, read_sensor_A0},
    {A1, read_sensor_A1},
    {A2, read_sensor_A2},
    {A3, read_sensor_A3},
    {A4, read_sensor_A4},
    {A5, read_sensor_A5},
    {A6, read_sensor_A6},
    {A7, read_sensor_A7},
    {A8, read_sensor_A8},
    {A9, read_sensor_A9},
    {AA, read_sensor_AA},
    {AB, read_sensor_AB},
    {AC, read_sensor_AC},
    {AD, read_sensor_AD},
    {AE, read_sensor_AE},
    {AF, read_sensor_AF},
    {B0, read_sensor_B0},
    {B1, read_sensor_B1},
    {B2, read_sensor_B2},
    {B3, read_sensor_B3},
    {B4, read_sensor_B4},
    {B5, read_sensor_B5},
    {B6, read_sensor_B6},
    {B7, read_sensor_B7},
    {B8, read_sensor_B8},
    {B9, read_sensor_B9},
    {BA, read_sensor_BA},
    {BB, read_sensor_BB},
    {BC, read_sensor_BC},
    {BD, read_sensor_BD},
    {BE, read_sensor_BE},
    {BF, read_sensor_BF},
    {C0, read_sensor_C0},
    {C1, read_sensor_C1},
    {C2, read_sensor_C2},
    {C3, read_sensor_C3},
    {C4, read_sensor_C4},
    {C5, read_sensor_C5},
    {C6, read_sensor_C6},
    {C7, read_sensor_C7},
    {C8, read_sensor_C8},
    {C9, read_sensor_C9},
    {CA, read_sensor_CA},
    {CB, read_sensor_CB},
    {CC, read_sensor_CC},
    {CD, read_sensor_CD},
    {CE, read_sensor_CE},
    {CF, read_sensor_CF},
    {D0, read_sensor_D0},
    {D1, read_sensor_D1},
    {D2, read_sensor_D2},
    {D3, read_sensor_D3},
    {D4, read_sensor_D4},
    {D5, read_sensor_D5},
    {D6, read_sensor_D6},
    {D7, read_sensor_D7},
    {D8, read_sensor_D8},
    {D9, read_sensor_D9},
    {DA, read_sensor_DA},
    {DB, read_sensor_DB},
    {DC, read_sensor_DC},
    {DD, read_sensor_DD},
    {DE, read_sensor_DE},
    {DF, read_sensor_DF},
    {E0, read_sensor_E0},
    {E1, read_sensor_E1},
    {E2, read_sensor_E2},
    {E3, read_sensor_E3},
    {E4, read_sensor_E4},
    {E5, read_sensor_E5},
    {E6, read_sensor_E6},
    {E7, read_sensor_E7},
    {E8, read_sensor_E8},
    {E9, read_sensor_E9},
    {EA, read_sensor_EA},
    {EB, read_sensor_EB},
    {EC, read_sensor_EC},
    {ED, read_sensor_ED},
    {EE, read_sensor_EE},
    {EF, read_sensor_EF},
    {F0, read_sensor_F0},
    {F1, read_sensor_F1},
    {F2, read_sensor_F2},
    {F3, read_sensor_F3},
    {F4, read_sensor_F4},
    {F5, read_sensor_F5},
    {F6, read_sensor_F6},
    {F7, read_sensor_F7},
    {F8, read_sensor_F8},
    {F9, read_sensor_F9},
    {FA, read_sensor_FA},
    {FB, read_sensor_FB},
    {FC, read_sensor_FC},
    {FD, read_sensor_FD},
    {FE, read_sensor_FE},
    {FF, read_sensor_FF},
};



/*
const FunctionType functype[] = {
	// {0x00, MultiFunctions},
	{0x01, CallInitCore},
	{0x02, CallReadCore},
	{0x03, CallEnableCore},
	{0x04, CallDisableCore},
};*/

const int numtype = sizeof(functype)/sizeof(functype[0]);

void SortReading(byte *dataReading, int packetLength)
{	
	int request = dataReading[1] & 0xF0;
	int protocol = dataReading[1] & 0x0F;
	int datalength = dataReading[3];

	bool checkcrc = CheckCRC(dataReading[datalength + 4]);

	byte typebyte = 0;
	byte paramlength = 0;

	bool exceptionCheck = false;
	int totalSubpacket = 0;

	// for (int i = 0; i < packetLength; i++)
	//     SerialUSB.write(dataReading[i]);

	if (checkcrc && (request == 0) && (protocol == 2) && (datalength + 6 == packetLength))
	{
		PacketInit(); 
		byte *subpacket = dataReading + 4;
		// while (datalength != 0)
		while (subpacket < &dataReading[datalength + 4])
		{
			typebyte = (subpacket[0] >> 4) & 0x0F;
			paramlength = subpacket[0] & 0x0F;

			for (int i = 0; i < numtype; i++)
			{
				const FunctionType *ft = functype + i;
				if (ft->funcid == typebyte)
				{
					if (subpacket[1] == 0x16)
					{
						totalSubpacket--;
						exceptionCheck = true;
						ReadChemconfig();
						break;
					}
					else if (subpacket[1] == 0x31)
					{
						totalSubpacket--;
						exceptionCheck = true;
						ReadAlphaConfig();
						break;
					}

					exceptionCheck = false;
					ft->func(subpacket + 1, paramlength);
					break;
				}
			}
			subpacket += paramlength + 1;
			totalSubpacket++;
		}
		if (!exceptionCheck || totalSubpacket > 0)
			PacketSender(0x01);  // last packet of this request
	}
}




void configure_sensor (byte *data, int length)
{
  #ifdef SerialDebug 
  SerialUSB.print("configure_sensor - ");
  SerialUSB.println(length);
  #endif
  return;
}

void init_sensor (byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("init_sensor - ");
  SerialUSB.println(length);
  #endif
 

  return;
}

void enable_sensor (byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("enable_sensor - ");
  SerialUSB.println(length);
  #endif
 
  return;
}


void write_sensor(byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("write_sensor - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void read_sensor(byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("read_sensor - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void disable_sensor(byte *data, int length)
{


  #ifdef SerialDebug 
  SerialUSB.print("disable_sensor - ");
  SerialUSB.println(length);
  #endif
  
  return;
}


void configure_bus(byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("configure_sensor - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void init_bus(byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("init_sensor - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void enable_bus(byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("enable_bus - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void write_bus(byte *data, int length)
{

  #ifdef SerialDebug 
  SerialUSB.print("write_bus - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void read_bus(byte *data, int length)
{


  #ifdef SerialDebug 
  SerialUSB.print("read_bus - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void disable_bus(byte *data, int length)
{


  #ifdef SerialDebug 
  SerialUSB.print("disable_bus - ");
  SerialUSB.println(length);
  #endif
  
  return;
}

void CallInitCore(byte *data, int length)
{
	if (data[0] == 0x2B)
		InitAlphasensor();
	else
		Packetization(data[0], 0xFF);
}

struct ReadCoresense
{
	const byte sensorid;
	void (*func)(byte*, int*);
};

const ReadCoresense readcore[] = {
	// FW version
	{0xFF, ReadVersion},  // Firmware version
	// Metsense
	{0x00, ReadMacAdd}, // Mac address of Met/Lightsense board
	{0x01, ReadTMP112}, // temperature
	{0x02, ReadHTU21D}, // temperature, humidity
	{0x03, ReadHIH4030}, // humidity
	{0x04, ReadBMP180}, // temperature, pressure
	{0x05, ReadPR103J2}, // temperature
	{0x06, ReadTSL250ms}, // light
	{0x07, ReadMMA}, // acceleration force
	{0x08, ReadSPV}, // sound level
	{0x09, ReadTSYS01}, // temperature
	// Lightsense
	{0x0A, ReadHMC}, // magnetic field
	{0x0B, ReadHIH6130}, // temperature, humidity
	{0x0C, ReadAPDS}, // light
	{0x0D, ReadTSL260RD}, // light
	{0x0E, ReadTSL250RDls}, // light
	{0x0F, ReadMLX}, // light
	{0x10, ReadML8511}, // UV index
	{0x13, ReadTMP421}, // temperature
	// Chem
	// {0x16, ReadChemconfig},  // NOT CORESENSE PACKET!!! INDEPENDENT DIFFERENT PACKET!!! DIFFERENT FORM!!!
	{0x2A, ReadChem}, // chemical sensors, temperature, humidity, pressure
	// Alpha
	{0x28, ReadAlphaHisto}, // particle histogram
	{0x29, ReadAlphaSerial}, // serial number of alpha sensor
	{0x30, ReadAlphaFWver}, // FW version of alpha sesnor
	// {0x31, ReadAlphaConfig}, // configuration of alpha sensor, NOT CORESENSE PACKET!!! INDEPENDENT DIFFERENT PACKET!!! DIFFERENT FORM!!!
	// // Rain gauge OnSet
	// {0x37, ReadOnSet}, // rain gauge
	// // Soil moisture Decagon
	// {0x38, ReadDecagon}, // soil temperature, soil electric conductivity, soil volumetric water content
};

int numCoreRead = sizeof(readcore)/sizeof(readcore[0]);

void CallReadCore(byte *data, int length)
{
	byte thisid = data[0];
	byte sensorReading[1024];
	int readingLength = 0;

	int repeat = 0;
	int interval = 0;
	if (length == 2)
		repeat = data[1];
	else if (length == 3)
	{
		repeat = data[1];
		interval = data[2];
	}

	bool enable;
	if (thisid == 0x28 || thisid == 0x29 || thisid == 0x30 || thisid == 0x31)
		enable = GetEnable(0x2B);
	else if (thisid == 0x16 || thisid == 0x2A)
		enable = GetEnable(0x2A);
	else
		enable = GetEnable(thisid);

	// SerialUSB.print("GetEnable ");
	// SerialUSB.println(enable);

	if (!enable)
	{
		Packetization(thisid, 0xFF);
		return;
	}

	for (int i = 0; i < numCoreRead; i++)
	{
		const ReadCoresense *rc = readcore + i;
		if (rc->sensorid == thisid)
		{
			if (thisid == 0x2A)
				repeat = 3;
			// 	for (int i = 0; i < 3; i++)
			// 	{
			// 		rc->func(sensorReading, &readingLength);
			// 		Packetization(thisid, sensorReading, readingLength);
			// 	}
			// 	break;

			// }
			
			if (length > 1 || thisid == 0x2A)
			{
				for (int i = 0; i < repeat; i++)
				{
					rc->func(sensorReading, &readingLength);
					Packetization(thisid, sensorReading, readingLength);
					delay(interval);
				}
			}

			rc->func(sensorReading, &readingLength);
			Packetization(thisid, sensorReading, readingLength);
					
			break;
		}
	}
}
