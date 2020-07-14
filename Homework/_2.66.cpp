#include <iostream>

using namespace std;

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x = (x >> 1) +  (x & 1);
    return x;
}

int main() {
    unsigned x = 1;
    cout << "End with input 0" << endl;
    while ( x != 0) {
        cin >> x;
        cout << leftmost_one(x) << endl;
    }
    return 0;
}