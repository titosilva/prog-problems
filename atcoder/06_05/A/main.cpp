#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c;

    cin >> a >> b >> c;

    auto x = b / c;
    auto y = a / c;

    if (x == y) {
        if (x == 0) {
            cout << -1 << endl;
        } else if (a == b) {
            cout << a << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    
    cout << (y + 1) * c << endl;
    return 0;
}