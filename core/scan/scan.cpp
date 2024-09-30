#include "../../globals.h"

#define MAXTOKENLEN 40
#define BUFFER_LENGHT 256

typedef enum {
    START, IN_ASSIGN, IN_COMMENT, IN_NUM, IN_ID, DONE
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

TokenType getToken(void) {
    char c = getNextChar();
    
    fprintf(stdout, "%c", c);
    return ENDFILE;
}

