class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1, mx2, mn1, mn2;
        mx1 = mx2 = INT_MIN;
        mn1 = mn2 = INT_MAX;
        // maintain mx1 > mx2, mn1 < mn2
        for (auto& i : nums) {
            if (i > mx1) {
                mx2 = mx1;
                mx1 = i;
            } else if (i > mx2) {
                mx2 = i;
            }
            if (i < mn1) {
                mn2 = mn1;
                mn1 = i;
            } else if (i < mn2) {
                mn2 = i;
            }
        }
        return mx1 * mx2 - mn1 * mn2;
    }
};
