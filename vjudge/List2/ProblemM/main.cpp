#include <bits/stdc++.h>

using namespace std;

int get_row(int pos) {
    return floorf64(sqrtf64(pos));
}

int get_col(int pos, int row) {
    return pos - row * row;
}

double get_x(int col, int row) {
    return (col - ((row + 1) * (row + 1) - row * row - 1) / 2) * 0.5;
}

int main() {
    int n = 0, m = 7;
    while (cin >> n >> m) {

        if (n == m) {
            cout << 0 << endl;
            continue;
        }

        auto rn = get_row(n), rm = get_row(m);
        auto cn = get_col(n, rn), cm = get_col(m, rm);

        auto trih = 0.5 * sqrt(3);

        auto dh = (abs(rn - rm) - 1) * trih;

        auto delta = 0.5 * sqrt(3) / 3;

        if (rn == rm) {
            dh = ((cn % 2) - (cm % 2)) * delta;
        } else if (n < m) {
            dh += ((cn % 2) + 1) * delta + ((1 - (cm  % 2)) + 1) * delta;
        } else {
            dh += ((cm  % 2) + 1) * delta + ((1 - (cn  % 2)) + 1) * delta;
        }

        auto dx = fabs(get_x(cn, rn) - get_x(cm, rm));

        cout << fixed;
        cout << setprecision(3);
        cout << sqrt(dh * dh + dx * dx) << endl;
    }

    return 0;
}
