#include <iostream>

using namespace std;

int divide_power2(int x, int k) {
    int offset = 0;
    int w = sizeof(int) << 3;
    (x >> (w - 1)) && (offset = (1 << k) - 1);
    return (x + offset) >> k;
}

int main() {
    int k;
    cin >> k;

    cout << divide_power2(0xA, k) << endl;
    return 0;
}