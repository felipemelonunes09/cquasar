```bash
#
# Terminals
#

<openBracket>    ::= {
<closeBrackets>  ::= }
<endCommand>     ::= ;
<openDelimiter>  ::= (
<closeDelimiter> ::= )

<typeInteger> ::= Int
<typeString> ::= String


<id> ::= "[A-z]([A-z]|[0-9])+"
<number> ::= [0-9]+"

#
# Non-terminals
#

<primitiveTypes> ::= <typeInteger> | <typeString>

<program>            ::= <openBracket> <programDeclaration> <closeBrackets>
<programDeclaration> ::= <command> { <endcommand>, <command> }

<multOperator> ::= * | -
<addOperator> ::= + | -
<boolOperator> :: < | > | >= | <= | ==
<logicOperator> :: == | >< | && | ||

<factor> ::= ( <expression> ) | <number> | <id>
<term> ::= <factor> { <multOperator> <factor> }

<AriticExpression> ::= <term> { <addOperator> <term> }
<booleanExpression> ::= <expression> [ <boolOperator> <expression> ]
<logicExpression> ::= <booleanExpression> [ <logicOperator> <booleanExpression> ]

<typedDeclaration> ::= <AriticExpression> | <booleanExpression> | <logicExpression>

##
## Commands
##

<declarationCommand> ::= <primitiveTypes> <id> <equalsSign> <typedDeclaration>

<conditionalCommand> ::= if <openDelimiter> <logicExpression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          |
                          if <openDelimiter> <logicExpression> <closeDelimiter>
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>
                          else
                          <openBracket>
                            <programDeclaration>
                          <closeBracket>

<whileLoopCommand> ::= while <openDelimiter> <logicExpression> <closeDelimiter>
			<openBracket>
                          <programDeclaration>
                        <closeBracket>

<readCommand> ::= read <id>
<writeCommand> ::= write <id>

<command> ::= <conditionalCommand> | <whileLoopCommand> | <readCommand> | <writeCommand> | <declarationCommand>

