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
    template <typename T>
    void log(vector<T> v) { 
        for (auto x : v) {
            std::cout << x << '\t';
        }
        std::cout << '\n';
    } 
    typedef map<int, vector<int>> depth_nodes;
    depth_nodes dn;
    void lo(TreeNode* n) {
        typedef pair<TreeNode*, int> node_level;
        queue<node_level> q;
        q.push({n, 0});
        while (!q.empty()) {
            node_level d = q.front();
            q.pop();
            if (d.first) { 
                log(vector<int>({d.first->val, d.second}));
                dn[d.second].push_back(d.first->val);
            }
            if (d.first->left)
                q.push({d.first->left, d.second + 1});
            if (d.first->right)
                q.push({d.first->right, d.second + 1});
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        lo(root);
        vector<double> res;
        for (const auto& [depth, nodes] : dn) {
            double avg = accumulate(nodes.begin(), nodes.end(), 0.0);
            avg /= nodes.size();
            res.push_back(avg);
        }
        return res;
    }
};
