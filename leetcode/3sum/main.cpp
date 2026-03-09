#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        auto rs = vector<vector<int>>();
        for (int i = 0; i < nums.size(); i++) {
            auto ni = nums[i];

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                auto nj = nums[j], nk = nums[k];
                auto sum = ni + nj + nk;

                if (sum == 0) {
                    rs.push_back({ ni, nj, nk });

                    while (j < k && nj == nums[j]) j++;
                    while (j < k && nk == nums[k]) k--;
                } else if (sum < 0) {
                    j++;
                } else { 
                    k--;
                }
            }
        }

        return rs;
    }
};

int main() {

    
}