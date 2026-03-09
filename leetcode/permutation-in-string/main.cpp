#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto s1ch = vector<int>(256, -1);
        auto unique_s1ch = 0;

        for (auto c : s1) {
            s1ch[c] = max(s1ch[c] + 1, 1);
            unique_s1ch += (s1ch[c] == 1);
        }

        int pre = 0, pos = s1.size() - 1;

        for (auto c : s2.substr(0, s1.size())) {
            s1ch[c]--;
            if (s1ch[c] == 0) {
                unique_s1ch--;
            }

            if (unique_s1ch == 0) {
                return true;
            }
        }

        while (pos < s2.size()) {
            pos++;
            auto pos_c = s2[pos];
            s1ch[pos_c]--;
            if (s1ch[pos_c] == 0) {
                unique_s1ch--;
            }

            auto pre_c = s2[pre];
            s1ch[pre_c]++;
            if (s1ch[pre_c] == 1) {
                unique_s1ch++;
            }
            pre++; 

            if (unique_s1ch == 0) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    cout << (Solution().checkInclusion("ab", "eidboaoo") ? "true" : "false") << endl;
    return 0;
}