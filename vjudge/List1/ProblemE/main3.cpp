#include <iostream>
#include <vector>

using namespace std;
typedef unsigned int num;

int main() {
    ios::sync_with_stdio(false);

    num N, L, U, M;

    while (cin >> N >> L >> U) {
        if (L == U) {
            cout << L << endl;
            continue;
        }

        if (L > U) {
            swap(L, U);
        }

        M = 0;
        for (int i = 31; i >= 0; i--) {
            M |= ((N >> i) & 1)? 0 : (1 << i);

            if (M > U) {
                M ^= (1 << i);
            } else if (M < L) {
                M |= (L & (1 << i));
            }
        }

        cout << M << endl;
    }

    return 0;
}