class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto i = 0;
        auto j = 0;
        while (j != nums.size()) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
