#include <Wire.h>

void ReadI2C(char address, int length, char *out);
void WriteI2C(char address, int length, char *in);
