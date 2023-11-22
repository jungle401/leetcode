/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        auto res = string();
        stack<TreeNode*> s;
        s.push(root);
        while (s.size()) {
            auto n = s.top();
            s.pop();
            if (!n) continue;
            res += to_string(n->val);
            res.push_back(' ');
            s.push(n->right);
            s.push(n->left);
        }
        return res;
    }

    void insert(TreeNode*& r, int val) {
        if (r == nullptr) {
            r = new TreeNode(val);
            return;
        } else {
            if (val < r->val) {
                insert(r->left, val);
            } else {
                insert(r->right, val);
            }
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto ss = stringstream(data);
        int val;
        TreeNode* res = nullptr;
        while (ss >> val) {
            insert(res, val);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
