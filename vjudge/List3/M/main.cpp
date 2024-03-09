#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    ll p = 2;
    auto k = 0;
    for (int i = 1; i < 50; i++) {
        p <<= 1;
        ll d = ((b % p) - (a % p)) % p;

        auto r = 0;
        for (auto j = 0; j <= d; j++) {
            auto x = ((a % p) + j) % p;

            r ^= ((x % p) >> i);
            cout << p << " " << r << endl;
        }

        k |= (r << i);
    }

    cout << k;
}
