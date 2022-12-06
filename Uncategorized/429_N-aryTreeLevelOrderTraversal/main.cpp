/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        auto ans = vector<vector<int>>();
        typedef pair<Node*, int> node_lv;
        auto nl_root = node_lv(root, 0);
        queue<node_lv> q;
        q.push(nl_root);
        while (!q.empty()) { 
            node_lv nl = q.front();
            q.pop();
            if (nl.first) {
                if (nl.second >= ans.size()) {
                    ans.push_back({});
                }
                ans[nl.second].push_back(nl.first->val);
                // std::cout << nl.first->val << '\t';
                // std::cout << nl.second << '\n';
                for (auto child : nl.first->children) {
                    if (child) {
                        q.push(node_lv(child, nl.second + 1));
                    }
                }
            }
        }
        // return {{0}};
        return ans;
    }
};
