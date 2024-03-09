#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    string r = "";
    bool found = false;
    for (auto c : s) {
        if (c == '|') {
            found = !found;
            continue;
        }

        if (found) {
            continue;
        }

        r += c;
    }

    cout << r << endl;
    return 0;
}