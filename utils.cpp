#include "utils.h"
#include <cctype> 

bool isDigit(char c) {
    return c >= '0' && c <= '9';
} 

bool isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

bool isStartIdentifier(char c) {
    return isalpha(c) || c == '_';
}

bool isIdentifier(char c) {
    return isStartIdentifier(c) || isDigit(c);
}

bool isEqual(char c) {
    return c == '=';
}