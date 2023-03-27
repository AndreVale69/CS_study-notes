grammar Ex5;

main : seq EOF;

seq : | first_lang | sec_lang;

first_lang : | '0' first_lang one | '1' first_lang zero;
one : '1' first_lang;
zero : '0' first_lang;

sec_lang : | '0' sec_lang d_one | d_one_zero | d_one '0' sec_lang;
d_one : '1' sec_lang '1' sec_lang;
d_one_zero : '1' sec_lang '0' sec_lang '1' sec_lang;
