#include "../../globals.h"
#include "../../utils.h"
#include "token.h"

#define BUFFER_LENGHT 256

typedef enum { _START, _NUMBER, _DONE } ScanState;

static char lineBuffer[BUFFER_LENGHT];
static int linePosition = 0;
static int bufferSize = 0;

static char getNextChar(void) {
    if (!(linePosition < bufferSize)) {
        linePosition++;
        if (fgets(lineBuffer, BUFFER_LENGHT-1, source)) {
            if (EchoSource) fprintf(listing, "%4d: %s", linemo, lineBuffer);
            bufferSize = strlen(lineBuffer);
            linePosition = 0;
            return lineBuffer[linePosition++];
        }
        else return EOF;
    }
    return lineBuffer[linePosition++];
}

static void ungetNextChat(void) {
    linePosition--;
}

Token getToken(void) {
    bool save;
    Token token;
    ScanState state = _START;
    std::string tokenString = "";

    while (state != _DONE) {
        char c = getNextChar();
        save = true;
        switch (state) { 
            case _START: 
                if (isDigit(c))
                    state = _NUMBER;
                else if (isWhiteSpace(c))
                    save = false;
                else {
                    state = _DONE;
                    switch (c)
                    {
                        case EOF:
                        break;
                    }
                }
            break;
            case _NUMBER:
                if (!isDigit(c)) {
                    ungetNextChat();
                    save = false;
                    state = _DONE;
                    token.setType(NUMBER);
                }
            break;
            case _DONE: break;
        }

        if (save) {
            tokenString += c;
            if (state == _DONE) {
                //if (currentToken == ID)
                    //currentToken = reservedLookup(tokenString);
            }
        }

        if (TraceScan) {
            fprintf(listing, "\t%d: ", linemo);
        }
    }

    token.setTokenString(tokenString);
    return token;
}

