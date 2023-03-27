grammar Ex4;

main : seq EOF;

seq : | alph;

alph : | 'a' alph alph_c | 'b' alph alph_c | 'c' alph alph_obb;

alph_c : 'c' alph;

alph_obb : 'a' alph | 'b' alph;
