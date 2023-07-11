{
    int x = 10;
    void foo () {
        x++;
    }
    void fie () {
        int x = 0;
        foo();
    }
    fie();
}