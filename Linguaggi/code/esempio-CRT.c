void main() {
    int b;
    void A() {
        int x = 0, y = 0, z = 5;
        void B() {
            int x = 3, w = 3;
            x = y + z;
        }
        void C(int a) {
            int y = 1, v = 1;
            void D() {
                int z = 2, v = 2;
                B();
                v = x + y;
            }
            D();
            x = z + y;
        }
        C(7);
    }
    A();
}