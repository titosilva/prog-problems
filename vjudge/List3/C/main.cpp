#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int x;
    string line;
    while (cin >> x) {
        getline(cin, line);
        getline(cin, line);
        auto is = istringstream(line);

        auto a = vector<int>();
        int k;
        while (is >> k) {
            a.push_back(k);
        }
        auto n = a.size() - 1;

        auto b = vector<int>(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] * (n - i);
        }

        reverse(b.begin(), b.end());
        int s = 0, p = 1;
        for (auto e: b) {
            s += p * e;
            p *= x;
        }

        cout << s << endl;
    }

    return 0;
}