#include <iostream>

using namespace std;

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    int ans = word;
    int left_shift = (3 - bytenum) << 3;
    int right_shift = 3 << 3;
    return ans << left_shift >> right_shift;
}

int main() {
    packed_t word = 0x12345678;
    int bytenum = 0;
    cout << "End with input -1";
    while (bytenum != -1) {
        cin >> bytenum;
        cout << hex << xbyte(word, bytenum) << endl;
    }
    return 0;
}