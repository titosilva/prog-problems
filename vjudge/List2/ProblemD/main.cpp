#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    long long n = 100, k = 5;
    while (cin >> n >> k) {
        // Cada vez que são utilizados n cigarros, n / k cigarros novos são "produzidos"
        // s = n + (n / k) + (n / k)/k + ...
        // soma da PG
        cout << n + (n - 1) / (k - 1) << endl;
    }

    return 0;
}
