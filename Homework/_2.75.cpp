#include <iostream>

using namespace std;

int w = sizeof(int) << 3;
int signed_high_prod(int x, int y) {
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned offset, a = 0, b = 0;
    (x >> (w - 1)) && (b = y);
    (y >> (w - 1)) && (a = x);
    offset = a + b;
    return signed_high_prod(x, y) + offset;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
  uint64_t mul = (uint64_t) x * y;
  return mul >> 32;
}

int main() {
    unsigned x, y;
    cin >> x;
    cin >> y;
    cout << hex << unsigned_high_prod(x, y) << endl;
    cout << "answer:" << hex << another_unsigned_high_prod(x, y) << endl;
    return 0;
}