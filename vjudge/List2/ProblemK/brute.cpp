#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 1;
    int j = 1;
    for (int i = 1; i < 10000000; i++) {
        if (n % 2) {
            cout << "TERM " << i << " IS " << n - j + 1 << "/" << j << endl;
        } else {
            cout << "TERM " << i << " IS " << j << "/" << n - j + 1 << endl;
        }

        if (n == j) {
            n++;
            j = 1;
        } else {
            j++;
        }
    }

    return 0;
}
