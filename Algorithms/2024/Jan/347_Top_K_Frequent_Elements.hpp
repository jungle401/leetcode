class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto m = map<int, int>();
        for (auto& i : nums) {
            m[i]++;
        }
        auto v = vector<pair<int, int>>();
        for (auto& [a, b] : m) {
            v.push_back({b, a});
        }
        sort(v.begin(), v.end(), greater());
        auto res = vector<int>();
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};
