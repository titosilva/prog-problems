#include <bits/stdc++.h>

using namespace std;

bool is_valid(char a) {
    return (
        ('a' <= a && a <= 'z') ||
        ('A' <= a && a <= 'Z') ||
        ('0' <= a && a <= '9')
    );
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    string ans, guess;
    while (cin >> n) {
        if (n < 0) break;

        cout << "Round " << n << endl;
        cin >> ans >> guess;

        auto ansc = set<char>();
        for (auto a: ans) {
            if (is_valid(a)) ansc.insert(a);
        }

        int err = 0;
        int cor = 0;
        int gn = ansc.size();
        auto guessc = set<char>();
        for (auto g: guess) {
            if (!is_valid(g)) continue;
            if (guessc.count(g)) continue;

            guessc.insert(g);

            if (!ansc.count(g)) err++;
            else cor++;

            if (cor == gn) break;
            else if (err == 7) break;
        }

        if (err >= 7) {
            cout << "You lose." << endl;
        } else if (cor >= gn) {
            cout << "You win." << endl;
        } else {
            cout << "You chickened out." << endl;
        }
    }

    return 0;
}