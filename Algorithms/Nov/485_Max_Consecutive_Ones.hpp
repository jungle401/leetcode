class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        for (auto& c : nums) {
            if (c == 0) {
                cnt = 0;
            } else {
                cnt++;
                if (cnt > res) {
                    res = cnt;
                }
            }
        }
        return res;
    }
};
