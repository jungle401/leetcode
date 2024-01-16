/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> get_map(Node* node) {
        auto new_node = new Node(node->val);
        auto mp = unordered_map<int, Node*>({{node->val, new_node}});
        auto q = queue<Node*>({node});
        auto vist = unordered_set<Node*>({node});
        while (q.size()) {
            auto v = q.front();
            q.pop();
            for (auto w : v->neighbors) {
                if (vist.contains(w)) continue;
                vist.insert(w);
                mp.insert({w->val, new Node(w->val)});
                q.push(w);
            }
        }
        return mp;
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        auto mp = get_map(node);
        auto q = queue<Node*>({node});
        auto vist = unordered_set<Node*>({node});
        for (auto w : node->neighbors) {
            mp[node->val]->neighbors.push_back(mp[w->val]);
        }
        while (q.size()) {
            auto v = q.front();
            q.pop();
            for (auto w : v->neighbors) {
                if (vist.contains(w)) continue;
                vist.insert(w);
                for (auto u : w->neighbors) {
                    mp[w->val]->neighbors.push_back(mp[u->val]);
                }
                q.push(w);
            }
        }
        return mp[node->val];
    }
};
