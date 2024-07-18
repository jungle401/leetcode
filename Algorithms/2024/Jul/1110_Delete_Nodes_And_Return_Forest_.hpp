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
  vector<TreeNode*> res;
  unordered_set<int> td;
  void rec(TreeNode* r, TreeNode*& p, int lr, bool kept) {
    if (!r) return;
    if (td.contains(r->val)) {
      if (!lr) {
        // parent went left to here
        p->left = nullptr;
      } else {
        p->right = nullptr;
      }
      rec(r->left, r, 0, false);
      rec(r->right, r, 1, false);
    } else {
      // !td.contains(r->val)
      if (!kept) {
        res.push_back(r);
      }
      rec(r->left, r, 0, true);
      rec(r->right, r, 1, true);
    }
  }
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    for (auto i : to_delete) {
      td.insert(i);
    }
    auto d = new TreeNode();
    d->left = root;
    rec(root, d, 0, false);
    return res;
  }
};
