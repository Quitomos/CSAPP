#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned float_bits;

float u2f(unsigned x) {
  return *(float*) &x;
}

float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if (exp == 0xff && frac != 0) return f;
    else return exp << 23 | frac;
}

int main() {
    unsigned x = 1;
    while (x != 0) {
        bool tmp = (u2f(float_negate(x)) == abs(u2f(x)));
        cout << tmp;
        if (tmp == 0) {
            cout << endl << "wrong case: x = " << x << endl;
            break;
        }
        ++x;
    }
    return 0;
}