#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int n, m, d;

    cin >> n >> m >> d;
    auto a = vector<ll>(n);
    auto b = vector<ll>(m);

    ll temp, amax, amin, cnt = 0;
    for (auto &e: a) {
        cin >> temp;
        e = temp;
        if (cnt == 0) amin = amax = e;
        else {
            amin = min(amin, e);
            amax = max(amax, e);
        }
    }

    for (auto &e: a) {
        cin >> temp;
        e = temp;
        if (cnt == 0) amin = amax = e;
        else {
            amin = min(amin, e);
            amax = max(amax, e);
        }
    }

    return 0;
}