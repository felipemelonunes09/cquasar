# Token Identificados Pelo Analisador Léxico

The lexical analyzer will process the file by loading lines into a buffer with a capacity of `256` characters (configurable in future updates). The analyzer allows calls to return tokens one by one as it performs the reading. When the current line is fully processed, the analyzer will automatically continue reading the next line, reloading the `256` characters into the buffer.

## Recognized Tokens

### Controls Tokens
-------------------
> | Symbol  | 📐 Token Type  |
> | ---| ---     | 
> | EOF |  Tt_Ctl_ENDFILE  | 
> | $ |  Tt_Ctl_ERROR  | 
> | $ |  Tt_Ctl_UNDEFINED  | 
> | ; |  Tt_Crl_ENDCOMMAND  |

### Identifier Tokens

> | Symbol  | 📐 Token Type   |
> | ---| ---     | 
> | [1-9][1-9]*$ |  Tt_Id_NUMBER  | 
> | [a-zA-Z][a-zA-Z0-9]*$ |  Tt_Id_IDENTIFIER  | 
> | ( |  Tt_Id_O_PARENTHESES  | 
> | ) |  Tt_Id_C_PARENTHESES  |

### Reserved Words Tokens

> | Symbol  | 📐 Token Type   |
> | ---| ---     | 
> | if |  Tt_Rw_IF  |
> | else |  Tt_Rw_Else  |
> | for |  Tt_Rw_FOR  | 
> | while |  Tt_Rw_WHILE  | 
> | print |  Tt_Rw_PRINT  |

### Operators Tokens

> | Symbol  | 📐 Token Type   |
> | ---| ---     | 
> | = |  Tt_Op_Expr_ATTRIBUITION  |
> | + |  Tt_Op_Aritc_PLUS  | 
> | - |  Tt_Op_Aritc_MINUS  | 
> | / |  Tt_Op_Aritc_MULTIPLICATION  |
> | * |  Tt_Op_Aritc_DIVISION  |
> | == |  Tt_Op_Bool_COMPARATION  |
> | >= |  Tt_Op_Bool_GREATER_EQUAL  |
> | > |  Tt_Op_Bool_GREATER  |
> | < |  Tt_Op_Bool_LESS  |
> | <= |  Tt_Op_Bool_LESS_EQUAL  |

## Comment
Any text that starts with `#` and ends with `#` will be considered a comment and completely ignored by the lexical analyzer.

