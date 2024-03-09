#include <bits/stdc++.h>

using namespace std;

int main() {
    string r = "";

    for (std::string line; std::getline(std::cin, line);) {
        r = line + "\n" + r;

        if (line == "0") break;
    }

    cout << r << endl;
    return 0;
}