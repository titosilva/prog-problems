#include <bits/stdc++.h>

// https://leetcode.com/problems/two-sum/description/

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto m = unordered_map<int, int>();

        for (int i = 0; i < nums.size(); i++) {
            auto n = nums[i];
            auto o = m.find(target-n);

            if (o == m.end()) {
                m[n] = i;
                continue;
            }

            return { i, o->second };
        }

        return {};
    }
};

int main() {

}