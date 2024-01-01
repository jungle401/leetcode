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
    using ll = long long;
    // init
    int res = 0;
    int t;
    // states
    vector<int> path;
    ll sum = 0;
    // recursion
    void rec(TreeNode* r) {
        // state validation
        if (!r) return;
        // state update
        path.push_back(r->val);
        sum += r->val;
        // condition examine
        auto tmp_sum = sum;
        for (int i = 0; i < path.size(); i++) {
            if (tmp_sum == t) {
                res++;
            }
            tmp_sum -= path[i];
        }
        // transit
        rec(r->left);
        rec(r->right);
        // restore states
        sum -= r->val;
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        rec(root);
        return res;
    }
};
