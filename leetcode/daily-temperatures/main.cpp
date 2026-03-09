#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto st = stack<pair<int, int>>();
        
        auto r = vector<int>(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            auto t = temperatures[i];
    
            while (!st.empty() && t > st.top().first) {
                auto top = st.top();
                st.pop();
                r[top.second] = i - top.second;
            }

            st.push({ t, i });
        }

        return r;
    }
};

int main() {

}