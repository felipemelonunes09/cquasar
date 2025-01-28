# Token Identificados Pelo Analisador Léxico
O analisador léxico processará o arquivo carregando linhas em um buffer com capacidade de `256` caracteres (configurável em futuras atualizações). O analisador permite chamadas para retornar, token por token, à medida que realiza a leitura. Quando a linha atual for totalmente processada, o analisador continuará automaticamente lendo a próxima linha, recarregando os `256` caracteres no buffer.

## Tokens Reconhecidos

### Tokens de Controle
-------------------
> | Simbolo  | 📐 Tipo de Token  |
> | ---| ---     | 
> | EOF |  Tt_Ctl_ENDFILE  | 
> | $ |  Tt_Ctl_ERROR  | 
> | $ |  Tt_Ctl_UNDEFINED  | 
> | ; |  Tt_Crl_ENDCOMMAND  |

### Tokens de Identificadores

> | Simbolo  | 📐 Tipo de Token  |
> | ---| ---     | 
> | [1-9][1-9]*$ |  Tt_Id_NUMBER  | 
> | [a-zA-Z][a-zA-Z0-9]*$ |  Tt_Id_IDENTIFIER  | 
> | ( |  Tt_Id_O_PARENTHESES  | 
> | ) |  Tt_Id_C_PARENTHESES  |

### Tokens de Palavras Reservadas

> | Simbolo  | 📐 Tipo de Token  |
> | ---| ---     | 
> | if |  Tt_Rw_IF  |
> | else |  Tt_Rw_Else  |
> | for |  Tt_Rw_FOR  | 
> | while |  Tt_Rw_WHILE  | 
> | print |  Tt_Rw_PRINT  |

### Tokens de Operadores

> | Simbolo  | 📐 Tipo de Token  |
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

## Comentários
Todo texto que estiver iniciando com um `'#'` e finalizando com `'#'` sera considerado um comentário e totalmente ignorado pelo analisador léxico.


