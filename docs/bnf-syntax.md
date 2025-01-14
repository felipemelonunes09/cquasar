```bash
<openBracket>    ::= "{"
<closeBrackets>  ::= "}"
<endCommand>     ::= ";"
<openDelimiter>  ::= "("
<closeDelimiter> ::= ")"

<program>            ::= <openBracket> <programDeclaration> <closeBrackets>
<programDeclaration> ::= <programDeclaration> <endCommand> <command> | <command> 

<command> ::= <conditionalCommand> | <loopCommand> | <readCommand> | <writeCommand>

<conditionalCommand> ::= "if" <openDelimiter> <expression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          |
                          "if" <openDelimiter> <expression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          "else"
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
  
<expression> ::= "NI"
<loopCommand> ::= "NI"
<readCommand> ::= "NI"
<writeCommand> ::= "NI"
```
