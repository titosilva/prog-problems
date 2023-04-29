#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c;

    cin >> n >> a >> b;
    int s = a + b;

    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == s) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
