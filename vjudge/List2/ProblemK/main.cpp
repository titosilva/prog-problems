#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    int count = 0;
    while (cin >> n) {
        if (count > 0) cout << endl;

        int row = ceil((sqrt(1 + 8 * n) - 1) / 2);
        int prev = row - 1;
        int col = n - (prev * prev + prev) / 2;

        if (row % 2) {
            cout << "TERM " << n << " IS " << row - col + 1 << "/" << col;
        } else {
            cout << "TERM " << n << " IS " << col << "/" << row - col + 1;
        }
        count++;
    }

    cout << endl;
    return 0;
}
