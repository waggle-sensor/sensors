#include <Arduino.h>
// #include <Wire.h>
// #include <OneWire.h>
#include "scanner.h"
#include "stringutils.h"

// OneWire ds(48);

Scanner scanner;

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    SerialUSB.println("debug: setup");

    scanner.Init(SerialUSB);
    // Wire.begin();
}

void commandID() {
    if (scanner.Scan() != '\n') {
        SerialUSB.println("err: invalid args");
        return;
    }

    SerialUSB.println("ok: 0.0.1");

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
        SerialUSB.println("err: invalid args");
        return;
    }

    SerialUSB.println("ok: abc123");
}

void command2Write() {
    int count = 0;

    while (scanner.Scan() != '\n') {
        SerialUSB.print("debug: write ");
        SerialUSB.println(scanner.TokenText());
        count++;
    }

    SerialUSB.print("ok: ");
    SerialUSB.println(count);
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
    SerialUSB.println("err: not implemented");
}

bool execCommand() {
    // consume leading newline tokens
    while (scanner.Scan() == '\n') {
        // if (scanner.Err()) {
        //     scanner.Reset();
        // }
    }

    SerialUSB.print("debug: command ");
    SerialUSB.println(scanner.TokenText());

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

    // consume trailing tokens
    while (scanner.Scan() != '\n') {
    }

    return false;
}

void loop() {
    if (!execCommand()) {
        SerialUSB.print("err: invalid command ");
        SerialUSB.println(scanner.TokenText());
    }
}
