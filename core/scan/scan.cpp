#include "../../globals.h"
#include "../../utils.h"

#define MAXTOKENLEN 40
#define BUFFER_LENGHT 256

typedef enum {
    _START, _NUMBER, _DONE
} ScanState;

char tokenString[MAXTOKENLEN + 1];

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

TokenType getToken(void) {
    int tokenStringIndex = 0;
    bool save;
    TokenType currentToken;
    ScanState state = _START;
    while (state != _DONE) {
        char c = getNextChar();
        save = true;
        switch (state) { 
            case _START: 
                if (isDigit(c))
                    state = _NUMBER;
                else if (c == EOF) 
                    state = _DONE;
                else
                    state = _DONE;
            break;
            case _NUMBER:
                if (!isDigit(c)) {
                    ungetNextChat();
                    save = false;
                    state = _DONE;
                    currentToken = NUMBER;
                }
            break;
            case _DONE: break;
        }

        if ((save) && tokenStringIndex <= MAXTOKENLEN) {
            tokenString[tokenStringIndex++] = c;
            if (state == _DONE) {
                tokenString[tokenStringIndex] = '\0';
                //if (currentToken == ID)
                    //currentToken = reservedLookup(tokenString);
            }
        }

        if (TraceScan) {
            fprintf(listing, "\t%d: ", linemo);
            printf("\ntoken: %s", tokenString);
            //printToken(currentToken, tokenString);
        }
    }

    return currentToken;
}

