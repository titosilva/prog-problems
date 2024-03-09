#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    long n;
    while (cin >> n) {
        if (n < 0) break;

        if (n == 0) {
            cout << "0" << endl;
            continue;
        }
        
        string t;
        while (n > 0) {
            t += (n % 3) + '0';
            n /= 3;
        }

        reverse(t.begin(), t.end());
        cout << t << endl;
    }

    return 0;
}