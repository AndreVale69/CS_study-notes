{
    int i; int x := 3;
    int y = 2;
    void pluto(){
        return y;
    }
    void pippo(){
        int y;
        y = i;
        x = 3;
        x = pluto() + x;
        i = i + 1
    }
    while (i <= 1)
    {
        pippo();
    }
}