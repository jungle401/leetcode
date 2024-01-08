class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            // nums[i] points to the next zero
            // nums[j] pointes to the next non-zero after the non-zero
            if (nums[i] != 0) continue;
            if (j <= i) j = i + 1;
            while (j < nums.size() && nums[j] == 0) j++;
            if (j == nums.size()) break;
            swap(nums[i], nums[j]);
        }
    }
};
