grammar Ex4;

main : start EOF;

start : | inizia_a | inizia_b;

inizia_a : | 'a' inizia_a continua_b fine_c;

inizia_b : | 'b' inizia_b fine_c;

continua_b : | 'b' continua_b fine_c;

fine_c : 'c';
