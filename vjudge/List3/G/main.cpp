#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    string a, r;
    cin >> a;

    bool done = false;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] == '0' && a[i + 1] == '1' && !done) {
            done = true;
            continue;
        }

        r += a[i];
    }

    if (done) {
        r += a[a.size() - 1];
    }

    cout << r << endl;
    return 0;
}