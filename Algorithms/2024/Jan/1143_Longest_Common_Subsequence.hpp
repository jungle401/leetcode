class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto m = text1.size();
        auto n = text2.size();
        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
