var n = 12;

function addn(){
    return n + 30;
}

function set(){
    var n = 17;
    n = addn();
    document.write(n + '\n');
}

// var n = 13;

set();

document.write(n);