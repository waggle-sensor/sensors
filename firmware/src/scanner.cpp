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

    do {
        int c = readchar();

        if (isprint(c) || c == '\n' || c == '\r') {
            lookahead = c;
        }
    } while(lookahead < 0);

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

    while (isspace(c) && c != '\r' && c != '\n') {
        c = Next();
    }

    if (c == '\r' || c == '\n') {
        lookahead = -1;
        return '\n';
    }

    tokpos = 0;

    while (isgraph(c)) {
        tok[tokpos++] = c;
        c = Next();
    }

    tok[tokpos] = 0;

    return 0;
}

char *Scanner::TokenText() {
    if (tokpos < 0) {
        return "";
    } else {
        return tok;
    }
}
