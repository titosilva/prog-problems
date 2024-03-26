#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef long long ll;


int main() {
    ll n;

    cin >> n;

    if (n == 1) {
        cout << "0" << endl;
        return 0;
    }

    n--;
    string s;

    while (n > 0) {
        auto dig = (n % 5) * 2;
        n /= 5;
        s += to_string(dig);
    }

    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}