class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto res = 0;
        for (auto& i : nums) {
            res = res ^ i;
        }
        return res;
    }
};
