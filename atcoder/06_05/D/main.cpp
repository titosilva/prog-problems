#include <bits/stdc++.h>

using namespace std;
typedef pair<char, char> oper;
typedef vector<oper> opers;

char fr(char a, char b) {
    return (a - b) % 10;
}

char gr(char a, char b) {

}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    auto a = vector<char>(n);
    for (auto &c: a) {
        cin >> c;
    }

    map<int, opers> mult, add;

    for (char i = 0; i < 10; i++) {
        add[i] = opers();
        for (char j = 0; j < 10; j++) {
            add[i].push_back(oper(j, (i - j) % 10));
        }

        mult[i] = opers();
        for (char j = 0; j < 10; j++) {
            for (char k = 0; k < 0; k++) {
                if ((j * k) % 10 == i) mult[i].push_back(oper(j, k));
            }
        }
    }

    a.reverse();
    for (char c = 0; c < 10; c++) {
    }
}

