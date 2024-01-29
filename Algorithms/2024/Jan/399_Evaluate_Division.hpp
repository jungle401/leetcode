class Solution {
public:
    class State {
    public:
        string operand;
        double val;
    };
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        auto edges = unordered_map<string, unordered_map<string, double>>();
        for (int i = 0; i < equations.size(); i++) {
            auto& e = equations[i];
            edges[e[0]][e[1]] = values[i];
            edges[e[1]][e[0]] = 1 / values[i];
        }
        auto res = vector<double>();
        for (auto& query : queries) {
            auto& st = query[0];
            auto& ed = query[1];
            auto q = queue<State>({{st, 1}});
            auto vist = unordered_set<string>({st});
            auto found = false;
            while (!q.empty()) {
                auto v = q.front();
                q.pop();
                auto it = edges.find(v.operand);
                if (it == edges.end()) continue;
                auto i2 = it->second.find(ed);
                if (i2 != it->second.end()) {
                    res.push_back(v.val * i2->second);
                    found = true;
                    break;
                }
                for (auto& [op, val] : it->second) {
                    if (vist.contains(op)) continue;
                    vist.insert(op);
                    q.push({op, v.val * val});
                }
            }
            if (!found) res.push_back(-1);
        }
        return res;
    }
};
