#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef long long ll;


int main() {
    ll n, c = 0;
    cin >> n;

    ll pow = 2;
    while (n % pow == 0 && c < 64) {
        c++;
        pow <<= 1;
    }

    cout << c << endl;
    return 0;
}