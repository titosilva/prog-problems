#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        auto st = stack<char>();
        
        for (auto c : s) {
            if (st.size() == 0) {
                st.push(c);
                continue;
            }

            auto top = st.top();

            auto closes = 
                (top == '(' && c == ')') ||
                (top == '[' && c == ']') ||
                (top == '{' && c == '}');

            if (closes) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.size() == 0;
    }
};

int main() {
    cout << (Solution().isValid("")? "true" : "false") << endl;
}