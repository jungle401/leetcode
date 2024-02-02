class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto rs = 0;
        for (int i = 1; i < nums.size(); i++) rs += nums[i];
        if (!rs) return 0;
        auto ls = 0;
        for (int i = 1; i < nums.size(); i++) {
            ls += nums[i - 1];
            rs -= nums[i];
            if (ls == rs) return i;
        }
        return -1;
    }
};
