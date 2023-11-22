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
    vector<vector<int>> res;
    vector<int> state;
    void rec(TreeNode* r, int t) {
        state.push_back(r->val);
        if (!r->left && !r->right && r->val == t) {
            res.push_back(state);
        }
        if (r->left) rec(r->left, t - r->val);
        if (r->right) rec(r->right, t - r->val);
        state.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        rec(root, targetSum);
        return res;
    }
};
