#include <Arduino.h>

void setup() {
  SerialUSB.begin(115200);
}

const byte data[256] = {0};

void loop() {
  for (;;) {
    SerialUSB.write(data, 256);
  }
}
