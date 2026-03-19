#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    auto m = unordered_set<int>();

    for (auto n : nums) {
      if (m.find(n) != m.end()) return true;
      m.insert(n);
    }

    return false;
  }
};