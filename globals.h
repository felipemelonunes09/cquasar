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
    ENDFILE, ERROR, UNDEFINED,
    NUMBER, ID
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