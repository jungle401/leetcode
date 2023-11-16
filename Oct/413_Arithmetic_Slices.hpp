class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        auto res = 0;
        for (int i = 0; i + 2 < n; i++) {
            auto j = i + 2;
            auto diff = nums[i + 1] - nums[i];
            while (j < n && nums[j] - nums[j - 1] == diff) {
                res += (j - i - 1);
                j++;
            }
            i = j - 2;
        }
        return res;
    }
};
