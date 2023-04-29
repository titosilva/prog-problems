#include <bits/stdc++.h>

using namespace std;

vector<int> emulate(int n) {
    vector<int> result;

    for (int j = 1; j < n; j++) {
        int sum = 0;
        result.clear();

        for (int i = j; sum < n && i < n; i++) {
            sum += i;
            result.push_back(i);
            if (sum == n) break;
        }

        if (sum==n) break;
    }

    return result;
}


pair<int, int> solve(int n) {
    for (int i = 2; i <= ceil(sqrt(n)); i++) {
        if (n % i) continue;

        auto k = n / i;
        auto x = (k + 1) / 2;
        auto d = i;

        if (d >= x) {
            return pair<int, int>(k, d - x);
        }
    }

    return pair<int, int>(0, 0);
}

int main() {
    // for (int i = 0; i < 100; i++) {
    //     auto ans = emulate(i);

    //     cout << i << ": ";
    //     for (auto v: ans) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    int n;
    while (cin >> n) {
        if (n < 0) break;
        auto p = solve(n);
        cout << n << " = " << p.second + 1 << " + ... + " << p.first + p.second << endl;
    }
}
