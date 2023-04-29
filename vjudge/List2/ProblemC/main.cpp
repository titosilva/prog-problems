#include <bits/stdc++.h>

using namespace std;

vector<int> emulate(int n) {
    // cout << "Emulating...";
    string s;
    auto counts = vector<int>(10, 0);

    for (int i = 1; i <= n; i++) {
        s += to_string(i);
    }

    for (auto c: s) {
        counts[c - '0']++;
    }

    return counts;
}

vector<int> solve(int n) {
    // cout << "Solving...";
    int p10 = 100000;
    auto counts = vector<int>(10, 0);

    while (p10 > 0) {
        p10 /= 10;
        if (p10 > n || p10 == 0) {
            continue;
        }

        int x = n / p10;
        for (int j = 1; j < x; j++) {
            counts[j % 10] += p10;
        }

        int m = n % p10;
        counts[x % 10] += m + 1;
    }

    return counts;
}

void solve_and_print(int n) {
    auto counts = solve(n);
    for (int j = 0; j < 10; j++) {
        cout << counts[j];
        if (j < 9) {
            cout << " ";
        }
    }
}

void emul_and_print(int n) {
    auto counts = emulate(n);
    for (int j = 0; j < 10; j++) {
        cout << counts[j];
        if (j < 9) {
            cout << " ";
        }
    }
}

int main() {
    int d, n;

    // auto done = false;
    // n = 1;
    // while (!done) {
    //     cout << "N: " << n << endl;
    //     auto emul = emulate(n);
    //     auto counts = solve(n);
    //     cout << "Finished" << endl;
        
    //     cout << "Emul: ";
    //     for (auto c: emul) {
    //         cout << " " << c << " ";
    //     }
    //     cout << endl << "Resu: ";
    //     for (auto c: counts) {
    //         cout << " " << c << " ";
    //     }

    //     for (int i = 0; i < 10; i++) {
    //         if (emul[i] != counts[i]) {
    //             done = true;
    //             break;
    //         }   
    //     }
    //     cout << endl << endl;
    //     n++;
    // }

    // for (int i = 1; i < 10000; i++) {
    //     solve_and_print(i);
    //     // emul_and_print(i);
    //     if (i < 10000 - 1) {
    //         cout << endl;
    //     }
    // }

    cin >> d;
    for (int i = 0; i < d; i++) {
        cin >> n;

        auto counts = emulate(n);
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

    return 0;
}
