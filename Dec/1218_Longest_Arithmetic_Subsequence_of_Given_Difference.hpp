class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        auto res = 1;
        auto um = unordered_map<int, int>();
        // um[i]: {end at X number, max length}
        for (int i = 0; i < arr.size(); i++) {
            auto target = arr[i] - difference;
            if (!um.contains(target)) {
                um[arr[i]] = 1;
            } else {
                um[arr[i]] = um[target] + 1;
                res = max(res, um[arr[i]]);
            }
        }
        return res;
    }
};
