class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = upper_bound(nums.begin(), nums.end(), target - 1);
        auto u = upper_bound(nums.begin(), nums.end(), target);
        auto li = int(l - nums.begin());
        auto ui = int(u - nums.begin() - 1);
        if (li > ui) return vector<int>{-1, -1};
        return vector<int>{li, ui};
    }
};
