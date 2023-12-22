class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        auto edges = unordered_map<int, vector<int>>();
        for (auto& p : adjacentPairs) {
            edges[p[0]].push_back(p[1]);
            edges[p[1]].push_back(p[0]);
        }
        auto visited = unordered_set<int>();
        auto stk = stack<int>();
        for (auto& [v, ws] : edges) {
            if (ws.size() == 1) {
                stk.push(v);
                break;
            }
        }
        auto res = vector<int>();
        while (!stk.empty()) {
            auto v = stk.top();
            stk.pop();
            visited.insert(v);
            res.push_back(v);
            for (auto& w : edges[v]) {
                if (!visited.contains(w)) {
                    stk.push(w);
                }
            }
        }
        return res;
    }
};
