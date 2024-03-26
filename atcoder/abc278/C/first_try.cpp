#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// This was my first try to solving this problem
// It did work for samples and initial small cases
// but received RE for other cases

// Tips: do not use unordered_set in competitive programming
// because it does not allow binary search

int main() {
    int n, q;
    cin >> n >> q;
    auto users = vector<unordered_set<int>>(n, unordered_set<int>());

    int t, a, b;
    for (int i = 0; i < q; i++) {
        cin >> t >> a >> b;
        a--;
        b--;

        if (t == 1) {
            users[a].insert(b);
        } else if (t == 2) {
            users[a].erase(b);
        } else {
            auto ans = users[a].find(b) == users[a].end() || users[b].find(a) == users[b].end();
            cout << (ans? "No" : "Yes") << endl;
        }
    }

    return 0;
}