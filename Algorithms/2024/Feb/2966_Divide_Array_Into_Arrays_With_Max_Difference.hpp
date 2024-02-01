class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto res = vector<vector<int>>();
        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i - 2] > k) return {};
            res.push_back(vector<int>{nums.begin() + i - 2, nums.begin() + i + 1});
        }
        return res;
    }
};
