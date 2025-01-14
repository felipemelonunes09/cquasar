```bash
<openBracket>   ::= "{"
<closeBrackets> ::= "}"
<endCommand>    ::= ";"

<program>            ::= <openBracket> <programDeclaration> <closeBrackets>
<programDeclaration> ::= <programDeclaration> <endCommand> <command> | <command> 

<command> ::= <conditionalCommand> | <loopCommand> | <readCommand> | <writeCommand> 
```
