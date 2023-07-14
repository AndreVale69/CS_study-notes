lista function (lista list){
    if(length(list) = 0) then return();
    else return concat(function(cdr(list)),car(list) * 3)
}