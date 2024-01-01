class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        auto res = string();
        auto v = vector<int>(nums.size());
        for (int i = 0; i < nums[0].size(); i++) {
            auto c0 = 0;
            auto c1 = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (v[j]) continue;
                if (nums[j][i] == '0') {
                    c0++;
                } else {
                    c1++;
                }
            }
            if (c0 < c1) {
                res += '0';
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j][i] == '1') {
                        v[j] = 1;
                    }
                }
            } else {
                res += '1';
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j][i] == '0') {
                        v[j] = 1;
                    }
                }
            }
        }
        return res;
    }
};
