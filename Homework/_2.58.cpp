#include <iostream>

using namespace std;

int is_little_endian() {
    int i = 1;
    unsigned char c = *((unsigned char *) &i);
    return c == 1;
}

int main() {
    cout << is_little_endian()<<endl;
    return 0;
}