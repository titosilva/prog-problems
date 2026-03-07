#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto last_seen = vector<int>(256, -1);

        int largest = 0;

        int pre = 0, pos = 0;
        while (pos < s.size()) {
            pre = max(pre, last_seen[s[pos]] + 1);
            last_seen[s[pos]] = pos;
            largest = max(largest, pos - pre + 1);
            pos++;
        }

        return largest;
    }
};