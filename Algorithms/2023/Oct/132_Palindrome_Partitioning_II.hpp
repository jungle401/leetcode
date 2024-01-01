class Solution {
public:
    int minCut(string s) {
        // build palindrome table
        int n = s.size();
        vector<vector<int>> pt(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            pt[i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            pt[i - 1][i] = (s[i - 1] == s[i]);
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                if (pt[j + 1][j + i - 1] && s[j] == s[j + i]) {
                    pt[j][j + i] = 1;
                }
            }
        }
        // dp[i]: min cut for string[0 .. i]
        vector<int> dp(n, n);
        for (int i = 0; i < n; i++) {
            dp[i] = i;
        }
        for (int i = 1; i < n; i++) {
            if (pt[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 1; j <= i; j++) {
                    if (pt[j][i]) {
                        if (dp[i] > dp[j - 1] + 1) {
                            dp[i] = dp[j - 1] + 1;
                        }
                    }
                }
            }
        }
        return dp.back();
    }
};
