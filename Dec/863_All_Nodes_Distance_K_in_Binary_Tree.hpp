/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> edges;
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        auto q = queue<TreeNode*>();
        q.push(root);
        auto vist = unordered_map<int, int>();
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            vist[v->val] = 0;
            if (v->left) {
                edges[v->val].push_back(v->left->val);
                edges[v->left->val].push_back(v->val);
                q.push(v->left); 
            }
            if (v->right) {
                edges[v->val].push_back(v->right->val);
                edges[v->right->val].push_back(v->val);
                q.push(v->right); 
            }
        }
        auto qq = queue<int>();
        int dist = 0;
        // for (auto [v, ws] : edges) {
        //     cout << v << ":\t";
        //     for (auto w : ws) {
        //         cout << w << ' ';
        //     }
        //     cout << endl;
        // }
        qq.push(target->val);
        vist[target->val] = 1;
        while (!qq.empty()) {
            if (dist == k) {
                while (!qq.empty()) {
                    res.push_back(qq.front());
                    qq.pop();
                }
                break;
            }
            int sz = qq.size();
            for (int i = 0; i < sz; i++) {
                auto v = qq.front();
                qq.pop();
                for (auto& w : edges[v]) {
                    if (!vist[w]) {
                        qq.push(w);
                        vist[w] = 1;
                    }
                }
            }
            dist++;
        }
        return res;
    }
};
