#include "fmt.h"
#include <cstdarg>

void Printf(const char *fmt, ...) {
    char s[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(s, 80, fmt, args);
    SerialUSB.println(s);
    va_end(args);
}
