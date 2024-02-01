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
    void rec(TreeNode* n, int odir, int len) {
        res = max(res, len);
        if (odir == 0) {
            if (n->left) rec(n->left, 0, 1);
            if (n->right) rec(n->right, 1, len + 1);
        } else {
            if (n->left) rec(n->left, 0, len + 1);
            if (n->right) rec(n->right, 1, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if (root->left) rec(root->left, 0, 1);
        if (root->right) rec(root->right, 1, 1);
        return res;
    }
};
