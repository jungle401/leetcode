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
    pair<int, int> rec(TreeNode* r) {
        if (!r) return {0, 0};
        auto [ls, lnn] = rec(r->left);
        auto [rs, rnn] = rec(r->right);
        if ((r->val + ls + rs) / (lnn + rnn + 1) == r->val) {
            res++;
        }
        return make_pair(ls + rs + r->val, lnn + rnn + 1);
    }
    int averageOfSubtree(TreeNode* root) {
        if (!root) return 0;
        auto [sum, nn] = rec(root);
        return res;
    }
};
