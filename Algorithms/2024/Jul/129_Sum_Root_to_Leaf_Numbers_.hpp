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
  int rec(TreeNode* r, int cur) {
    if (!r) return 0;
    if (!r->left && !r->right) return cur * 10 + r->val;
    return rec(r->left, cur * 10 + r->val) +
           rec(r->right, cur * 10 + r->val);
  }
  int sumNumbers(TreeNode* root) {
    return rec(root, 0);
  }
};
