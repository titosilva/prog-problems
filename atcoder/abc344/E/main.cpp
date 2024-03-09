#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    auto a = list<int>(n);
    auto ap = unordered_map<int, list<int>::iterator>();

    for (auto &ai : a) {
        cin >> ai;
    }

    for (auto it = a.begin(); it != a.end(); it++) {
        ap[*it] = it;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x;

        auto xit = ap[x];
        if (t == 1) {
            cin >> y;
            auto yit = a.insert(xit, y);
            *xit = y;
            *yit = x;
            ap[x] = yit;
            ap[y] = xit;
        } else {
            a.erase(xit);
            ap.erase(x);
        }
    }

    for (auto &ai : a) {
        cout << ai << " ";
    }

    cout << endl;

    return 0;
}