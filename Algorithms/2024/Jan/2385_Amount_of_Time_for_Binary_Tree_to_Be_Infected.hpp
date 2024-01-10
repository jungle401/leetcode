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
    void sq(queue<TreeNode*> q) {
        while (!q.empty()) {
            q.pop();
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        auto es = unordered_map<TreeNode*, vector<TreeNode*>>();
        auto q = queue<TreeNode*>({root});
        auto st = new TreeNode();
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto v = q.front();
                if (v->val == start) {
                    st = v;
                }
                if (v->left) {
                    es[v].push_back(v->left);
                    es[v->left].push_back(v);
                    q.push(v->left);
                }
                if (v->right) {
                    es[v].push_back(v->right);
                    es[v->right].push_back(v);
                    q.push(v->right);
                }
                q.pop();
            }
        }
        auto vist = unordered_set<TreeNode*>();
        vist.insert(st);
        while (!q.empty()) {
            q.pop();
        }
        q.push(st);
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            sq(q);
            res++;
            for (int i = 0; i < n; i++) {
                auto v = q.front();
                for (auto& w : es[v]) {
                    if (vist.contains(w)) continue;
                    q.push(w);
                    vist.insert(w);
                }
                q.pop();
            }
        }
        return res - 1;
    }
};
