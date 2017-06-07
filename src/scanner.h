#include <Arduino.h>

// TODO Scanner should have error handling and propogation.

class Scanner {
public:

    void Init(Stream &s);
    char Next();
    char Peek();
    char Scan();
    const char *TokenText() const;

private:

    Stream *reader;
    char lookahead;
    char tok[256];
    int tokpos;
};
