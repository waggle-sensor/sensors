#include <Arduino.h>

class Framer {
public:

    Framer();
    const char *Err() const;
    void WriteFrame(byte *b, int n);
    int ReadFrame(byte *b, int max);

private:

    byte ReadByte();
    byte ReadEscapedByte();
    void ReadUntilStart();
    int ReadBody(byte *data, int max);

    const char *err;
};
