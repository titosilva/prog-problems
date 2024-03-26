#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    ll k, a = 0, b = 0;
    string as, bs;

    cin >> k;
    cin >> as >> bs;

    for (auto c: as) {
        a = a * k + (ll)(c - '0');
    }

    for (auto c: bs) {
        b = b * k + (ll)(c - '0');
    }

    cout << a * b << endl;
}