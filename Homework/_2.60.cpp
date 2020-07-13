#include <iostream>

using namespace std;

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned mask = 0xff << (i << 3);
    int minusone = -1;
    (x &= mask ^ minusone) |= ((unsigned)b << (i << 3));
    return x;
}

int main() {
    cout << hex << replace_byte(0x12345678, 2, 0xab) << endl
        << "answer: 0x12AB5678" <<endl;
    cout << hex << replace_byte(0x12345678, 0, 0xab) <<endl
        << "answer : 0x123456ab" <<endl;
    return 0;
}