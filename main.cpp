#include <iostream>
#include "globals.h"

/* if true the compiler will only make the scan */
#define NO_PARSE true

/* if true compiler will only make the syntax analysis */
#define NO_ANALYZE false

/* if true compiler will not generate code */
#define NO_CODE false

#if NO_PARSE
#include "./core/scan/scan.h"
#else
#include "./core/scan/scan.h"
#if !NO_ANALYZE
/*#include "analyzer"*/
#if !NO_CODE
/*#include "generator"*/
#endif
#endif
#endif

/* global variable allocation */
int linemo = 0;
FILE* source;
FILE* listing;
FILE* code;

/* tracemarks */

bool EchoSource      = true;
bool TraceScan       = true;
bool TraceParser     = true;
bool TraceAnalyzer   = true;
bool TraceCode       = true;
bool Error           = false;

int main(int argc, char* argv[]) {
    std::cout << "Quasar Compiler v0.1" << std::endl; // TODO: version number
    if (argc < 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char* filename = (char*) malloc((strlen(argv[1]) + 1) * sizeof(char));
    strcpy(filename, argv[1]);

    if (strchr(filename, '.') == NULL) {
        strcat(filename, ".qs");
    }
    source = fopen(filename, "r");
    if (source == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        exit(1);
    }
    listing = stdout;
    fprintf(listing, "\nQUASAR COMPILATION: %s\n", filename);

    #if NO_PARSE
    // TODO: implement a simple parser
    getToken();
    getToken();
    #endif

    free(filename);
    return 0;
}