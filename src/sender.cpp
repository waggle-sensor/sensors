#include "sender.h"
#include <Arduino.h>

const byte BBEGIN = 0xFC;
const byte BEND = 0xFE;
const byte BESCAPE = 0xCC;

bool ControlByte(byte b) {
    return b == BBEGIN || b == BEND || b == BESCAPE;
}

void SendFrame(byte *b, int n) {
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
