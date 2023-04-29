#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int h, w;
    char tmp;
    cin >> h >> w;

    auto a = vector<vector<char>>(h, vector<char>(w));
    auto b = vector<vector<char>>(h, vector<char>(w));
    auto arows = vector<int>(h);
    auto acols = vector<int>(w);
    auto brows = vector<int>(h);
    auto bcols = vector<int>(w);

    for (int j = 0; j < h; j++) {
        auto r = a[j];

        int acc = 0;
        for (int i = 0; i < w; i++) {
            cin >> tmp;
            acc += (int)tmp;
            r[i] = tmp;
        }

        arows[j] = acc;
    }

    for (int i = 0; i < w; i++) {
        int acc = 0;
        for (int j = 0; j < h; j++) {
            acc += (int)a[j][i];
        }
        acols[i] = acc;
    }

    for (int j = 0; j < h; j++) {
        auto r = b[j];

        int acc = 0;
        for (int i = 0; i < w; i++) {
            cin >> tmp;
            acc += (int)tmp;
            r[i] = tmp;
        }

        brows[j] = acc;
    }

    for (int i = 0; i < w; i++) {
        int acc = 0;
        for (int j = 0; j < h; j++) {
            acc += (int)b[j][i];
        }

        bcols[i] = acc;
    }

    bool ok = false;
    for (int i = 0; i < w; i++) {
        ok = true;

        for (int j = 0; j < w; j++) {
            if (acols[j] != bcols[(j + i)%w]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            break;
        }
    }

    if (!ok) {
        cout << "No" << endl;
        return 0;   
    }

    for (int i = 0; i < h; i++) {
        ok = true;

        for (int j = 0; j < h; j++) {
            if (arows[j] != brows[(j + i)%h]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            break;
        }
    }

    if (!ok) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

