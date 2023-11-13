class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                auto sum2 = nums[l] + nums[r];
                if (sum2 < -nums[i]) {
                    l++;
                } else if (sum2 > -nums[i]) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    do {
                        l++;
                    } while (l < r && nums[l - 1] == nums[l]);
                    do {
                        r--;
                    } while (l < r && nums[r + 1] == nums[r]);
                }
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return res;
    }
};
