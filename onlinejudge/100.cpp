#include <iostream>

using namespace std;

int cycle(int k) {
    int count = 1;

    while (k != 1) {
        if (k % 2) {
            k = 3 * k + 1;
        } else {
            k /= 2;
        }

        ++count;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);

    int i, j;

    while (cin >> i >> j) {
        int ans = 0;

        if (i > j) swap(i, j);
        
        for (int k = i; k <= j; ++k) {
            // cout << "k = " << k << " cycle = " << cycle(k) << "\n";
            ans = max(ans, cycle(k));
        }

        cout << i << " " << j << " " << ans << "\n";
    }

    return 0;
}