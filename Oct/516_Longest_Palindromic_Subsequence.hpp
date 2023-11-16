class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        auto dp = vector<vector<int>>(n, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][i] = 1;
            if (s[i - 1] == s[i]) {
                dp[i - 1][i] = 2;
            } else {
                dp[i - 1][i] = 1;
            }
        }
        for (int d = 2; d < n; d++) {
            for (int i = 0; i + d < n; i++) {
                auto st = i;
                auto ed = i + d;
                auto val = max(dp[st + 1][ed], dp[st][ed - 1]);
                if (s[st] == s[ed]) {
                    auto val2 = dp[st + 1][ed - 1] + 2;
                    if (val2 > val) {
                        val = val2;
                    }
                }
                dp[st][ed] = val;
            }
        }
        return dp[0][n - 1];
    }
};
