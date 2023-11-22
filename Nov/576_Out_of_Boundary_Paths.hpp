class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m, n;
    // at boundary
    bool ab(int r, int c) {
        // miss the case of r and c at corner(diagnally outside)
        return r == -1 || c == -1 || r == m || c == n;
    }
    int rec(int r, int c, int mv) {
        if (mv == 0) {
            return ab(r, c);
        }
        if (ab(r, c)) {
            return 1;
        }
        if (dp[r][c][mv] != -1) {
            return dp[r][c][mv];
        }
        auto res = 0;
        res += rec(r + 1, c + 0, mv - 1);
        res += rec(r - 1, c + 0, mv - 1);
        if (res > (1e9+7)) {
            res %= int(1e9+7);
        }
        res += rec(r - 0, c + 1, mv - 1);
        if (res > (1e9+7)) {
            res %= int(1e9+7);
        }
        res += rec(r - 0, c - 1, mv - 1);
        if (res > (1e9+7)) {
            res %= int(1e9+7);
        }
        return dp[r][c][mv] = res;
    }
    int findPaths(int m_, int n_, int maxMove, int startRow, int startColumn) {
        m = m_;
        n = n_;
        dp = vector<vector<vector<int>>>(m, 
            vector<vector<int>>(n,
            vector<int>(maxMove + 1, -1)));
        return rec(startRow, startColumn, maxMove);
    }
};
