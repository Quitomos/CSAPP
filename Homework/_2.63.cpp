#include <iostream>

using namespace std;

int w = sizeof(int) << 3;
unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    xsra &= (1 << (w - k)) - 1;
    return xsra;
}

unsigned sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    unsigned mask = ~((1 << (w - k)) - 1);
    return ((~(xsrl - (1 << (w - k - 1)))) & mask) + xsrl;
}

int main() {
    unsigned x;
    int x2, k;
    cin >> x;
    cin >> k;
    cout << hex << srl(x, k) << endl;
    cin >> x2;
    cin >> k;
    cout << hex << srl(x2, k) << endl;
    return 0;
}