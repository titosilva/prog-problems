#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pos;
typedef pair<pair<int, int>, int> inst;

inst find_snuke(vector<vector<char>> grid, int w, int h) {
    auto snuke = "snuke";
    int snuke_idx = 0;

    
}

int main() {
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    auto grid = vector<vector<char>>();

    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;

        auto v = vector<char>();
        for (auto c: s) {
            if ('a' <= c <= 'z') v.push_back(c);
        }

        grid.push_back(v);
    }

    auto instruct = find_snuke(grid, w, h);
    auto pos = instruct.first;
    auto dir = instruct.second;
    auto r = pos.first + 1;
    auto c = pos.second + 1;

    for (int i = 0; i < 5; i++) {
        cout << r << " " << c << endl;

        if (dir == 0) {
            c += 1;
        } else if (dir == 1) {
            r += 1;
        } else {
            c += 1;
            r += 1;
        }
    }
}