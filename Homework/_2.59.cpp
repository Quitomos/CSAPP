#include <iostream>

using namespace std;

long long fun(long long x, long long y) {
    long long mask = -1;
    return (x & 0xff) + (y & (mask ^ 0xff)); 
}

int main() {
    cout << hex << fun(0x89ABCDEF, 0x76543210) << endl;
    cout << "answer: 765432ef" <<endl;
    return 0;
}