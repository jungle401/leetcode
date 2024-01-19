class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(nums.begin(), nums.end());
        auto l = 0, r = int(nums.size() - 1), res = 0;
        while (l < r) {
            auto s = nums[l] + nums[r];
            if (s == k) l++, r--, res++;
            else if (s < k) l++;
            else r--;
        }
        return res;
    }
};
