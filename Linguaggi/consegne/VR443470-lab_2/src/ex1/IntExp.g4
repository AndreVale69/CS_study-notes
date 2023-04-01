grammar IntExp;

main    : exp EOF ;

exp     : NAT                       # nat
        | LPAR exp PLUS exp RPAR    # plus
        | LPAR exp MULT exp RPAR    # mul
        | LPAR exp SUBT exp RPAR    # sub
        | LPAR exp DIVI exp RPAR    # div
        | LPAR exp MODU exp RPAR    # mod
        ;

LPAR    : '('   ;
RPAR    : ')'   ;
PLUS    : '+'   ;
MULT    : '*'   ;
SUBT    : '-'   ;
DIVI    : '/'   ;
MODU    : 'mod' ;


NAT     : '0' | [1-9][0-9]* | '-' [1-9][0-9]* ;

WS      : [ \t\n\r]+ -> skip ;
