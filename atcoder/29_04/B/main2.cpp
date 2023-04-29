#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> shift_matrix(vector<vector<char>> m, int w, int h, int sw, int sh) {
    auto result = vector<vector<char>>(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            result[(i + sh) % h][(j + sw) % w] = m[i][j];
        }
    }

    return result;
}

bool cmp_matrix(vector<vector<char>> a, vector<vector<char>> b, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    auto a = vector<vector<char>>(h, vector<char>(w));
    auto b = vector<vector<char>>(h, vector<char>(w));
    
    char tmp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            a[i][j] = tmp;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            b[i][j] = tmp;
        }
    }

    for (int sh = 0; sh < h; sh++) {
        for (int sw = 0; sw < w; sw++) {
            auto shifted = shift_matrix(b, w, h, sw, sh);
            if (cmp_matrix(a, shifted, h, w)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
