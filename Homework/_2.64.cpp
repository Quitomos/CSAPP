#include <iostream>

using namespace std;

int any_odd_one(unsigned x) {
    return (x & 0xAAAAAAAA) != 0;
}

int main() {
    unsigned x;
    x = 1;
    cout << "End with input 0" << endl;
    while (x != 0) {
        cin >> x;
        cout << any_odd_one(x);
    }
    return 0;
}