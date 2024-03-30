#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    auto found = unordered_set<string>();

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            auto t = s.substr(i, j - i + 1);
            found.insert(t);
        }
    }

    cout << found.size() << endl;

    return 0;
}