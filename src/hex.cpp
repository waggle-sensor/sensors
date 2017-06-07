// #include <Arduino.h>
#include "hex.h"
#include <stdio.h>
#include <string.h>

static const char hextable[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f',
};

static byte fromHexChar(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }

    if ('a' <= c && c <= 'f') {
        return c - 'a' + 10;
    }

    if ('A' <= c && c <= 'F') {
        return c - 'A' + 10;
    }

    return 0xff;
}

int EncodeHex(const byte *src, char *dst, int size) {
    for (int i = 0; i < size; i++) {
        dst[2*i] = hextable[src[i] >> 4];
        dst[2*i+1] = hextable[src[i] & 0x0f];
    }

    dst[2*size] = '\0';
    return 2*size;
}

int DecodeHex(const char *src, byte *dst) {
    int size = strlen(src);

    if (size % 2 != 0) {
        return -1;
    }

    for (int i = 0; i < size/2; i++) {
        byte a = fromHexChar(src[2*i]);

        if (a == 0xff) {
            return -1;
        }

        byte b = fromHexChar(src[2*i+1]);

        if (b == 0xff) {
            return -1;
        }

        dst[i] = (a << 4) | b;
    }

    return size/2;
}
