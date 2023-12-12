class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = min(nums[0], nums[1]);
        int m2 = max(nums[0], nums[1]);
        // keep m1 < m2
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > m2) {
                m1 = m2;
                m2 = nums[i];
            } else if (nums[i] > m1) {
                m1 = nums[i];
            }
        }
        return (m1 - 1) * (m2 - 1);
    }
};
