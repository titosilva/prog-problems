#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        auto v = vector<int>(n+1, 0);
        v[1] = 1;
        v[2] = 2;

        for (int i = 3; i <= n; i++) {
            v[i] = (1+v[i-1]) + (1+v[i-2]);
        }

        return v[n];
    }
};