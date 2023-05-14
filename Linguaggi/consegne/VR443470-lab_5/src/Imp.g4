grammar Imp;

prog: com EOF;

com : IF LPAR exp RPAR THEN LBRACE com RBRACE ELSE LBRACE com RBRACE    # if
    | ID ASSIGN exp                                                     # assign
    | ID LPARQUA exp RPARQUA ASSIGN exp                                 # array
    | SKIPP                                                             # skip
    | com SEMICOLON com                                                 # seq
    | WHILE LPAR exp RPAR LBRACE com RBRACE                             # while
    | OUT LPAR exp RPAR                                                 # out
    ;

exp : NAT                               # nat
    | BOOL                              # bool
    | STRING                            # string
    | LPAR exp RPAR                     # parExp
    | <assoc=right> exp POW exp         # pow
    | TOSTR LPAR exp RPAR               # toStr
    | NOT exp                           # not
    | exp op=(DIV | MUL | MOD) exp      # divMulMod
    | exp op=(PLUS | MINUS) exp         # plusMinus
    | exp op=(LT | LEQ | GEQ | GT) exp  # cmpExp
    | exp op=(EQQ | NEQ) exp            # eqExp
    | exp op=(AND | OR | CONC) exp      # andOrConcExp
    | ID                                # id
    | ID LPARQUA exp RPARQUA            # access
    ;

NAT     : '0'       | [1-9][0-9]*   ;
BOOL    : 'true'    | 'false'       ;
STRING  : '"' LETT* '"'             ;

fragment LETT   : ~["\\\r\n] | ESCAPE   ;
fragment ESCAPE : '\\' [btnfr"'\\]      ;

PLUS    : '+'   ;
MINUS   : '-'   ;
MUL     : '*'   ;
DIV     : '/'   ;
MOD     : 'mod' ;
POW     : '^'   ;

AND     : '&'   ;
OR      : '|'   ;

EQQ     : '=='  ;
NEQ     : '!='  ;
LEQ     : '<='  ;
GEQ     : '>='  ;
LT      : '<'   ;
GT      : '>'   ;
NOT     : '!'   ;

IF      : 'if'      ;
THEN    : 'then'    ;
ELSE    : 'else'    ;
WHILE   : 'while'   ;
SKIPP   : 'skip'    ;
ASSIGN  : '='       ;
OUT     : 'out'     ;
TOSTR   : 'tostr'   ;
CONC    : '.'       ;

LPAR        : '('   ;
RPAR        : ')'   ;
LPARQUA     : '['   ;
RPARQUA     : ']'   ;
LBRACE      : '{'   ;
RBRACE      : '}'   ;
SEMICOLON   : ';'   ;

ID  : [a-z]+    ;

WS  : [ \t\r\n]+ -> skip;