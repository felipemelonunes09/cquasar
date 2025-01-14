```bash
<openBracket>    ::= "{"
<closeBrackets>  ::= "}"
<endCommand>     ::= ";"
<openDelimiter>  ::= "("
<closeDelimiter> ::= ")"

<typeInteger> ::= "Int"
<typeString> ::= "String"

<primitiveTypes> ::= <typeInteger> | <typeString>

<program>            ::= <openBracket> <programDeclaration> <closeBrackets>
<programDeclaration> ::= <programDeclaration> <endCommand> <command> | <command> 

<command> ::= <conditionalCommand> | <loopCommand> | <readCommand> | <writeCommand>

<conditionalCommand> ::= "if" <openDelimiter> <booleanExpression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          |
                          "if" <openDelimiter> <booleanExpression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          "else"
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>

<whileLoopCommand> ::= "while" <openDelimiter> <booleanExpression> <closeDelimiter>
						            <openBracket>
                          <programDeclaration>
                        <closeBracket>

<declarationCommand> ::= "#NI"
<booleanExpression> ::= "NI"
<loopCommand> ::= "NI"
<readCommand> ::= "NI"
<writeCommand> ::= "NI"
```
