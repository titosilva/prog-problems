// Facilita inclusão de bibliotecas
// Inclui toda a biblioteca padrão
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string S;

    cin >> N >> S;

    if (S.find('x') == string::npos && S.find('o') != string::npos) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}