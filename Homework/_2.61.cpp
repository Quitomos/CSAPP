#include <iostream>

using namespace std;

int w = sizeof(int) << 3;

int funa(int x) {
    return ((x >> (w - 1)) ^ 0) & (((x + 1) >> (w - 1)) ^ 1); 
}

int funb(int x) {
    return ((x >> (w - 1)) ^ 1) & (((x - 1) >> (w - 1)) ^ 0);
}

int func(int x) {
    x &= 0xff;
    return ((x >> 7) ^ 0) & ((((x + 1) & 0xff) >> 7) ^ 1);
}

int fund(int x) {
    return ((x >> (w - 1)) ^ 1) & (((x - (1 << (w - 8))) >> (w - 1)) ^ 0);
}

int main() {
    cout << "answer: 1 0" << endl;
    cout << funa(-1) << " " << funa(33) <<endl;
    cout << funb(0) << " " << funb(33) <<endl;
    cout << func(767) << " " << func(149) << endl;
    cout << fund(234) << " " << fund(-5847) << endl;
    return 0;
}