#include "main.h"

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    Wire.begin();
    delay(10);
    
    // Chemsense
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.
    pinMode(PIN_CHEMSENSE_POW, OUTPUT);
    digitalWrite(PIN_CHEMSENSE_POW, LOW);
   
    Printf("debug: setup complete");
}

void commandID() {
    if (scanner.Scan() != '\n') {
        Printf("err: invalid args");
        return;
    }

    readMAC();

    Printf("ok: 0.0.1");

    //     byte mac[8];
    //
    //     ds.reset();
    //     ds.write(0x33);
    //
    //     for (int i = 0; i < 8; i++) {
    //         mac[i] = ds.read();
    //     }
    //
    //     if (OneWire::crc8(mac, 8) != 0) {
    //         SerialUSB.println("ERR failed crc");
    //         return;
    //     }
    //
    //     EncodeHex(mac, hexbuf, 8);
    //     SerialUSB.print("OK ");
    //     SerialUSB.println(hexbuf);
}

void commandVersion() {
    if (scanner.Scan() != '\n') {
        Printf("err: invalid args");
        return;
    }

    Printf("ok: abc123");
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
    while (scanner.Scan() != '\n') {
        byte sensor_ID = sensor.sensorID(scanner.TokenText());
        // Printf("debug: request %s, id: %x", scanner.TokenText(), sensor_ID);

        if (sensor_ID < 0x10)
            readMet(sensor_ID);
        else if (sensor_ID < 0x20)
            readLight(sensor_ID);
        else if (sensor_ID < 0x40)
            readChem(sensor_ID);
        else if (sensor_ID < 0xB0)
            readCat(sensor_ID);
        else
        {
            Printf("debug: request <%s> %s", scanner.TokenText(),  "no match");
            // return;
        }
    }

    Printf("ok: %s", "end request");
}

void readMAC()
{
    Printf("Met mac %ld No unit", MetLightMAC);
    chem.ChemGet(chem_reading);
    SerialUSB.print("Chem ");
    SerialUSB.println(chem_reading);
    Printf("Chem %s", chem_reading);
}

void readMet(byte sensor_ID)
{
    Printf("debug: request <%s>, id: %x, group: %s", scanner.TokenText(), sensor_ID, "Met");
    
    if (sensor_ID == 0x00)
        readMAC();
    else if (sensor_ID == 0x0F)
    {
        readMAC();

        for (sensor_ID = 0x01; sensor_ID < MetSenNum; sensor_ID++)
        {
            cmet.MetGet(sensor_ID, &NumVal, float_data, unit);
            sensor.sensorName(sensor_ID, &sensorNM);

            for (int i = 0; i < NumVal; i++)
                Printf("Met %s %.2f %s", sensorNM, float_data[i], unit[i]);
        }
    }
    else
    {
        cmet.MetGet(sensor_ID, &NumVal, float_data, unit);
        for (int i = 0; i < NumVal; i++)
            Printf("Met %s %.2f %s", scanner.TokenText(), float_data[i], unit[i]);
    }
}

void readLight(byte sensor_ID)
{
    Printf("debug: request <%s>, id: %x, group: %s", scanner.TokenText(), sensor_ID, "Light");

    if (sensor_ID == 0x1F)
    {
        for (sensor_ID = 0x10; sensor_ID < (0x10 + LightSenNum); sensor_ID++)
        {
            clight.LightGet(sensor_ID, &NumVal, float_data, unit);
            sensor.sensorName(sensor_ID, &sensorNM);

            for (int i = 0; i < NumVal; i++)
                Printf("Light %s %.2f %s", sensorNM, float_data[i], unit[i]);
        }
    }
    else
    {
        clight.LightGet(sensor_ID, &NumVal, float_data, unit);
        for (int i = 0; i < NumVal; i++)
            Printf("Light %s %.2f %s", scanner.TokenText(), float_data[i], unit[i]);
    }
}

void readChem(byte sensor_ID)
{
    chem.ChemGet(chem_reading);
    Printf("Chem %s", chem_reading);
}

void readCat(byte sensor_ID)
{
    Printf("debug: request <%s>, id: %x", scanner.TokenText(), sensor_ID);

    if (sensor_ID == 0xA0) //temp
    {
        for (int i = 0; i < TempSense; i++)
        {
            if (tArray[i] < 0x10)
                readMet(tArray[i]);
            else if (tArray[i] < 0x20)
                readLight(tArray[i]);
        }
    }
    else if (sensor_ID == 0xA1)
    {
        for (int i = 0; i < HumidSense; i++)
        {
            if (hArray[i] < 0x10)
                readMet(hArray[i]);
            else if (hArray[i] < 0x20)
                readLight(hArray[i]);
        }
    }


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
