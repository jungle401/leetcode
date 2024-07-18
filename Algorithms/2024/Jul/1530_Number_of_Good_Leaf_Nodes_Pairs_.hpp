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
 template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& i : v) {
    os << i << '\t';
  }
  return os;
};
class Solution {
public:
int res = 0;
int d;
  vector<int> ds(TreeNode* r) {
    if (!r) return {};
    if (!r->left && !r->right) {
      return {1};
    }
    auto lds = ds(r->left);
    auto rds = ds(r->right);
    sort(lds.begin(), lds.end());
    sort(rds.begin(), rds.end());
    bool b = false;
    for (int i = 0; i < lds.size(); i++) {
      for (int j = 0; j < rds.size(); j++) {
        if (lds[i] + rds[j] <= d) {
          res++;
        } else {
          b = true;
          break;
        }
      }
    }
    lds.insert(lds.end(), rds.begin(), rds.end());
    for (auto& i : lds) {
      i++;
    }
    return lds;
  }
    int countPairs(TreeNode* root, int distance) {
      d = distance;
      ds(root);
      return res;
    }
};
