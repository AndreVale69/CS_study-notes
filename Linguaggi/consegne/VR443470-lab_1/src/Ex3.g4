grammar Ex3;

main : pal EOF;

pal : | '0' | '1' | '0' pal '0' | '1' pal '1';

