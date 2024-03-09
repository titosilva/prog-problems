#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    long x;
    while (cin >> x) {
        cout << (x * (x + 1) / 2) * (x * (x + 1) / 2) << endl;
    }

    return 0;
}