#include <Arduino.h>

void setup() {
  // Select highest rate.
  // This seems to be able to dramatically exceed standard rates. I've seen rates into the 5-6 MB/s range.
  SerialUSB.begin(0);
}

const byte data[256] = {0};

void loop() {
  for (;;) {
    SerialUSB.write(data, 256);
  }
}
