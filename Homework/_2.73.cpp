#include <iostream>

using namespace std;

int saturating_add(int x, int y) {
    int w = sizeof(int) << 3;
    int ans = x + y;
    int sx = x >> (w - 1), sy = y >> (w - 1), sa = ans >> (w - 1);
    (!sx && !sy && sa) && (ans = INT_MAX);
    (sx && sy && !sa) && (ans = INT_MIN);
    return ans;
}

int main() {
    int x, int y;
    cin >> x;
    cin >> y;
    cout << saturating_add(x, y) << endl;
    return 0;
}