#include <Arduino.h>

// NOTE May want to model system as simple state machine to recall
// what we're supposed to be doing at any given time.

const char *version = "coresense 4.0.0";

char inputbuf[256];
int inputlen;

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

Scanner::Scanner(char *b, int size) {
    buffer = b;
    buffersize = size;
    err = NULL;
}

const char *Scanner::Err() const {
    return err;
}

void Scanner::Split() {
    char *s = buffer;

    argc = 0;
    err = NULL;

    while (*s != '\0') {
        while (isspace(*s)) {
            *s++ = '\0';
        }

        if (isgraph(*s)) {
            if (argc == 8) {
                err = "error: too many args";
                return;
            }

            argv[argc++] = s;
            while (isgraph(*s)) {
                s++;
            }
        }
    }
}

bool startswith(const char *s, const char *p) {
    while (*p != '\0') {
        if (*s != *p) {
            return false;
        }

        s++;
        p++;
    }

    return true;
}

bool matches(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}

void setup() {
    SerialUSB.begin(9600);

    while (!SerialUSB) {
    }

    SerialUSB.println("system ready");

    inputlen = 0;
}

void processinput() {
    Scanner scanner(inputbuf, 256);

    scanner.Split();

    if (scanner.Err() != NULL) {
        SerialUSB.println(scanner.Err());
        return;
    }

    if (scanner.argc == 0) {
        return;
    }

    if (matches(scanner.argv[0], "v")) {
        SerialUSB.println(version);
        return;
    }

    if (matches(scanner.argv[0], "pm")) {
        if (scanner.argc != 3) {
            SerialUSB.println("error: invalid usage");
            return;
        }

        int pin = atoi(scanner.argv[1]);
        int mode;

        if (matches(scanner.argv[2], "input")) {
            mode = INPUT;
        } else if (matches(scanner.argv[2], "output")) {
            mode = OUTPUT;
        } else {
            SerialUSB.println("error: invalid pin mode");
            return;
        }

        pinMode(pin, mode);
        return;
    }

    if (matches(scanner.argv[0], "pw")) {
        if (scanner.argc != 3) {
            SerialUSB.println("error: invalid usage");
            return;
        }

        int pin = atoi(scanner.argv[1]);
        int value = atoi(scanner.argv[2]);
        digitalWrite(pin, value);
        return;
    }
}

// in general, we should be able to sleep / power off unless we need to do
// any processing.
//
// one of the items that can be added is using a timer interrupt with a few
// second delay to read data out. this allows us to have a built in timeout
// system.
void loop() {
    // TODO figure out how to make sleep mode work
    // pmc_enable_sleepmode(1);

    while (SerialUSB.available()) {
        char b = SerialUSB.read();

        inputbuf[inputlen++] = b;

        // throw out buffer if we have an overflow
        if (inputlen == 256) {
            inputlen = 0;
        }

        // ensure buffer is null terminated
        inputbuf[inputlen] = '\0';

        if (b == '\r' or b == '\n') {
            SerialUSB.write("\r\n");
            processinput();
            inputlen = 0;
            break;
        } else {
            SerialUSB.write(b);
        }
    }
}
