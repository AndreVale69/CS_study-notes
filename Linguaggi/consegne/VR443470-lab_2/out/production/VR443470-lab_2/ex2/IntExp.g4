grammar IntExp;

main    : begin EOF ;

begin   : dec exp   ;

dec     :                       # nullassignm
        | ALF EQUA exp ENDL dec # assignm

        ;

exp     : NAT                       # nat
        | ALF                       # alf
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
EQUA    : '='   ;
ENDL    : ';'   ;

NAT     : '0' | [1-9][0-9]* | '-' [1-9][0-9]* ;
ALF     : [a-z]+;

WS      : [ \t\n\r]+ -> skip ;
