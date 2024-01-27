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
    int maxLevelSum(TreeNode* root) {
        auto q = queue<TreeNode*>({root});
        int maxLevel = 1;
        int maxSum = root->val;
        int levelCount = 0;
        while (!q.empty()) {
            levelCount++;
            int num_cur_level = q.size();
            int sum_cur_level = 0;
            for (int i = 0; i < num_cur_level; i++) {
                auto node = q.front();
                q.pop();
                sum_cur_level += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum_cur_level > maxSum) {
                maxSum = sum_cur_level;
                maxLevel = levelCount;
            }
        }
        return maxLevel;
    }
};
