#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        auto tchars = unordered_map<char, int>();
        int remaining_chars = t.size();
        const int tsize = t.size();

        for (auto c : t) {
            tchars[c]++;
        }
        
        int pre = 0, pos = 0;
        string current = "*";
        int minpre = 0, minpos = s.size() + 1;

        while (pos < s.size()) {
            auto c = s[pos];
            auto place = tchars.find(c);
            if (place != tchars.end()) {
                place->second--;

                if (place->second >= 0) {
                    remaining_chars--;
                }
            }

            pos++;

            while (remaining_chars == 0) {
                if (pos - pre < minpos - minpre) {
                    minpos = pos;
                    minpre = pre;
                }

                auto preplace = tchars.find(s[pre]);
                if (preplace != tchars.end()) {
                    preplace->second++;

                    if (preplace->second > 0) {
                        remaining_chars++;
                    }
                }

                pre++;
            }
        }

        if (minpos - minpre == s.size() + 1) {
            return "";
        }

        return string(s.begin() + minpre, s.begin() + minpos);
    }
};

int main() {
    cout << Solution().minWindow("a", "aa") << endl;
}