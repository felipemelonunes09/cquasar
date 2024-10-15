#include "../../globals.h"
#include "../../utils.h"
#include "token.h"

#define BUFFER_LENGHT 256

typedef enum { _START=1, _NUMBER=2, _DONE=3, _ID=4, _EQUAL=5, _LESS=6, _GREATER=7, _COMMENT=8 } ScanState;

static char lineBuffer[BUFFER_LENGHT];
static int linePosition = 0;
static int bufferSize = 0;

std::unordered_map<std::string, TokenType> reserverdWords = {
    {"if",    Tt_Rw_IF },
    {"for",   Tt_Rw_FOR },
    {"while", Tt_Rw_WHILE },
    {"print", Tt_Rw_PRINT }
};

static char getNextChar(void) {
    if (!(linePosition < bufferSize)) {
        linePosition++;
        if (fgets(lineBuffer, BUFFER_LENGHT-1, source)) {
            if (EchoSource) fprintf(listing, "\n(*)%4d: %s", linemo, lineBuffer);
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

Token* getToken(void) {
    bool save;
    Token* token = new Token(); 
    ScanState state = _START;
    std::string tokenString = "";   
    while (state != _DONE) {
    
        char c = getNextChar();
        save = true;

        switch (state) { 
            case _START: 
                if (isDigit(c))
                    state = _NUMBER;
                else if (isStartIdentifier(c))
                    state = _ID;
                else if (isEqual(c)) 
                    state = _EQUAL;
                else if (isWhiteSpace(c))
                    save = false;
                else if (c == '>')
                    state = _GREATER;
                else if (c == '#') {
                    state = _COMMENT;
                    save = false;
                }
                else {
                    state = _DONE;
                    switch (c)
                    {
                        case EOF: token->setType(Tt_Ctl_ENDFILE);             break;
                        case '+': token->setType(Tt_Op_Aritc_PLUS);           break;
                        case '-': token->setType(Tt_Op_Aritc_MINUS);          break;
                        case '/': token->setType(Tt_Op_Aritc_DIVISION);       break;
                        case '*': token->setType(Tt_Op_Aritc_MULTIPLICATION); break;
                    }
                }
            break;
            case _NUMBER:
                if (!isDigit(c)) {
                    ungetNextChat();
                    save = false;
                    state = _DONE;
                    token->setType(Tt_Id_NUMBER);
                }
            break;
            case _ID:
                if (!isIdentifier(c)) {
                    ungetNextChat();
                    save = false;
                    state = _DONE;
                    token->setType(Tt_Id_IDENTIFIER);
                }
            break;
            case _EQUAL: 
                if (isEqual(c)) {
                    token->setType(Tt_Op_Bool_COMPARATION);
                }
                else {
                    token->setType(Tt_Op_Expr_ATTRIBUITION);
                    ungetNextChat();
                    save = false;
                }
                state=_DONE;
            break;
            case _LESS:
                if (c == '=') 
                    token->setType(Tt_Op_Bool_LESS_EQUAL);
                else {
                    token->setType(Tt_Op_Bool_LESS);
                    ungetNextChat();
                    save=false;
                }
                state=_DONE;
            break;
            case _GREATER:
                if (c == '=')
                    token->setType(Tt_Op_Bool_GREATER_EQUAL);
                else {
                    token->setType(Tt_Op_Bool_GREATER);
                    ungetNextChat();
                    save=false;
                }
                state=_DONE;
            break;
            case _COMMENT:
                save=false;
                if (c == '#')
                    state=_START;
            break;
            case _DONE: break;
        }
        if (save) 
            tokenString += c;
        if (state == _DONE) {
            if (reserverdWords.count(tokenString)) {
                if (TraceScan) { fprintf(listing, " (RW) "); }
                token->setType(reserverdWords[tokenString]); 
        }
        }
    }

    token->setTokenString(tokenString);
    if (TraceScan) 
        fprintf(listing, "\t%d: %s\n", linemo,  token->toString().c_str());
    return token;
}

