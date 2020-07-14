#include <iostream>

using namespace std;

int tsub_ok(int x, int y) {
    int w = sizeof(int) << 3;
    int ans = x - y;
    int sx = x >> (w - 1), sy = y >> (w - 1), sa = ans >> (w - 1);
    return (!sx && sy && sa) || (sx && !sy && !sa);
}

int main() {
    int x, int y;
    cin >> x;
    cin >> y;
    cout << tsub_ok(x, y) << endl;
    return 0;
}