#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned float_bits;

float u2f(unsigned x) {
  return *(float*) &x;
}

float_bits float_i2f(int i) {
    if (i == 0) return 0;
    unsigned bias = 0x7f;
    if (i == INT_MIN) return ((31 + bias) << 23) | 0x80000000;
    unsigned sign = (i >> 31) & 1;
    if (sign == 1) i = -i;
    int len = 32;
    while (i < (1 << len - 1)) --len;
    unsigned E = len - 1;
    unsigned exp = E + bias;
    i &= (1 << E) - 1;

    unsigned frac = 0;
    if (E <= 23) {
        frac = i << (23 - E);
        return sign << 31 | exp << 23 | frac;
    }
    frac = i >> (E - 23);
    unsigned tmp = exp << 23 | frac;
    int add = 0;
    unsigned restmask = (1 << (E - 23)) - 1;
    unsigned mid = 1 << (E - 24);
    unsigned last = frac & 1;
    if ((i & restmask) > mid) add = 1;
    else if (((i & restmask) == mid) && (last == 1)) add = 1;
    return sign << 31 | (tmp + add);
}

int main() {
    int x = 2;
    while (x != 1) {
        bool tmp = u2f(float_i2f(x)) == (float)x;
        cout << tmp;
        if (tmp == 0) {
            cout << endl << "wrong case: x = " << x << endl;
            break;
        }
        ++x;
    }
    return 0;
}