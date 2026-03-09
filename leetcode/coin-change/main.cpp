#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, int> dp;
    int minChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        auto place = dp.find(amount);
        if (place != dp.end()) return dp[amount];

        int minc = 100000;
        for (int i = 0; i < coins.size(); i++) {
            if (amount == coins[i]) {
                minc = 1;
                break;
            }

            auto c = minChange(coins, amount - coins[i]);

            if (c > -1) minc = min(minc, c);
        }

        minc = (minc == 100000? -1 : minc);

        dp[amount] = minc;
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp = unordered_map<int, int>();
        return minChange(coins, amount);
    }
};