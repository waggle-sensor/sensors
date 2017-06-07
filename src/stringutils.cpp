#include "stringutils.h"
#include <Arduino.h>

bool startswith(const char *s, const char *p) {
    while (*p != '\0') {
        if (*s != *p) {
            return false;
        }

        s++;
        p++;
    }

    return true;
}

bool matches(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}

char tolower(char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    }

    return c;
}

char toupper(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 'a' + 'A';
    }

    return c;
}

int parseInt(const char *s) {
    return -1;
}

int parseHex(const char *s) {
    return -1;
}
