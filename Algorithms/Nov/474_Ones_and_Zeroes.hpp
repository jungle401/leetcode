class Solution {
public:
    int strs_size;
    class ZO {
        public:
        int zero_cnt = 0;
        int one_cnt = 0;
    };
    vector<ZO> zos;
    vector<vector<vector<int>>> dp;
    int rec(int idx, int m, int n) {
        if (m < 0 || n < 0) return -1;
        if (idx == strs_size) return 0;
        if (dp[idx][m][n] != -1) return dp[idx][m][n];
        auto take = 1 + rec(idx + 1, m - zos[idx].zero_cnt, n - zos[idx].one_cnt);
        auto abort = rec(idx + 1, m, n);
        return dp[idx][m][n] = max(take, abort);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        strs_size = strs.size();
        for (auto& str : strs) {
            zos.push_back(ZO());
            for (auto& c : str) {
                if (c == '0') {
                    zos.back().zero_cnt++;
                } else {
                    zos.back().one_cnt++;
                }
            }
        }
        dp = vector<vector<vector<int>>>(strs.size(),
            vector<vector<int>>(m + 1,
                vector<int>(n + 1, -1)
            )
        );
        return rec(0, m, n);
    }
};
