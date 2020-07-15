#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned float_bits;

float u2f(unsigned x) {
  return *(float*) &x;
}

float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if (exp == 0xff) return f; //NAN or 00;

    if (exp == 0) {
        int add = frac & 1;
        frac >>= 1;
        if ((frac & 1) != 0 && add == 1) ++frac;
    }
    else if (exp == 1) {
        int add = frac;
        unsigned tmp = exp << 23 | frac;
        tmp >>= 1;
        if ((tmp & 1) != 0 && add == 1) ++tmp;
        exp = tmp >> 23;
        frac = tmp & 0x7fffff;
    }
    else {
        exp -= 1;
    }
    return sign << 31 | exp << 23 | frac;
}

int main() {
    unsigned x = 1;
    while (x != 0) {
        bool tmp = (u2f(float_half(x)) == 0.5 * (u2f(x)));
        cout << tmp;
        if (tmp == 0) {
            cout << endl << "wrong case: x = " << x << endl;
            break;
        }
        ++x;
    }
    return 0;
}