#include <Arduino.h>

// TODO Scanner should have error handling and propogation.

class Scanner {
public:

    Scanner();
    char Next();
    char Peek();
    char Scan();
    const char *TokenText() const;

private:

    int lookahead;
    char tok[64];
    int tokpos;
};
