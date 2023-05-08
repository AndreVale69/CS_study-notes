grammar IntExp;

main    : begin EOF ;

begin   : dec exp   ;

dec     : (ALF EQUA exp ENDL)*  ;

exp     : FLOAT                             # float
        | ALF                               # alf
        | exp op=(MULT | DIVI | MODU) exp   # multDiviModu
        | exp op=(PLUS | SUBT) exp          # plusSubt
        | <assoc=right> exp POTE exp        # pote
        | LPAR exp RPAR                     # expCont
        ;


LPAR    : '('   ;
RPAR    : ')'   ;
PLUS    : '+'   ;
SUBT    : '-'   ;
MULT    : '*'   ;
DIVI    : '/'   ;
POTE    : '^'   ;
MODU    : 'mod' ;
EQUA    : '='   ;
ENDL    : ';'   ;

FLOAT   : INTEGER | (INTEGER | '-' '0') '.' NUMBS + ;
fragment INTEGER    : NAT | '-' NUM         ;
fragment NAT        : '0' | NUM             ;
fragment NUM        : POSNUMBS NUMBS *      ;
fragment NUMBS      : '0' | POSNUMBS        ;
fragment POSNUMBS   : [1-9]                 ;
ALF     : [a-z]+                            ;

WS      : [ \t\n\r]+ -> skip ;
