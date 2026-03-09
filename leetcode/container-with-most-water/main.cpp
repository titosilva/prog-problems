#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int pre = 0, pos = height.size() - 1;

        auto largest = 0;
        int hpos, hpre;
        while (pos > pre) {
            hpos = height[pos]; hpre = height[pre];
            largest = max(largest, (pos - pre) * min(hpos, hpre));
            
            pos = hpos >= hpre? pos : pos - 1;
            pre = hpos < hpre? pre : pre + 1;
        }

        return largest;
    }
};

int main() {
    auto r = vector<int> { 1,8,6,2,5,4,8,3,7 };
    cout << Solution().maxArea(r) << endl;
}