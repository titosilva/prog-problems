#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    string s;

    cin >> n;
    cin >> s;

    int good = 0;
    bool pass = true;
    for (auto c: s) {
        if (c == 'x') {
            pass = false;
            break;
        }

        if (c == 'o') {
            good++;
        }
    }

    if (pass && good > 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}