grammar IntEx2;

main    : dec EOF ;

dec     : ALF                       # alf
        | ALF EQUA NAT ENDL dec     # assi
        ;

exp     : NAT                       # nat
        | LPAR exp PLUS exp RPAR    # plus
        | LPAR exp SUBT exp RPAR    # sub
        | LPAR exp MULT exp RPAR    # mul
        | LPAR exp DIVI exp RPAR    # div
        | LPAR exp MODU exp RPAR    # mod
        ;

NAT     : '0' | [1-9][0-9]* | '-' [1-9][0-9]* ;
ALF     : [a-z]+;

LPAR    : '('   ;
RPAR    : ')'   ;
PLUS    : '+'   ;
SUBT    : '-'   ;
MULT    : '*'   ;
DIVI    : '/'   ;
MODU    : 'mod' ;
EQUA    : '='   ;
ENDL    : ';'   ;

WS      : [ \t\n\r]+ -> skip ;
