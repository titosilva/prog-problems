#include <bits/stdc++.h>

using namespace std;

void emulate(int n, int* counts) {
    for (int i = 0; i < 10; i++) {
        counts[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        auto copy = i;
        for (int j = 0; j < 5; j++) {
            if (copy == 0) break;
            counts[copy % 10]++;
            copy /= 10;
        }
    }
}

int main() {
    int d, n;
    int counts[15];

    cin >> d;
    for (int i = 0; i < d; i++) {
        cin >> n;

        emulate(n, counts);
        for (int j = 0; j < 10; j++) {
            cout << counts[j];
            if (j < 9) {
                cout << " ";
            }
        }

        if (i < d - 1) {
            cout << endl;
        }
    }

    // for (int i = 1; i < 10000; i++) {
    //     emulate(i, counts);
    //     for (int j = 0; j < 10; j++) {
    //         cout << counts[j];
    //         if (j < 9) {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    cout << endl;
    return 0;
}
