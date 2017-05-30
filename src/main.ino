#include <Arduino.h>

// NOTE May want to model system as simple state machine to recall
// what we're supposed to be doing at any given time.

const char *version = "coresense 4.0.0";

char inputbuf[256];
int inputlen;

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    SerialUSB.write("system ready\r\n");
    delay(3000);

    inputlen = 0;
}

// in general, we should be able to sleep / power off unless we need to do
// any processing.
//
// one of the items that can be added is using a timer interrupt with a few
// second delay to read data out. this allows us to have a built in timeout
// system.
void loop() {
    // enter sleep mode
    // PMC->PMC_FSMR &= PMC_FSMR_LPM;
    // __WFE();

    // TODO figure out how to make sleep mode work
    pmc_enable_sleepmode(1);

    while (SerialUSB.available()) {
        char b = SerialUSB.read();

        inputbuf[inputlen] = b;
        inputlen++;

        // throw out buffer if we have an overflow
        if (inputlen == 256) {
            inputlen = 0;
        }

        // ensure buffer is null terminated
        inputbuf[inputlen] = '\0';

        if (b == '\n') {
            break;
        }
    }

    delay(1000);
}
