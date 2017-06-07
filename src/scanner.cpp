#include "scanner.h"

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
