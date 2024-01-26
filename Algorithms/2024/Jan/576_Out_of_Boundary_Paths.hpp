class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m, n;
    int rec(int r, int c, int mv) {
        if (r < 0 || r == m || c < 0 || c == n) return mv >= 0;
        if (mv == 0) return (r < 0 || r == m || c < 0 || c == n);
        if (dp[r][c][mv] != -1) return dp[r][c][mv];
        long long res = 0;
        res += rec(r - 1, c, mv - 1);
        res += rec(r + 1, c, mv - 1);
        res += rec(r, c - 1, mv - 1);
        res += rec(r, c + 1, mv - 1);
        res = res % static_cast<long long>(1e9 + 7);
        return dp[r][c][mv] = res;
    }
    int findPaths(int m_, int n_, int maxMove, int startRow, int startColumn) {
        m = m_, n = n_;
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return rec(startRow, startColumn, maxMove);
    }
};
