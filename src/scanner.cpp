#include "scanner.h"
#include <Arduino.h>

Scanner::Scanner(char *b, int size) {
    buffer = b;
    buffersize = size;
    err = NULL;
}

const char *Scanner::Err() const {
    return err;
}

void Scanner::Split() {
    char *s = buffer;

    argc = 0;
    err = NULL;

    while (*s != '\0') {
        while (isspace(*s)) {
            *s++ = '\0';
        }

        if (isgraph(*s)) {
            if (argc == 8) {
                err = "error: too many args";
                return;
            }

            argv[argc++] = s;
            while (isgraph(*s)) {
                s++;
            }
        }
    }
}
