#include <Arduino.h>

// TODO Scanner should have error handling and propogation.

class Scanner {
public:

    Scanner();
    char Next();
    char Peek();
    char Scan();
    char *TokenText();

private:

    int lookahead;
    char tok[64];
    int tokpos;
};
