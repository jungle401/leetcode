class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        auto vist = vector<int>(nums.size(), -1);
        auto res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (vist[i] == -1) {
                int j = i;
                int k = 0;
                while (vist[j] == -1) {
                    vist[j] = 1;
                    j = nums[j];
                    k++;
                }
                if (res < k) {
                    res = k;
                }
            }
        }
        return res;
    }
};
