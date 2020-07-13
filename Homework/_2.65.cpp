#include <iostream>

using namespace std;

int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 1;
    return x;
}

int main() {
    unsigned x = 1;
    cout << "End with input 0" << endl;
    while ( x != 0) {
        cin >> x;
        cout << odd_ones(x);
    }
    return 0;
}