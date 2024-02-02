class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        auto e = unordered_map<int, vector<int>>();
        auto oe = unordered_map<int, set<int>>();
        for (auto& c : connections) {
            e[c[0]].push_back(c[1]);
            e[c[1]].push_back(c[0]);
            oe[c[0]].insert(c[1]);
        }
        auto q = queue<int>({0});
        auto res = 0;
        auto vist = unordered_set<int>({0});
        while (q.size()) {
            auto v = q.front();
            q.pop();
            for (auto& w : e[v]) {
                if (vist.contains(w)) continue;
                if (!oe[w].contains(v)) res++;
                vist.insert(w);
                q.push(w);
            }
        }
        return res;
    }
};
