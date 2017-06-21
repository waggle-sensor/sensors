#include "main.h"

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    Wire.begin();
    delay(10);
    
    // Chemsense
    Serial3.begin(CHEMSENSE_DATARATE);
    // To wait until chem sends data again
    // if chem does not send data for 2 secs
    Serial3.setTimeout(4000);
    pinMode(PIN_CHEMSENSE_POW, OUTPUT);
    // LOW means power on
    digitalWrite(PIN_CHEMSENSE_POW, LOW);
   
    Printf("debug: setup complete");
}

void commandID() {
    // If user wants only Mac of boards,
    // then just return two MAC addrs
    if (scanner.Scan() != '\n') {
        Printf("err: invalid args");
        return;
    }
    byte sensor_ID = 0x00;
    readMAC(sensor_ID);
}

void commandVersion() {
    if (scanner.Scan() != '\n') {
        Printf("err: invalid args");
        return;
    }

    Printf("ok: Ver 4.0.1");
}

void command2Write() {
    int count = 0;

    while (scanner.Scan() != '\n') {
        Printf("debug: write %s", scanner.TokenText());
        count++;
    }

    Printf("ok: %d", count);
}

void command2Read() {
    // if (strcmp(scanner.TokenText(), "2read") == 0) {
    //     if (scanner.Scan() == '\n') {
    //         std::cout << "debug: reading " << scanner.TokenText() << " bytes" << std::endl;
    //     }
    //
    //     std::cout << "ok:";
    //
    //     for (int i = 0; i < atoi(scanner.TokenText()); i++) {
    //         std::cout << " aa";
    //     }
    //
    //     std::cout << std::endl;
    //
    //     goto ok;
    // }
    Printf("err: not implemented");
}

void command2Request() {
    // Let's grap some data
    while (scanner.Scan() != '\n') {
    	// check input command
    	// according to the input command,
    	// we will grap data from Met/Light/or Chem board
        byte sensor_ID = sensor.sensorID(scanner.TokenText());
        
        // Call functions according to the sensor_ID
        if (sensor_ID < 0x10)
            readMet(sensor_ID);
        else if (sensor_ID < 0x20)
            readLight(sensor_ID);
        else if (sensor_ID < 0x40)
            readChem(sensor_ID);
        else
        {
            Printf("debug: request <%s> %s", scanner.TokenText(),  "no match");
            // return;
        }
    }

    Printf("ok: %s", "end request");
}

void readMAC(byte sensor_ID)
{
    // Print Met Mac addr,
    // Met Mac is const value, write down the number in "main.h"
    Printf("data %x %ld", 0x00, MetLightMAC);
    readChem(sensor_ID);


	// Printf("Met mac %ld No unit", MetLightMAC);
	// chem.ChemGet(dataReading);
 //    // Because this FW try to do nothing,
 //    // it just graps a line of data from chem and sends
	// SerialUSB.print("Chem ");
	// SerialUSB.println(dataReading);
 //    // Printf function have buffer limit as 80, 
 //    // which cannot carries all chem data in one printf buff!!
	// // Printf("Chem %s", dataReading);
}

void printData(byte ID, int* NumVal, char* dataReading)
{
    // Print data, for all data from three boards 
    // Met, light, and chem
	SerialUSB.print("data ");
	SerialUSB.print(ID);
	SerialUSB.print(' ');
	for (int i = 0; i < *NumVal; i++)
	{
		SerialUSB.print(dataReading[i], HEX);
		SerialUSB.print(' ');
	}
	SerialUSB.println("");
}

void readMet(byte sensor_ID)
{
    // Call exact function for each of sensors, and fill/grap/bring data
	// Printf("debug: request <%s>, id: %x, group: %s", scanner.TokenText(), sensor_ID, "Met");

    // If user wants only Mac addrs
    // the command for this is "2request mac"
	if (sensor_ID == 0x00)
		readMAC(sensor_ID);

    // If user wants all the sensor data
    // the command for this is "2request met"
	else if (sensor_ID == 0x0F)
	{
		for (sensor_ID = 0x01; sensor_ID < MetSenNum; sensor_ID++)
		{
			cmet.MetGet(sensor_ID, &NumVal, dataReading);
			printData(sensor_ID, &NumVal, dataReading);
		}
	}

    // If user wants data from one sensor
    // the command for this is "2request <sensor name>"
	else
	{
		cmet.MetGet(sensor_ID, &NumVal, dataReading);
		printData(sensor_ID, &NumVal, dataReading);
	}
}

void readLight(byte sensor_ID)
{
    // Call exact function for each of sensors, and fill/grap/bring data
    // Printf("debug: request <%s>, id: %x, group: %s", scanner.TokenText(), sensor_ID, "Light");

    // If user wants all the sensor data
    // the command for this is "2request light"
    if (sensor_ID == 0x1F)
    {
        for (sensor_ID = 0x10; sensor_ID < (0x10 + LightSenNum); sensor_ID++)
        {
            clight.LightGet(sensor_ID, &NumVal, dataReading);
            printData(sensor_ID, &NumVal, dataReading);
        }
    }

    // If user wants data from one sensor
    // the command for this is "2request <sensor name>"
    else
    {
        clight.LightGet(sensor_ID, &NumVal, dataReading);
        printData(sensor_ID, &NumVal, dataReading);
    }
}

void readChem(byte sensor_ID)
{
    // Call exact function for each of sensors, and fill/grap/bring data
    chem.ChemGet(&NumVal, dataReading);
    printData(sensor_ID, &NumVal, dataReading);
}

bool execCommand() {
    // consume leading newline tokens
    while (scanner.Scan() == '\n') {
        // if (scanner.Err()) {
        //     scanner.Reset();
        // }
    }

    Printf("debug: command <%s>", scanner.TokenText());

    if (matches(scanner.TokenText(), "ver")) {
        commandID();
        return true;
    }

    if (matches(scanner.TokenText(), "id")) {
        commandVersion();
        return true;
    }

    if (matches(scanner.TokenText(), "2write")) {
        command2Write();
        return true;
    }

    if (matches(scanner.TokenText(), "2read")) {
        command2Read();
        return true;
    }

    // Let's get data,
    if (matches(scanner.TokenText(), "2request")) {
        command2Request();
        return true;
    }

    // consume trailing tokens
    while (scanner.Scan() != '\n') {
    }

    return false;
}

void loop() {
    bool ok = execCommand();

    if (!ok) {
        Printf("err: invalid command");
    }
}
