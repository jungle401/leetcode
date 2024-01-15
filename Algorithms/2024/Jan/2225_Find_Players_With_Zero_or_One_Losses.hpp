class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        auto mp = unordered_map<int, int>();
        for (auto& m : matches) {
            auto w = m[0];
            auto l = m[1];
            if (!mp.contains(w)) { mp[w] = 0; }
            mp[l]++;
        }
        auto res = vector<vector<int>>(2);
        for (auto& [p, l] : mp) {
            if (l == 0) {
                res[0].push_back(p);
            } else if (l == 1) {
                res[1].push_back(p);
            }
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};
