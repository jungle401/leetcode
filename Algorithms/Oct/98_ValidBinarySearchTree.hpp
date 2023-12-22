#include <cstdint>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool v(TreeNode* n, long llim, long rlim) {
        if (!n) {
            return true;
        }
        if (llim >= n->val || n->val >= rlim) {
            return false;
        }
        auto lc_valid = v(n->left, llim, n->val);
        auto rc_valid = v(n->right, n->val, rlim);
        return lc_valid && rc_valid;
    }
    bool isValidBST(TreeNode* root) {
        return v(root, INT64_MIN, INT64_MAX);
    }
};
