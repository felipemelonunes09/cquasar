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

<declarationCommand> ::= <primitiveTypes> <id> <equalsSign> <typedExpression>

<conditionalCommand> ::= "if" <openDelimiter> <logicExpression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          |
                          "if" <openDelimiter> <logicExpression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          "else"
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>

<whileLoopCommand> ::= "while" <openDelimiter> <logicExpression> <closeDelimiter>
			<openBracket>
                          <programDeclaration>
                        <closeBracket>

<arithmeticExpression> = "#NI"
<booleanExpression> = "#NI"
<logicExpression> = "#NI"

<typedExpression> := <arithmeticExpression> | <booleanExpression> | <logicExpression>

<declarationCommand> ::= "#NI"
<readCommand> ::= "#NI"
<writeCommand> ::= "#NI"

https://bnfplayground.pauliankline.com/?bnf=%3CopenBracket%3E%20%3A%3A%3D%20%22%7B%22%0A%3CcloseBracket%3E%20%3A%3A%3D%20%22%7D%22%0A%3CendCommand%3E%20%3A%3A%3D%20%22%3B%22%0A%3CopenDelimiter%3E%20%3A%3A%3D%20%22(%22%0A%3CcloseDelimiter%3E%20%3A%3A%3D%20%22)%22%0A%3CequalsSign%3E%20%3A%3A%3D%20%22%3D%22%0A%0A%3CtypeInteger%3E%20%3A%3A%3D%20%22Int%22%0A%3CtypeString%3E%20%3A%3A%3D%20%22String%22%0A%0A%3CprimitiveTypes%3E%20%3A%3A%3D%20%3CtypeInteger%3E%20%7C%20%3CtypeString%3E%0A%0A%3Cprogram%3E%20%3A%3A%3D%20%3CopenBracket%3E%20%3CprogramDeclaration%3E%20%3CcloseBracket%3E%0A%3CprogramDeclaration%3E%20%3A%3A%3D%20%3CprogramDeclaration%3E%20%3CendCommand%3E%20%3Ccommand%3E%20%7C%20%3Ccommand%3E%20%0A%0A%3Ccommand%3E%20%3A%3A%3D%20%3CconditionalCommand%3E%20%7C%20%3CdeclarationCommand%3E%20%7C%20%3CwhileLoopCommand%3E%20%7C%20%3CreadCommand%3E%20%7C%20%3CwriteCommand%3E%20%0A%0A%3CdeclarationCommand%3E%20%3A%3A%3D%20%3CprimitiveTypes%3E%20%3Cid%3E%20%3CequalsSign%3E%20%3CtypedExpression%3E%0A%0A%3CconditionalCommand%3E%20%3A%3A%3D%20%22if%22%20%3CopenDelimiter%3E%20%3ClogicExpression%3E%20%3CcloseDelimiter%3E%0A%09%09%09%09%09%09%09%3CopenBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%09%3CprogramDeclaration%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3CcloseBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22if%22%20%3CopenDelimiter%3E%20%3ClogicExpression%3E%20%3CcloseDelimiter%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%09%3CopenBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%09%3CprogramDeclaration%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3CcloseBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%22else%22%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%09%20%3CopenBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%09%3CprogramDeclaration%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%09%20%3CcloseBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%0A%3CwhileLoopCommand%3E%20%3A%3A%3D%20%22while%22%20%3CopenDelimiter%3E%20%3ClogicExpression%3E%20%3CcloseDelimiter%3E%0A%09%09%09%09%09%09%3CopenBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%09%3CprogramDeclaration%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3CcloseBracket%3E%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%0A%0A%3CarithmeticExpression%3E%20%3D%20%22%23NI%22%0A%3CbooleanExpression%3E%20%3D%20%22%23NI%22%0A%3ClogicExpression%3E%20%3D%20%22%23NI%22%0A%0A%3CtypedExpression%3E%09%3A%3A%3D%20%3CarithmeticExpression%3E%20%7C%20%3CbooleanExpression%3E%20%7C%20%3ClogicExpression%3E%0A%0A%3CdeclarationCommand%3E%20%3A%3A%3D%20%22%23NI%22%0A%3CreadCommand%3E%20%3A%3A%3D%20%22%23NI%22%0A%3CwriteCommand%3E%20%3A%3A%3D%20%22%23NI%22%0A%0A&name=QuasarGrammar
```
