#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto m = unordered_map<string, vector<string>>();

        for (auto s : strs) {
            auto copy = s;
            sort(copy.begin(), copy.end());
            m[copy].push_back(s);
        }

        auto r = vector<vector<string>>();
        for (auto const& [k, arr] : m) {
            r.push_back(arr);
        }

        return r;
    }
};

int main() {

}