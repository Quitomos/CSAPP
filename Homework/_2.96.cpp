#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned float_bits;

float u2f(unsigned x) {
  return *(float*) &x;
}

int float_f2i(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;

    if (exp < 0x7f) return 0;
    if (exp >= 31 + 0x7f) return 0x80000000;
    unsigned E = exp - 0x7f;
    unsigned M = frac | 0x800000;
    if (M > 23) return M << (E - 23) | (sign << 31);
    return M >> (23 - E) | (sign << 31);
}

int main() {
    unsigned x = 1;
    while (x != 0) {
        bool tmp = float_f2i(x) == (int)u2f(x);
        cout << tmp;
        if (tmp == 0) {
            cout << endl << "wrong case: x = " << x << endl;
            break;
        }
        ++x;
    }
    return 0;
}