class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        auto tmp = 0;
        auto res = 0;
        auto tail = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                tmp += 1;
            } else {
                if (k > 0) {
                    tmp += 1;
                    k--;
                } else {
                    while (tail < i && nums[tail] == 1) { tail++; }
                    tail += 1;
                    tmp = i - tail + 1;
                }
            }
            res = max(res, tmp);
        }
        return res;
    }
};
