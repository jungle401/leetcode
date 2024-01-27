class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto g = *max_element(candies.begin(), candies.end());
        auto res = vector<bool>(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= g) {
                res[i] = 1;
            }
        }
        return res;
    }
};
