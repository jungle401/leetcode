class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        auto arr = vector<int>(nums.size() + 1);
        for (auto& i : nums) {
            arr[i]++;
        }
        auto res = vector<int>(2);
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == 0) res[1] = i;
            if (arr[i] == 2) res[0] = i;
        }
        return res;
    }
};
