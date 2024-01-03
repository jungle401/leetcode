class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicates = 1, k = 1;
        for (int i = 1; i < nums.size(); i++) {
            (nums[i] == nums[i - 1]) ? duplicates++ : duplicates = 1;
            if (duplicates <= 2) nums[k++] = nums[i];
        }
        return k;
    }
};
