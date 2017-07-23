#include "scanner.h"
#include <ctype.h>

Scanner::Scanner(int (*readchar)()) {
    this->readchar = readchar;
    lookahead = -1;
    tokpos = -1;
}

// TODO Decide if we should filter nonprintable characters out.
char Scanner::Next() {
    lookahead = -1;

    while (lookahead < 0) {
        lookahead = readchar();
    }

    return lookahead;
}

char Scanner::Peek() {
    if (lookahead < 0) {
        Next();
    }

    return lookahead;
}

char Scanner::Scan() {
    int c = Peek();

    tokpos = -1;

    while (isspace(c) || c == '\0' || c == '\b') {
        if (c == '\n' || c == '\r' || c == '\0' || c == '\b') {
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

char *Scanner::TokenText() {
    if (tokpos < 0) {
        return "";
    } else {
        return tok;
    }
}
