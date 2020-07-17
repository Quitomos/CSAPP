#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned float_bits;

float u2f(unsigned x) {
  return *(float*) &x;
}

int float_f2i(float_bits uf) {
   unsigned E, M;
   unsigned sign = uf >> 31;
   unsigned exp = uf >> 23 & 0xff;
   unsigned frac = uf & ((1 << 23) - 1);
   unsigned ans;

    if (exp < 0x7f) return 0;
    if (exp >= 31 + 0x7f) return 1 << 31;
    E = exp - 0x7f;
    M = frac | (1 << 23);
    if (E > 23) ans = M << (E - 23);
    else ans = M >> (23 - E);
    if (sign) ans = -ans;
    return ans;
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