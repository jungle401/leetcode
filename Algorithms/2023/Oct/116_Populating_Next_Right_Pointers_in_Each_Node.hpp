/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;
        auto q = queue<Node*>();
        q.push(root);
        while (!q.empty()) {
            auto lv_size = q.size();
            auto f = q.front();
            if (f->left) {
                q.push(f->left);
                q.push(f->right);
            }
            q.pop();
            for (int i = 0; i < lv_size - 1; i++) {
                auto v = q.front();
                if (v->left) {
                    q.push(v->left);
                    q.push(v->right);
                }
                f->next = v;
                f = v;
                q.pop();
            }
        }
        return root;
    }
};
