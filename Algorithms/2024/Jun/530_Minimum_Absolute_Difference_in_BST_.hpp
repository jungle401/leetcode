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
    int getMinimumDifference(TreeNode* root) {
      auto stk = stack<TreeNode*>();
      auto cur = root;
      auto last_val = int(-1e5);
      auto min_diff = INT_MAX;
      while (stk.size() || cur) {
        while (cur) {
          stk.push(cur);
          cur = cur->left;
        }
        cur = stk.top();
        stk.pop();

        // traversing
        auto diff = cur->val - last_val;
        min_diff = min(min_diff, diff);
        last_val = cur->val;

        cur = cur->right;
      }
      return min_diff;
    }
};
