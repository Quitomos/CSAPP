#include <iostream>

using namespace std;

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    unsigned mask = ~((1 << (w - n - 1) << 1) - 1);
    return (x << n) + ((x & mask) >> (w - n - 1) >> 1);
}

int main() {
    unsigned x = 0x12345678;
    int n = 0;
    cout << "End with input -1" << endl;
    while (n != -1) {
        cin >> n;
        cout << hex << rotate_left(x, n) << endl;
    }
    return 0;
}