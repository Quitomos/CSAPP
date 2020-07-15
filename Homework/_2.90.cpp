#include <iostream>

using namespace std;

float u2f(unsigned x) {
  return *(float*) &x;
}

float fpwr2(int x) {
    unsigned exp, frac;
    unsigned u;

    if (x < -149) {
        exp = 0;
        frac = 0;
    }
    else if (x < -126) {
        exp = 0;
        frac = 1 << (unsigned)149 + x;
    }
    else if (x < 128) {
        exp = x + 127;
        frac = 0;
    }
    else {
        exp = -1;
        frac = 0;
    }

    u = exp << 23 | frac;
    return u2f(u);
}

int main() {
    int x;
    cin >> x;
    cout << fpwr2(x) <<endl;
    return 0;
}