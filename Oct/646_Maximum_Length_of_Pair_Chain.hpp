class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        auto dp = vector<int>(n, 1);
        sort(pairs.begin(), pairs.end(), [] (const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
        }
        return dp[pairs.size() - 1];
    }
};
