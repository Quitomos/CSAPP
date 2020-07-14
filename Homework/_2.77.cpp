#include <iostream>

using namespace std;

int multi17(int x) {
    return (x << 4) + x;
}

int multim7(int x) {
    return x - (x << 3);
}

int multi60(int x) {
    return (x << 6) - (x << 2);
}

int multim112(int x) {
    return (x << 4) - (x << 7);
}

int main() {
    int x;
    cin >> x;
    cout << multi17(x) << endl
        << multim7(x) << endl
        << multi60(x) << endl
        << multim112(x) << endl;
    return 0;
}