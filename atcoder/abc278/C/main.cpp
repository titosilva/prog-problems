#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    auto f = set<pair<int, int>>();

    int t, a, b;
    for (int i = 0; i < q; i++) {
        cin >> t >> a >> b;
        a--;
        b--;

        if (t == 1) {
            f.emplace(a, b);
        } else if (t == 2) {
            f.erase({a, b});
        } else {
            auto ans = f.find({a, b}) == f.end() || 
                f.find({b, a}) == f.end();
            cout << (ans? "No" : "Yes") << endl;
        }
    }

    return 0;
}