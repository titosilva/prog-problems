#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> sums;
    int n, m, l, q;
    
    cin >> n;
    auto a = vector<int>(n);

    for (auto &ai : a) {
        cin >> ai;
    }

    cin >> m;
    auto b = vector<int>(m);

    for (auto &bi : b) {
        cin >> bi;
    }

    cin >> l;
    auto c = vector<int>(l);

    for (auto &ci : c) {
        cin >> ci;
    }

    for (auto ai : a) {
        for (auto bi : b) {
            for (auto ci : c) {
                sums.insert(ai + bi + ci);
            }
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (sums.count(x)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}