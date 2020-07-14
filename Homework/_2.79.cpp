#include <iostream>

using namespace std;

int divide_power2(int x, int k) {
    int offset = 0;
    int w = sizeof(int) << 3;
    (x >> (w - 1)) && (offset = (1 << k) - 1);
    return (x + offset) >> k;
}

int mul3div4(int x) {
    return divide_power2(((x << 1) + x), 2);
}

int main() {
    int x;
    cin >> x;

    cout << mul3div4(x) << endl;
    return 0;
}