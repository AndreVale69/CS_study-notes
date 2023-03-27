grammar Ex1;

main : digits EOF;

digits : '0' seq_zero one_rep | one_rep;

seq_zero : | '0' seq_zero;

seq_any : | '0' seq_any | '1' seq_any;

one_rep : '1' seq_zero '1' seq_zero '1' seq_zero '1' seq_any;
