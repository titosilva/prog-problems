#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto m = unordered_map<int, int>();
        for (auto n : nums) {

            auto mn = m.find(n);
            if (mn == m.end()) {
                m[n]=0;
            }

            m[n]++;
        }

        auto pq = priority_queue<pair<int, int>>();
        for (auto const &[n, cnt] : m) {
            pq.push({ cnt, n });
        }

        auto r = vector<int>();
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            r.push_back(top.second);
        }

        return r;
    }
};