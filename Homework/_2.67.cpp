#include <iostream>

using namespace std;

int int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = 1 << 31 << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_new() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = 1 << 15 << 15 << 2;
    return set_msb && !beyond_msb;
}

int main() {
    cout << int_size_is_32 <<endl <<int_size_is_32_new << endl;
    return 0;
}