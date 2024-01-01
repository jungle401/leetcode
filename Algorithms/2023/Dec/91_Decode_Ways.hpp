class Solution {
public:
    int numDecodings(string s) {
        // dp[i] : answer to s[0:i]

        // dp[i] +=
        //      (cond_1 ? dp[i - 1] : 0) +
        //      (cond_2 ? dp[i - 2] : 0);
        //
        // cond. 1:  0 < s[i] <= 26
        // cond. 2:  10 <= s[i-1]s[i] <= 26

        if (s[0] == '0') return 0;
        int dp1, dp2;
        dp1 = dp2 = 1;
        for (int i = 1; i < s.size(); i++) {

            // dp[i]
            auto tmp = 0;

            // condition 1
            if (s[i] != '0') {
                tmp += dp2;
            }

            // condition 2
            if (s[i - 1] == '1' ||
                (s[i - 1] == '2' && s[i] <='6')
            ) {
                tmp += dp1;
            }

            // record to dp
            dp1 = dp2;
            dp2 = tmp;

        }
        return dp2;
    }
};
