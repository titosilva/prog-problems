#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, n, i, m;

    while (cin >> n >> d) {
        cout << "[";
        i = n / d;
        m = n % d;

        cout << i << ";";

        n = d;
        d = m;
        while (n != 1) {
            i = n / d;
            m = n % d;

            cout << i;

            if (m > 0) {
                cout << ",";
            }

            n = d;
            d = m;
        }

        cout << "]" << endl;
    }

    return 0;
}
