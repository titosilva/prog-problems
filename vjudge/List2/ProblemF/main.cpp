#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    double last, curr, ratio;
    cin >> last;
    cin >> curr;

    bool need_rem = false, cant_solve = false;
    if (last == 0) {
        ratio = 0;

        if (curr != 0) {
            need_rem = true;
        } else {
            last = curr;
        }
    } else {
        ratio = curr / last;
        last = curr;
    }

    for (int i = 2; i < n; i++) {
        cin >> curr;

        if ((ratio == 0 && curr != 0) || fabs(curr / last - ratio) > 0.000001)  {
            if (need_rem) {
                cant_solve = true;
                break;
            } else {
                need_rem = true;
                continue;
            }
        }

        last = curr;
    }

    if (cant_solve) {
        cout << 2 << endl;
    } else if (need_rem) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
