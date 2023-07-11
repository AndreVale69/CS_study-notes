$n = 12;

sub addn() {
    return $n + 30
};

sub set() {
    $n = 17;
    $n = addn();
    print $n
};

set();

print $n;