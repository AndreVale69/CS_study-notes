lista functionrc (lista list, lista res){
    if(length(list) = 0) then return res;
    else return functionrc(cdr(list), concat(car(list) * 3), res)
}

lista function (lista list){
    return functionrc(list, ());
}