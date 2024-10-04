#include "utils.h"

bool isDigit(char c) {
    return c >= '0' && c <= '9';
} 

bool isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}