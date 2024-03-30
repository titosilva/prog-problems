#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c;

    auto k = __builtin_popcount(c);
    auto rm = (a + b - k);

    if (rm % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    x = c;
    y = 0;

    for (int i = 0; i <= 60 && rm > 0; i++) {
        auto mask = (1LL << i);

        if ((x & mask) == 0) {
            x |= mask;
            y |= mask;
            rm -= 2;
        }
    }

    if (rm > 0) {
        cout << -1 << endl;
    } else {
        cout << x << " " << y << endl;
    }

    return 0;
}