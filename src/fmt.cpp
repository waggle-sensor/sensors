#include "fmt.h"
#include <Arduino.h>

void Printf(const char *fmt, ...) {
    char s[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(s, 80, fmt, args);
    va_end(args);
    SerialUSB.println(s);
}
