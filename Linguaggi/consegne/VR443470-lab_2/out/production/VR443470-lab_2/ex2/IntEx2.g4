grammar IntEx2;

main    : dec EOF ;

dec     : ALF                       # alf
        | ;

exp     : NAT                       # nat
        | LPAR exp PLUS exp RPAR    # plus
        | LPAR exp SUBT exp RPAR    # sub
        | LPAR exp MULT exp RPAR    # mul
        | LPAR exp DIVI exp RPAR    # div
        | LPAR exp MODU exp RPAR    # mod
        ;

LPAR    : '('   ;
RPAR    : ')'   ;
PLUS    : '+'   ;
SUBT    : '-'   ;
MULT    : '*'   ;
DIVI    : '/'   ;
MODU    : 'mod' ;


NAT     : '0' | [1-9][0-9]* | '-' [1-9][0-9]* ;
ALF     : [a-z]+;

WS      : [ \t\n\r]+ -> skip ;
