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
    vector<TreeNode*> rec(int l, int r) {
        if (l == r) return { new TreeNode(l) };
        else if (l > r) return { nullptr };
        auto res = vector<TreeNode*>();
        for (int i = l; i <= r; i++) {
            auto lts = rec(l, i - 1);
            auto rts = rec(i + 1, r);
            for (auto& lt : lts) {
                for (auto& rt : rts) {
                    auto root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    res.emplace_back(move(root));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return rec(1, n);
    }
};
