// input   output
// -9      -6
// -8      -6
// -7      -5
// -6      -4
// -5      -3
// -4      -3
// -3      -2
// -2      -1
// -1      0
// 0       0
// 1       0
// 2       1
// 3       2
// 4       3
// 5       3
// 6       4
// 7       5
// 8       6
// 9       6


#include <iostream>

using namespace std;

int threefourths(int x) {
    int offset = 3;
    int w = sizeof(int) << 3;
    (x >> (w - 1)) && (offset = 0); 
    return x - ((x + offset) >> 2);
}

int main() {
    int x;
    cin >> x;
    cout << threefourths(x) << endl;
    return 0;
}