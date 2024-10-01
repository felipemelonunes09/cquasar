#include "token.h"

Token::Token() : tokenString(""), type(UNDEFINED) {}

Token::Token(const std::string& tokenString, TokenType type) :
    tokenString(tokenString), type(type) {}

Token::~Token() {}

void Token::setTokenString(const std::string& id) {
    tokenString = id;
}


void Token::setType(const TokenType tokenType) {
    type = tokenType;
}

std::string Token::getTokenString() const {
    return tokenString;
}

TokenType Token::getType() const {
    return type;
}

std::string Token:: toString() {
    return "Token(" + tokenString + ", " + std::to_string(type) + ")";
}