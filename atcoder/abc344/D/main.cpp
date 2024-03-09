#include <bits/stdc++.h>

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

string bags[100][10];
int mins[100][10];
unordered_map<pair<string, int>, int, hash_pair> costs;

int dp_rec(string t, int n, int bag) {
    if (t.length()==0) {
        return 0;
    }

    if (bag >= n) {
        return 10000000;
    }

    auto p = pair<string, int>(t, bag);
    if (costs.count(p)) {
        return costs[p];
    }

    int mind = 10000000;
    for (int i = 0; i < 10; i++) {
        string sb = bags[bag][i];
        if (sb.length() == 0) {
            break;
        }

        if (t.substr(0, sb.length()) == sb) {
            mind = min(mind, dp_rec(t.substr(sb.length()), n, bag + 1) + 1);
        }
    }

    mind = min(mind, dp_rec(t, n, bag + 1));

    costs[p] = mind;
    return mind;
}

int main() {
    memset(mins, -1, 100 * sizeof(int));
    string t;
    int n;
    cin >> t >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        for (int j = 0; j < a; j++) {
            cin >> bags[i][j];
        }
    }

    auto r = dp_rec(t, n, 0);
    if (r == 10000000) r = -1;
    cout << r << endl;

    return 0;
}