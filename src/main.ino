#include <Arduino.h>
#include <Wire.h>
#include <OneWire.h>
#include "scanner.h"
#include "stringutils.h"
#include "hex.h"

const char *version = "4.0.0";

char inputbuf[1024];
int inputlen;

char hexbuf[1024];

OneWire ds(48);

void commandVersion(int argc, const char **argv) {
    SerialUSB.print("OK ");
    SerialUSB.println(version);
}

void commandID(int argc, const char **argv) {
    byte mac[8];

    ds.reset();
    ds.write(0x33);

    for (int i = 0; i < 8; i++) {
        mac[i] = ds.read();
    }

    if (OneWire::crc8(mac, 8) != 0) {
        SerialUSB.println("ERR failed crc");
        return;
    }

    EncodeHex(mac, hexbuf, 8);
    SerialUSB.print("OK ");
    SerialUSB.println(hexbuf);
}

void commandPinMode(int argc, const char **argv) {
    if (argc != 3) {
        SerialUSB.println("ERR invalid args");
        return;
    }

    int pin = atoi(argv[1]);
    int mode;

    if (matches(argv[2], "input")) {
        mode = INPUT;
    } else if (matches(argv[2], "output")) {
        mode = OUTPUT;
    } else {
        SerialUSB.println("ERR invalid mode");
        return;
    }

    pinMode(pin, mode);
    SerialUSB.println("OK");
}

void commandPinWrite(int argc, const char **argv) {
    if (argc != 3) {
        SerialUSB.println("ERR invalid args");
        return;
    }

    int pin = atoi(argv[1]);
    int value = atoi(argv[2]);
    digitalWrite(pin, value);
    SerialUSB.println("OK");
}

void commandI2CBegin(int argc, const char **argv) {
    if (argc != 2) {
        SerialUSB.println("ERR invalid args");
        return;
    }

    int addr = atoi(argv[1]);
    Wire.beginTransmission(addr);
    SerialUSB.println("OK");
}

void commandI2CEnd(int argc, const char **argv) {
    Wire.endTransmission();
    SerialUSB.println("OK");
}

void commandI2CReq(int argc, const char **argv) {
    if (argc != 3) {
        SerialUSB.println("ERR invalid args");
        return;
    }

    int addr = atoi(argv[1]);
    int count = atoi(argv[2]);

    Wire.requestFrom(addr, count);
    SerialUSB.println("OK");
}

void commandI2CRead(int argc, const char **argv) {
    byte data[64];

    if (argc != 2) {
        SerialUSB.println("ERR invalid args");
        return;
    }

    int count = atoi(argv[1]);

    unsigned long startTime = millis();

    for (int i = 0; i < count; i++) {
        while (Wire.available() == 0) {
            if (millis() - startTime > 5000) {
                SerialUSB.println("ERR bus timeout");
                return;
            }
        }

        data[i] = Wire.read();
    }

    EncodeHex(data, hexbuf, count);
    SerialUSB.print("OK ");
    SerialUSB.println(hexbuf);
}

void commandI2CWrite(int argc, const char **argv) {
    SerialUSB.println("ERR not implemented");
}

struct Command {
    const char *name;
    void (*func)(int argc, const char **argv);
};

Command commands[] = {
    {"VER", commandVersion},
    {"ID", commandID},
    {"PM", commandPinMode},
    {"PWR", commandPinWrite},
    {"2BEG", commandI2CBegin},
    {"2END", commandI2CEnd},
    {"2REQ", commandI2CReq},
    {"2RD", commandI2CRead},
    {"2WR", commandI2CWrite},
};

const int numcommands = sizeof(commands) / sizeof(Command);

void dispatchcommand(Scanner &scanner) {
    if (scanner.argc == 0) {
        return;
    }

    for (int i = 0; i < numcommands; i++) {
        if (matches(scanner.argv[0], commands[i].name)) {
            commands[i].func(scanner.argc, (const char **)scanner.argv);
            return;
        }
    }

    SerialUSB.println("ERR invalid command");
}

void processinput() {
    Scanner scanner(inputbuf, 1024);

    scanner.Split();

    if (scanner.Err() != NULL) {
        SerialUSB.print("ERR ");
        SerialUSB.println(scanner.Err());
        return;
    }

    dispatchcommand(scanner);
}

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    Wire.begin();
}

void loop() {
    inputbuf[0] = '\0';
    inputlen = 0;

    while (1) {
        if (inputlen >= 1024) {
            SerialUSB.println("ERR buffer overflow");
            break;
        }

        while (SerialUSB.available() == 0) {
        }

        char b = SerialUSB.read();

        if (isprint(b)) {
            inputbuf[inputlen++] = b;
            inputbuf[inputlen] = '\0';
        }

        if (b == '\r' || b == '\n') {
            processinput();
            break;
        }
    }
}
