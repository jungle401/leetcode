/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    void pre(TreeNode* t, int mn, int mx) {
        if (!t) return;
        mn = min(mn, t->val);
        mx = max(mx, t->val);
        res = max(res, mx - mn);
        pre(t->left, mn, mx);
        pre(t->right, mn, mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        pre(root, root->val, root->val);
        return res;
    }
};
