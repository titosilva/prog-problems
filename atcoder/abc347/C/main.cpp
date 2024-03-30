#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    int a, b;
    cin >> n >> a >> b;

    int k, x, mn = -1, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        k--;
        x = k % (a + b);
        if (mn < 0) mn = x;
        mn = min(x, mn);
        mx = max(x, mx);
    }

    auto m = mx - mn;

    if (m < a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}