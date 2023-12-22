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
    vector<int> res;
    int cur_freq = 0;
    int cur_val = -1e5 - 1;
    int max_freq = 0;
    void in(TreeNode* r) {
        if (!r) return;
        in(r->left);
        // this>
        if (r->val == cur_val) {
            cur_freq++;
        } else {
            cur_freq = 1;
        }
        if (cur_freq > max_freq) {
            res = {r->val};
            max_freq = cur_freq;
        } else if (cur_freq == max_freq) {
            res.push_back(r->val);
        }
        cur_val = r->val;
        // this<
        in(r->right);
    }
    vector<int> findMode(TreeNode* root) {
        in(root);
        return res;
    }
};
