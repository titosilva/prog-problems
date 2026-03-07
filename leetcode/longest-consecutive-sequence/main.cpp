#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        auto s = unordered_set<int>();
        
        for (auto n : nums) {
            s.insert(n);
        }

        int largest = 0;
        for (auto n : s) {
            if (s.count(n - 1)) {
                continue;
            }

            int sz = 1;
            while (s.count(n+sz)) {
                sz++;
            }

            largest = max(largest, sz);
        }

        return largest;
    }
};