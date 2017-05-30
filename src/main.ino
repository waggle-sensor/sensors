#include <Arduino.h>
#include <Wire.h>
#include <OneWire.h>
#include "scanner.h"

// NOTE May want to model system as simple state machine to recall
// what we're supposed to be doing at any given time.

const char *version = "coresense 4.0.0";

char inputbuf[256];
int inputlen;

bool startswith(const char *s, const char *p) {
    while (*p != '\0') {
        if (*s != *p) {
            return false;
        }

        s++;
        p++;
    }

    return true;
}

bool matches(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }
}

OneWire ds(48);

const char *dispatchcommand(Scanner &scanner) {
    if (scanner.argc == 0) {
        return NULL;
    }

    if (matches(scanner.argv[0], "ver")) {
        if (scanner.argc != 1) {
            return "usage: ver";
        }

        SerialUSB.println(version);
    } else if (matches(scanner.argv[0], "pm")) {
        if (scanner.argc != 3) {
            return "usage: pm pin mode";
        }

        int pin = atoi(scanner.argv[1]);
        int mode;

        if (matches(scanner.argv[2], "input")) {
            mode = INPUT;
        } else if (matches(scanner.argv[2], "output")) {
            mode = OUTPUT;
        } else {
            return "error: invalid pin mode";
        }

        pinMode(pin, mode);
    } else if (matches(scanner.argv[0], "pw")) {
        if (scanner.argc != 3) {
            return "usage: pw pin value";
        }

        int pin = atoi(scanner.argv[1]);
        int value = atoi(scanner.argv[2]);
        digitalWrite(pin, value);
    } else if (matches(scanner.argv[0], "id")) {
        if (scanner.argc != 1) {
            return "usage: id";
        }

        ds.reset();
        ds.write(0x33);
        byte mac[8];

        for (int i = 0; i < 8; i++) {
            mac[i] = ds.read();
        }

        if (OneWire::crc8(mac, 8) != 0) {
            return "error: failed crc";
        }

        for (int i = 0; i < 8; i++) {
            SerialUSB.print((mac[i] >> 4) & 0x0F, HEX);
            SerialUSB.print((mac[i] >> 0) & 0x0F, HEX);
        }

        SerialUSB.println();
    } else if (matches(scanner.argv[0], "i2c-begin")) {
        if (scanner.argc != 2) {
            return "error: invalid usage";
        }

        int addr = atoi(scanner.argv[1]);
        Wire.beginTransmission(addr);
    } else if (matches(scanner.argv[0], "i2c-end")) {
        Wire.endTransmission();
    } else if (matches(scanner.argv[0], "i2c-req")) {
        if (scanner.argc != 3) {
            return "usage: i2c-req addr n";
        }
    } else if (matches(scanner.argv[0], "i2c-read")) {
        if (scanner.argc != 2) {
            return "usage: i2c-read n";
        }
    } else {
        return "error: invalid command";
    }

    return NULL;
}

const char *processinput() {
    const char *err;

    Scanner scanner(inputbuf, 256);

    scanner.Split();

    if (scanner.Err() != NULL) {
        return scanner.Err();
    }

    err = dispatchcommand(scanner);

    if (err != NULL) {
        return err;
    }

    // ack message
    SerialUSB.print("ok:");

    for (int i = 0; i < scanner.argc; i++) {
        SerialUSB.print(" ");
        SerialUSB.print(scanner.argv[i]);
    }

    SerialUSB.println();

    return NULL;
}

// in general, we should be able to sleep / power off unless we need to do
// any processing.
//
// one of the items that can be added is using a timer interrupt with a few
// second delay to read data out. this allows us to have a built in timeout
// system.
void loop() {
    // TODO figure out how to make sleep mode work
    // pmc_enable_sleepmode(1);

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
