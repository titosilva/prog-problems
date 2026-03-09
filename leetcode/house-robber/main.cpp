#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    vector<vector<int>> dp;

    int robRec(vector<int>&nums, int pre, int pos) {
        if (pre > pos || pre > nums.size() || pos > nums.size()) return 0;
        if (dp[pre][pos] != -1) return dp[pre][pos];

        if (pre == pos) return nums[pre];
        
        dp[pre][pos] = max(robRec(nums, pre+1, pos), robRec(nums, pre + 2, pos) + nums[pre]);
        return dp[pre][pos];
    }
public:
    int rob(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        return robRec(nums, 0, nums.size() - 1);
    }
};