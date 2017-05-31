class Scanner {
public:

    Scanner(char *b, int size);
    void Split();
    const char *Err() const;

    int argc;
    char *argv[8];
    char *buffer;
    int buffersize;
    const char *err;
};
