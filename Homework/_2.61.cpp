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
    int x = 0;
    cout << "End with input 1" << endl;
    while (x != 1) {
        cin >> x;
        cout << funa(x) << " " << funb(x) << " " << func(x) << " " << fund(x) << endl; 
    }
    return 0;
}