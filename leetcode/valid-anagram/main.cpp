#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      if (s.length() != t.length()) return false;

      int counts[256];
      memset(counts, 0, 256);
      
      for (int i = 0; i < s.length(); i++) {
        counts[s[i]]++;
        counts[t[i]]--;
      }

      for (int i = 0; i < 256; i++) {
        if (counts[i] != 0) return false;
      }

      return true;
    }
};