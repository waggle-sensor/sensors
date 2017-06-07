#include <Arduino.h>
// #include <Wire.h>
// #include <OneWire.h>
#include "stringutils.h"

// OneWire ds(48);

// TODO Add support for detecting type of data coming in.
class Scanner {
public:

    void Init(Stream &s);
    char Next();
    char Peek();
    char Scan();
    const char *TokenText() const;

private:

    Stream *reader;
    char lookahead;
    char tok[256];
    int tokpos;
};

void Scanner::Init(Stream &s) {
    reader = &s;
    lookahead = -1;
    tokpos = -1;
}

char Scanner::Next() {
    while (reader->available() == 0) {
        delay(10);
    }

    lookahead = reader->read();
    return lookahead;
}

char Scanner::Peek() {
    if (lookahead == -1) {
        Next();
    }

    return lookahead;
}

char Scanner::Scan() {
    char c = Peek();

    tokpos = -1;

    while (isspace(c)) {
        if (c == '\n' || c == '\r') {
            lookahead = -1;
            return '\n';
        }

        c = Next();
    }

    if (isgraph(c)) {
        tokpos = 0;

        while (isgraph(c)) {
            tok[tokpos++] = c;
            c = Next();
        }

        tok[tokpos] = '\0';
    }

    return 0;
}

const char *Scanner::TokenText() const {
    if (tokpos < 0) {
        return "";
    } else {
        return tok;
    }
}

Scanner scanner;

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    SerialUSB.println("debug: setup");

    // Wire.begin();
}

void commandID() {
    if (scanner.Scan() != '\n') {
        SerialUSB.println("err: invalid args");
        return;
    }

    SerialUSB.println("ok: 0.0.1");

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
        SerialUSB.println("err: invalid args");
        return;
    }

    SerialUSB.println("ok: abc123");
}

void command2Write() {
    int count = 0;

    while (scanner.Scan() != '\n') {
        SerialUSB.print("debug: write ");
        SerialUSB.println(scanner.TokenText());
        count++;
    }

    SerialUSB.print("ok: ");
    SerialUSB.println(count);
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
    SerialUSB.println("err: not implemented");
}

bool execCommand() {
    // consume leading newline tokens
    while (scanner.Scan() == '\n') {
        // if (scanner.Err()) {
        //     scanner.Reset();
        // }
    }

    SerialUSB.print("debug: command ");
    SerialUSB.println(scanner.TokenText());

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
    scanner.Init(SerialUSB);

    if (!execCommand()) {
        SerialUSB.print("err: invalid command ");
        SerialUSB.println(scanner.TokenText());
    }
}
