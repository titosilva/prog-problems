#include <bits/stdc++.h>

using namespace std;
typedef pair<char, char> oper;
typedef vector<oper> opers;

char fr(char a, char b) {
    return (a - b) % 10;
}

char gr(char a, char b, vector<vector<char>> divs) {

}

map<pair<char, char>, char> find_divs() {
    auto divs = vector<vector<char>>(10, vector<char>(10, -1));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if ((k * j) % 10 == i) divs[i][j] = k;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    auto a = vector<char>(n);
    for (auto &e: a) {
        cin >> e;
    }

    for (char c = 0; c < 10; c++) {
        auto temp = vector<char>(a);
        temp.push_back(c);

        for (auto iter = temp.rbegin(); iter < temp.rend(); iter++) {
            auto v1 = *iter;
            auto v2 = *(iter + 1);

            
        }
    }
}

