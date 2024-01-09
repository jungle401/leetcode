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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto s1 = stack<TreeNode*>({root1});
        auto s2 = stack<TreeNode*>({root2});
        auto next_leaf = [] (stack<TreeNode*>& s) {
            if (s.empty()) return (TreeNode*) nullptr;
            while (s.top()->left || s.top()->right) {
                auto t = s.top();
                s.pop();
                if (t->left) s.push(t->left);
                if (t->right) s.push(t->right);
            }
            auto res = s.top();
            s.pop();
            return res;
        };
        while (true) {
            auto l1 = next_leaf(s1);
            auto l2 = next_leaf(s2);
            if (l1 == nullptr || l2 == nullptr) {
                return l1 == l2;
            }
            if (l1->val != l2->val) return false;
        }
        return true;
    }
};
