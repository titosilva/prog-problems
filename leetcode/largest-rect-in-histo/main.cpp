#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int largest;
    void handleNext(int h, stack<pair<int, int>> &st) {
        int base_inc = 0;
        
        while (!st.empty()) {
            auto top = st.top();
            
            if (top.first < h) {
                break;
            }
            
            st.pop();
            base_inc+=top.second;
            largest = max(largest, top.first * base_inc);
        }

        if (h > 0) {
            largest = max(largest, h * (base_inc + 1));
            // cout << h << " " << base_inc + 1 << endl;
            st.push({ h, base_inc + 1 });
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        auto st = stack<pair<int, int>>();

        largest = 0;
        for (int i = 0; i < heights.size(); i++) {
            auto h = heights[i];
            handleNext(h, st);
        }

        handleNext(0, st);

        return largest;
    }
};

int main() {
    auto r = vector<int> { 2,1,5,6,2,3 };
    cout << Solution().largestRectangleArea(r) << endl;
    return 0;
}