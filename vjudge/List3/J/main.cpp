#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string conv_to_base(ll number, ll base) {
    string r;

    if (number == 0) {
        return "0";
    }

    while (number > 0) {
        auto v = (number % base);

        r += (v < 10) ? '0' + v : 'A' + v - 10;
        number /= base;
    }

    reverse(r.begin(), r.end());
    return r;
}

ll conv_from_base(string number, ll base) {
    ll r = 0;

    for (auto c: number) {
        auto u = toupper(c);
        auto v = (u >= 'A')? (u - 'A' + 10) : ((u <= '9')? (u - '0') : base * 2);

        if (v > base) return -1;

        r = r * base + v;
    }

    return r;
}


int main() {
    ios::sync_with_stdio(false);

    string line;
    while(getline(cin, line)) {
        auto s = istringstream(line);

        int src, dst;
        string number;
        s >> src >> dst >> number;

        auto v = conv_from_base(number, src);

        if (v < 0) {
            cout << number << " is an illegal base " << src << " number" << endl;
            continue;
        }

        auto r = conv_to_base(v, dst);

        cout << number << " base " << src << " = " << r << " base " << dst << endl;
    }

    return 0;
}
