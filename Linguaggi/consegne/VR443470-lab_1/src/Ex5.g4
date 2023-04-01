grammar Ex5;

main : start EOF;

start : | start_0 | start_0_double;

start_0 : | '0' start_0 one;
one : '1';

start_0_double :  | '0' start_0_double one one;
