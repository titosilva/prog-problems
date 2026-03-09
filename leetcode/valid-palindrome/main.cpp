#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution {
private: 
    char toLower(char c) {

    }
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        
        while (i <= j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main() {

}