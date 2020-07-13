#include <iostream>

using namespace std;

int int_shifts_are_arithmetic() {
    int w = sizeof(int) << 3;
    int x = -1;
    x = x >> 1;
    return x == -1;
}

int main() {
    cout << int_shifts_are_arithmetic() << endl;
    return 0;
}