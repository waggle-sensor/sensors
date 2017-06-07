#include <Arduino.h>

// TODO Scanner should have error handling and propogation.

class Scanner {
public:

    void Init();
    char Next();
    char Peek();
    char Scan();
    const char *TokenText() const;

private:

    char lookahead;
    char tok[64];
    int tokpos;
};
