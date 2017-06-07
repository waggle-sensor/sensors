#include "scanner.h"

void Scanner::Init() {
    lookahead = -1;
    tokpos = -1;
}

char Scanner::Next() {
    while (!SerialUSB.available()) {
        delay(10);
    }

    lookahead = SerialUSB.read();

    SerialUSB.print("debug: next = <");
    SerialUSB.print((int)lookahead);
    SerialUSB.println(">");

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

    while (isspace(c) || c == '\0') {
        if (c == '\n' || c == '\r' || c == '\0') {
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
