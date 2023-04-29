#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    int a[100][100];

    cin >> n;

    int temp;
    for (int i = 0; i < n; i++) {
        // a[i] = vector<int>(n);
        for (int j = 0; j < n; j++) {
            cin >> temp;
            a[i][j] = temp;
        }
    }

    int belem;
    bool rot1 = true, rot2 = true, rot3 = true, rot4 = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> belem;

            if (belem == 1) {
                continue;
            }

            if (a[i][j]) {
                rot1 = false;
            }

            if (a[n - 1 - j][i]) {
                rot2 = false;
            }

            if (a[n - 1 - i][n - 1 - j]) {
                rot3 = false;
            }

            if (a[j][n - 1 - i]) {
                rot4 = false;
            }
        }

        if (!(rot1 || rot2 || rot3 || rot4)) {
            break;
        }
    }

    if (rot1 || rot2 || rot3 || rot4) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}