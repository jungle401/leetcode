class Solution {
public:
    int n, k;
    vector<vector<int>> dp;
    int rec(int idx, int t) {
        if (idx > n || t < 0) { return 0; }
        if (idx == n && t == 0) { return 1; }
        if (dp[idx][t] != -1) { return dp[idx][t]; }
        auto res = 0;
        for (int i = 1; i <= k; i++) {
            res += rec(idx + 1, t - i);
            if (res > 1e9 + 7) { res %= int(1e9 + 7); }
        }
        return dp[idx][t] = res;
    }
    int numRollsToTarget(int n_, int k_, int target) {
        n = n_;
        k = k_;
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return rec(0, target);
    }
};
