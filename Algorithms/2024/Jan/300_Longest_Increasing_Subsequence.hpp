class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        auto dp = vector<int>(n);
        auto res = 0;
        for (int i = 0; i < n; i++) {
            auto mx = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) mx = max(mx, dp[j] + 1);
            }
            dp[i] = mx;
            res = max(res, mx);
        }
        return res;
    }
};
