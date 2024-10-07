#ifndef TOKEN_H
#define TOKEN_H
#include "../../globals.h"


class Token {
    public:
        ~Token();
        Token();
        Token(const std::string& tokenString, TokenType type);
        void setTokenString(const std::string& id);
        void setType(TokenType type);
        std::string getTokenString() const;
        std::string toString();
        TokenType getType() const; 
    private:
        std::string tokenString;
        TokenType type;
};

#endif