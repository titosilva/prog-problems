#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b;

    c = a / b;
    if (a % b) {
        c += 1;
    }

    cout << c << endl;
}