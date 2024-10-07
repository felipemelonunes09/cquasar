#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>

/* max quantity of reserved words */
#define MAXRESERVERD = 8

extern FILE* source;
extern FILE* listing;
extern FILE* code;

extern int linemo; /* enumeration of the lines  of the file source listing */

typedef enum {
    ENDFILE=0, ERROR=-1, UNDEFINED=-2,
    NUMBER=1, ID=2,
    IF=3, FOR=4, WHILE=5, PRINT=6
} TokenType;

/**************************************************/
/****** Tracemarks to follow the execution ****** */
/**************************************************/

extern bool EchoSource;
extern bool TraceScan;
extern bool TraceParse;
extern bool TraceAnalyze;
extern bool TraceCode;
extern bool Error;

#endif