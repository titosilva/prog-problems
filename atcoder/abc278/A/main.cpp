#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (i < k) continue;
        cout << temp << " ";
    }

    for (int i = 0; i < min(k, n); i++) {
        cout << 0 << " ";
    }

    cout << endl;
    return 0;
}