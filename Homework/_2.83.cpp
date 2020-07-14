#include <iostream>
#include <string>

using namespace std;

string fun(float Y, int k) {
    int ans = (Y * (1 << k)) - Y;
    string ret = to_string(ans);
    if (k <= ret.size()) return ret;
    int cont = k - ret.size();
    string tmp = "";
    while (cont--) tmp += '0';
    return tmp + ret;
}

int main() {
    cout << fun(0.2, 4) << endl;
    cout << fun(1/3.0, 4) << endl;
    return 0;
}

//5/7
//2/5
//19/63