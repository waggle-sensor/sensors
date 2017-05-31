#include <Arduino.h>
#include <Wire.h>
#include <OneWire.h>
#include "scanner.h"
#include "stringutils.h"

const char *version = "coresense 4.0.0";

char inputbuf[256];
int inputlen;

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    Wire.begin();
}

OneWire ds(48);

const char *commandVersion(int argc, const char **argv) {
    SerialUSB.println(version);
    return NULL;
}

const char *commandID(int argc, const char **argv) {
    byte mac[8];

    ds.reset();
    ds.write(0x33);

    for (int i = 0; i < 8; i++) {
        mac[i] = ds.read();
    }

    if (OneWire::crc8(mac, 8) != 0) {
        return "failed crc";
    }

    for (int i = 0; i < 8; i++) {
        SerialUSB.print((mac[i] >> 4) & 0x0F, HEX);
        SerialUSB.print((mac[i] >> 0) & 0x0F, HEX);
    }

    SerialUSB.println();
    return NULL;
}

const char *commandPinMode(int argc, const char **argv) {
    if (argc != 3) {
        return "invalid args";
    }

    int pin = atoi(argv[1]);
    int mode;

    if (matches(argv[2], "input")) {
        mode = INPUT;
    } else if (matches(argv[2], "output")) {
        mode = OUTPUT;
    } else {
        return "invalid pin mode";
    }

    pinMode(pin, mode);
    return NULL;
}

const char *commandPinWrite(int argc, const char **argv) {
    if (argc != 3) {
        return "invalid args";
    }

    int pin = atoi(argv[1]);
    int value = atoi(argv[2]);
    digitalWrite(pin, value);
    return NULL;
}

const char *commandI2CBegin(int argc, const char **argv) {
    if (argc != 2) {
        return "invalid args";
    }

    int addr = atoi(argv[1]);
    Wire.beginTransmission(addr);
    return NULL;
}

const char *commandI2CEnd(int argc, const char **argv) {
    Wire.endTransmission();
    return NULL;
}

const char *commandI2CReq(int argc, const char **argv) {
    return "not implemented";
}

const char *commandI2CRead(int argc, const char **argv) {
    return "not implemented";
}

struct Command {
    const char *name;
    const char *(*func)(int argc, const char **argv);
};

Command commands[] = {
    {"ver", commandVersion},
    {"id", commandID},
    {"pin-mode", commandPinMode},
    {"pin-write", commandPinWrite},
    {"i2c-begin", commandI2CBegin},
    {"i2c-end", commandI2CEnd},
    {"i2c-req", commandI2CReq},
    {"i2c-read", commandI2CRead},
};

const int numcommands = sizeof(commands) / sizeof(Command);

const char *dispatchcommand(Scanner &scanner) {
    if (scanner.argc == 0) {
        return NULL;
    }

    for (int i = 0; i < numcommands; i++) {
        if (matches(scanner.argv[0], commands[i].name)) {
            return commands[i].func(scanner.argc, (const char **)scanner.argv);
        }
    }

    return "invalid command";
}

void processinput() {
    const char *err;

    Scanner scanner(inputbuf, 256);

    scanner.Split();

    if (scanner.Err() != NULL) {
        SerialUSB.print("error: ");
        SerialUSB.println(scanner.Err());
        return;
    }

    err = dispatchcommand(scanner);

    if (err != NULL) {
        SerialUSB.print("error: ");
        SerialUSB.println(err);
        return;
    }

    // ack message
    SerialUSB.print("ok:");

    for (int i = 0; i < scanner.argc; i++) {
        SerialUSB.print(" ");
        SerialUSB.print(scanner.argv[i]);
    }

    SerialUSB.println();
}

// in general, we should be able to sleep / power off unless we need to do
// any processing.
//
// one of the items that can be added is using a timer interrupt with a few
// second delay to read data out. this allows us to have a built in timeout
// system.
void loop() {
    SerialUSB.print("> ");

    inputbuf[0] = '\0';
    inputlen = 0;

    while (1) {
        if (inputlen >= 256) {
            SerialUSB.println("error: buffer overflow");
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
            SerialUSB.println();
            processinput();
            break;
        } else {
            SerialUSB.write(b);
        }
    }
}
