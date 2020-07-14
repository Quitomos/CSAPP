#include <iostream>

using namespace std;

int funa(int k) {
    return ~((1 << k) - 1);
}

int funb(int j, int k) {
    int a = funa(j);
    int mask = (1 << (k + j)) - 1;
    return a & mask;
}

int main() {
    int k, j;
    cin >> k;
    cout << funa(k) << endl;
    cin >> k;
    cin >> j;
    cout << funb(j, k) << endl;
    return 0;
}