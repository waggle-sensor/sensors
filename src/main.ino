#include <Arduino.h>
// #include <Wire.h>
// #include <OneWire.h>
#include "scanner.h"
#include "stringutils.h"
#include <cstdarg>

void Printf(const char *fmt, ...) {
    char s[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(s, 80, fmt, args);
    SerialUSB.println(s);
    va_end(args);
}

// OneWire ds(48);

Scanner scanner;

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    scanner.Init();
    // Wire.begin();

    Printf("debug: setup complete");
}

void commandID() {
    if (scanner.Scan() != '\n') {
        Printf("err: invalid args");
        return;
    }

    Printf("ok: 0.0.1");

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
        Printf("err: invalid args");
        return;
    }

    Printf("ok: abc123");
}

void command2Write() {
    int count = 0;

    while (scanner.Scan() != '\n') {
        Printf("debug: write %s", scanner.TokenText())
        count++;
    }

    Printf("ok: %d", count);
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
    Printf("err: not implemented");
}

bool execCommand() {
    // consume leading newline tokens
    while (scanner.Scan() == '\n') {
        Printf("debug: consume newline");
        // if (scanner.Err()) {
        //     scanner.Reset();
        // }
    }

    Printf("debug: command <%s>", scanner.TokenText());

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
    Printf("debug: start loop");

    Printf("debug: start execCommand");
    bool ok = execCommand();
    Printf("debug: end execCommand");

    if (!ok) {
        Printf("err: invalid command [%s]", scanner.TokenText());
    }

    Printf("debug: end loop");
}
