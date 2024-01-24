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
    vector<int> occ_odd;
    int num_odds = 0;
    int res = 0;
    void rec(TreeNode* r) {
        if (occ_odd[r->val] == 1) {
            occ_odd[r->val] = 0;
            num_odds -= 1;
        } else {
            occ_odd[r->val] = 1;
            num_odds += 1;
        }
        if (!r->left && !r->right && num_odds <= 1) {
            res += 1;
        }
        if (r->left) rec(r->left);
        if (r->right) rec(r->right);
        if (occ_odd[r->val] == 1) {
            occ_odd[r->val] = 0;
            num_odds -= 1;
        } else {
            occ_odd[r->val] = 1;
            num_odds += 1;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        occ_odd.resize(10);
        if (!root) return 0;
        rec(root);
        return res;
    }
};
