#include <iostream>

using namespace std;

int float_le(float x, float y) {
    unsigned ux = static_cast<unsigned>(x);
    unsigned uy = static_cast<unsigned>(y);
    
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (sx && !sy) || ((!sx && !sy) && (((ux << 1 >> 1) - (uy << 1 >> 1)) >> 31)) || ((sx && sy) && !(((ux << 1 >> 1) - (uy << 1 >> 1)) >> 31));
}

int main() {
    float x, y;
    cin >> x;
    cin >> y;
    cout << float_le(x, y) << endl;
    return 0;
}