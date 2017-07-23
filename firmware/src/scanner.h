class Scanner {
public:

    Scanner(int (*readchar)());
    char Next();
    char Peek();
    char Scan();
    char *TokenText();

private:

    int (*readchar)();
    int lookahead;
    char tok[64];
    int tokpos;
};
