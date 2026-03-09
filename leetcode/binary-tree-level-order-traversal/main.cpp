#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        auto q = queue<pair<int, TreeNode*>>();

        auto r = vector<vector<int>>();
        q.push({ 0, root });

        int level = 0;
        auto level_nodes = vector<int>();
        while (!q.empty()) {
            auto fr = q.front(); q.pop();
            root = fr.second;

            if (root == NULL) {
                continue;
            }

            if (fr.first > level) {
                r.push_back(level_nodes);
                level = fr.first;
                level_nodes = vector<int>();
            }

            level_nodes.push_back(root->val);
            q.push({level + 1, root->left});
            q.push({level + 1, root->right});
        }

        r.push_back(level_nodes);
        return r;
    }
};