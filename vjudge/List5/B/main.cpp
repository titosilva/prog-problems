#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main() {
    ios::sync_with_stdio(false);

    ll a, b, x;
    cin >> a >> b >> x;

    auto n = (b - 2 - a) / x;
    if (a % x == 0) n++;
    if (b % x == 0) n++;

    if ((b%x) - (a%x) < 0) n++;

    cout << n << endl;
    return 0;
}