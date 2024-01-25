class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        auto res = vector<int>();
        for (auto& i : spells) {
            auto lb = lower_bound(potions.begin(), potions.end(), i, [&success] (const long long& element, const auto& val) {
                return element * val < success;
            });
            res.push_back(distance(lb, potions.end()));
        }
        return res;
    }
};
