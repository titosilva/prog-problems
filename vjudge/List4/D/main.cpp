#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    ll n, b;

    while(cin >> n >> b) {
        ll cap = (1ll << (b + 1)) - 1;
        // cout << cap << endl;
        if (n > cap) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }

    return 0;
}