class Solution {
public:
    int minCostClimbingStairs(vector<int>& dp) {
        int n = dp.size();
        dp.push_back(0);
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + dp[i];
        }
        return dp[n];
    }
};
