#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    auto a = vector<int>(n);

    for (auto &ai: a) {
        cin >> ai;
    }

    int temp, x = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;

        for (auto ai: a) {
            x ^= (ai + temp);
        }
    }

    cout << x << endl;
    return 0;
}
