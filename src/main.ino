#include <Arduino.h>
#include <Wire.h>
#include <OneWire.h>
#include "scanner.h"
#include "stringutils.h"

const char *ERROR_INVALID_ARGS = "invalid args";
const char *ERROR_NOT_IMPLEMENTED = "not implemented";
const char *ERROR_TIMED_OUT = "timed out";

const char *version = "coresense 4.0.0";
char inputbuf[256];
int inputlen;
OneWire ds(48);

// const char *base16[16] = "0123456789ABCDEF";
//
// byte value16(char c) {
//     if ('0' <= c && c <= '9') {
//         return c - '0';
//     }
//
//     if ('A' <= c && c <= 'F') {
//         return c - 'A';
//     }
//
//     if ('a' <= c && c <= 'f') {
//         return c - 'a';
//     }
//
//     return 0xFF;
// }
//
// void encode16(const byte *b, char *s, int n) {
//     for (int i = 0; i < n; i++) {
//         *s++ = base16[(b[i] >> 4) & 0xF];
//         *s++ = base16[(b[i] >> 0) & 0xF];
//     }
// }
//
// const char *decode16(const char *s, byte *b) {
//     while (*s != '\0') {
//         byte h = value16(*s++);
//         byte l = value16(*s++);
//
//         if (h == 0xFF || l == 0xFF) {
//             return "invalid symbol";
//         }
//
//         *b++ = (h << 4) | l;
//     }
//
//     return NULL;
// }

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

    // print hex string
    for (int i = 0; i < 8; i++) {
        SerialUSB.print((mac[i] >> 4) & 0x0F, HEX);
        SerialUSB.print((mac[i] >> 0) & 0x0F, HEX);
    }

    SerialUSB.println();
    return NULL;
}

const char *commandPinMode(int argc, const char **argv) {
    if (argc != 3) {
        return ERROR_INVALID_ARGS;
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
        return ERROR_INVALID_ARGS;
    }

    int pin = atoi(argv[1]);
    int value = atoi(argv[2]);
    digitalWrite(pin, value);
    return NULL;
}

const char *commandI2CBegin(int argc, const char **argv) {
    if (argc != 2) {
        return ERROR_INVALID_ARGS;
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
    if (argc != 3) {
        return ERROR_INVALID_ARGS;
    }

    int addr = atoi(argv[1]);
    int count = atoi(argv[2]);

    Wire.requestFrom(addr, count);

    return NULL;
}

const char *commandI2CRead(int argc, const char **argv) {
    byte data[64];

    if (argc != 2) {
        return ERROR_INVALID_ARGS;
    }

    int count = atoi(argv[1]);

    unsigned long startTime = millis();

    for (int i = 0; i < count; i++) {
        while (Wire.available() == 0) {
            if (millis() - startTime > 5000) {
                return ERROR_TIMED_OUT;
            }
        }

        data[i] = Wire.read();
    }

    // print hex string
    for (int i = 0; i < count; i++) {
        SerialUSB.print((data[i] >> 4) & 0x0F, HEX);
        SerialUSB.print((data[i] >> 0) & 0x0F, HEX);
    }

    SerialUSB.println();

    return NULL;
}

const char *commandI2CWrite(int argc, const char **argv) {
    // byte data[64];
    //
    // for (const char *s = argv[1], byte *b = data; *s != '\0'; s++, b++) {
    // }

    return ERROR_NOT_IMPLEMENTED;
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
    {"i2c-write", commandI2CWrite},
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

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    Wire.begin();
}

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
