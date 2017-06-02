#include "sender.h"
#include <Arduino.h>

const byte BBEGIN = 0xFE;
const byte BEND = 0xFC;
const byte BESCAPE = 0xFD;

bool ControlByte(byte b) {
    return (b == BBEGIN) || (b == BEND) || (b == BESCAPE);
}

class Framer {
public:

    Framer();
    const char *Err() const;
    void WriteFrame(byte *b, int n);
    int ReadFrame(byte *b, int max);

private:

    byte ReadByte();
    byte ReadEscapedByte();

    const char *err;
};

Framer::Framer() {
    err = 0;
}

const char *Framer::Err() const {
    return err;
}

void Framer::WriteFrame(byte *b, int n) {
    byte crc = 0;

    SerialUSB.write(BBEGIN);

    for (int i = 0; i < n; i++) {
        if (ControlByte(b[i])) {
            SerialUSB.write(BESCAPE);
            SerialUSB.write(b[i] ^ 0x20);
        } else {
            SerialUSB.write(b[i]);
        }
    }

    SerialUSB.write(crc);
    SerialUSB.write(BEND);
}

int Framer::ReadFrame(byte *data, int max) {
    int size = 0;

    // wait for frame start
    while (1) {
        byte b = ReadByte();

        if (err != NULL) {
            return;
        }

        if (b == BBEGIN) {
            break;
        }
    }

    // wait for data / end bytes.
    while (1) {
        if (size > max) {
            err = "frame too big";
            break;
        }

        byte b = ReadByte();

        if (err != NULL) {
            break;
        }

        if (b == BEND) {
            break;
        }

        if (b == BESCAPE) {
            data[size++] = ReadEscapedByte();
        } else {
            data[size++] = b;
        }
    }

    return size;
}

byte Framer::ReadByte() {
    unsigned long start = millis();

    while (SerialUSB.available() == 0) {
        if (millis() - start > 5000) {
            err = "read timeout";
            return 0;
        }
    }

    return SerialUSB.read();
}

byte Framer::ReadEscapedByte() {
    byte b = ReadByte();

    if (err != NULL) {
        return 0;
    }

    // control bytes should never follow escape byte.
    if (ControlByte(b)) {
        err = "invalid escaped byte";
        return 0;
    }

    return b ^ 0x20;
}
