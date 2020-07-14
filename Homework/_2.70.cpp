#include <iostream>
using namespace std;

int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    int offset = w - n;
    return (x << offset >> offset) == x;
}

int main() {
    int n = 5;
    int x = 1;
    cout << "End with input 0" << endl;
    while ( x != 0) {
        cin >> x;
        cout << hex << fits_bits(x, n) << endl;
    }
    return 0;
}