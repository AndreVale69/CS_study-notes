{
    int x = 0;
    void pippo(int n) {
        x = n + 1;
    }
    pippo(3);
    write(x);
        {
            int x = 0;
            pippo(3);
            write(x);
        }
    write(x);
}