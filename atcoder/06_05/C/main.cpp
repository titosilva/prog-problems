#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    ll n, x, sum = 0;
    cin >> n;

    auto a = vector<ll>(n);
    for (auto &e: a) {
        cin >> e;
        sum += e;
    }

    cin >> x;

    auto replays = x / sum;
    auto k = replays * n;

    auto r = replays * sum;
    for (auto &e: a) {
        if (r > x) {
            break;
        }

        r += e;
        k++;
    }

    cout << k << endl;
}