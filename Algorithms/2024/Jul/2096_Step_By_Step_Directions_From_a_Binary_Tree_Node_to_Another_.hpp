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
  bool FindPath(TreeNode* r, int val, string& path) {
    // Search End
    if (!r) return false;

    // Boarder case
    if (r->val == val) return true;

    // DFS to the left
    path.push_back('L');
    if (FindPath(r->left, val, path)) {
      return true;
    }
    path.pop_back();

    // DFS to the right
    path.push_back('R');
    if (FindPath(r->right, val, path)) {
      return true;
    }
    path.pop_back();

    // Search End
    return false;
  }
  string getDirections(TreeNode* root, int startValue, int destValue) {
    // The longest common prefix of two paths lead to the
    // lowest common ancestor. Result can be inferred from
    // path after that node.
    auto start_path = string(), dest_path = string();
    FindPath(root, startValue, start_path);
    FindPath(root, destValue, dest_path);
    // To abort the common prefix for the two paths.
    int i = 0;
    while (i < start_path.size() && i < dest_path.size()) {
      if (start_path[i] != dest_path[i]) {
        break;
      }
      i++;
    }
    auto res = string(start_path.size() - i, 'U') + dest_path.substr(i);
    return res;
  }
};
