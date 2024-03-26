#include <bits/stdc++.h>

using namespace std;

bool is_confusing(int h, int m) {
    int H = (h / 10) * 10 + m / 10;
    int M = (h % 10) * 10 + (m % 10);

    return H < 24 && M < 60;
}

int main() {
    ios::sync_with_stdio(false);
    int h, m;
    cin >> h >> m;

    while (!is_confusing(h, m)) {
        m = (m + 1) % 60;
        if (m == 0) h = (h + 1) % 24;
    }

    cout << h << " " << m;

    return 0;
}