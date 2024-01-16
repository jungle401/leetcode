class Solution {
public:
    int findMin(vector<int>& nums) {
        auto l = 0;
        auto r = nums.size() - 1;
        while (l + 1 < r) {
            auto m = (l + r) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            } else if (nums[m] > nums[r]) {
                l = m;
            }
        }
        if (nums[l] < nums[r]) return nums[l];
        return nums[r];
    }
};
