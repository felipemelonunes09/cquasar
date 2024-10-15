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
    Tt_Ctl_ENDFILE=0, Tt_Ctl_ERROR=-1, Tt_Ctl_UNDEFINED=-2,
    Tt_Id_NUMBER=1, Tt_Id_IDENTIFIER=2,
    Tt_Rw_IF=3, Tt_Rw_FOR=4, Tt_Rw_WHILE=5, Tt_Rw_PRINT=6,
        Tt_Op_Expr_ATTRIBUITION=7,
        Tt_Op_Aritc_PLUS=8, Tt_Op_Aritc_MINUS=9, Tt_Op_Aritc_MULTIPLICATION=10, Tt_Op_Aritc_DIVISION=11,
        Tt_Op_Bool_COMPARATION=12, Tt_Op_Bool_GREATER_EQUAL=13, Tt_Op_Bool_GREATER=14, Tt_Op_Bool_LESS=15, Tt_Op_Bool_LESS_EQUAL=16
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