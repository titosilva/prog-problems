#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n, q;
    auto vcount = se<int>(n, 0);

    for (int i = 0; i < q; i++) {
        int q, u, v;
        cin >> q >> u;

        if (q == 1) {
            cin >> v;
            vcount[u]++;
            vcount[v]++;
        } else {
            vcount[u] = 0;
        }

        cout << vcount.
    }

    return 0;
}