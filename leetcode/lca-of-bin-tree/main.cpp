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
private:
    tuple<TreeNode*, bool, bool> hasValues(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return { NULL, false, false };
        bool pf = root == p, qf = root == q;

        auto hl = hasValues(root->left, p, q);
        auto rl = get<0>(hl);
        if (rl != NULL) return hl;

        pf |= get<1>(hl);
        qf |= get<2>(hl);

        if (pf && qf) return { root, true, true };

        auto hr = hasValues(root->right, p, q);
        auto rr = get<0>(hr);
        if (rr != NULL) return hr;

        pf |= get<1>(hr);
        qf |= get<2>(hr);

        if (pf && qf) return { root, true, true };

        return { NULL, pf, qf };
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        auto h = hasValues(root, p, q);
        return get<0>(h);
    }
};