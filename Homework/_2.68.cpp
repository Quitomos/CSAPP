#include <iostream>

using namespace std;

int lower_one_mask(int n) {
    return ((1 << (n - 1)) << 1) - 1;
}

int main() {
    int x = 1;
    cout << "End with input 0" << endl;
    while ( x != 0) {
        cin >> x;
        cout << hex << lower_one_mask(x) << endl;
    }
    return 0;
}