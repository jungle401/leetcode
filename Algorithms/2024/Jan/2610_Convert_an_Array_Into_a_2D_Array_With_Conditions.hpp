class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        auto n = int(nums.size());
        auto occ = vector<int>(n + 1);
        auto res = vector<vector<int>>();
        for (int i = 0; i < n; i++) {
            auto& num = nums[i];
            occ[num]++;
            if (res.size() < occ[num]) {
                res.push_back(vector<int>{num});
            } else {
                res[occ[num] - 1].push_back(num);
            }
        }
        return res;
    }
};
