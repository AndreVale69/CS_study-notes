{int a = 3; int b = 5;
void fun(){
    int z = a * b;}
void fun2(){
    int a = 4; int c = 7;
    void fun3(){
        int a = c - b;
        fun();}
    b = a + b;
    fun3();}
fun2();}