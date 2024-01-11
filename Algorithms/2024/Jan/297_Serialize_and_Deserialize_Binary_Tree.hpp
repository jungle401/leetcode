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
        auto sk = stack<TreeNode*>({root});
        while (sk.size()) {
            auto t = sk.top();
            sk.pop();
            if (t == nullptr) res += "N ";
            else {
                res += to_string(t->val) + " ";
                sk.push(t->right);
                sk.push(t->left);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto ss = stringstream(data);
        auto s = string();
        auto res = new TreeNode();
        TreeNode** it = &res;
        auto sk = stack<TreeNode**>({it});
        while (ss >> s) {
            if (s == "N") {
                *sk.top() = nullptr;
                sk.pop();
            } else {
                *sk.top() = new TreeNode(stoi(s));
                auto t = *sk.top();
                sk.pop();
                sk.push(&(t->right));
                sk.push(&(t->left));
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
