class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto res = 0;
        for (int i = 1; i < prices.size(); i++) {
            auto diff = prices[i] - prices[i - 1];
            res += diff > 0 ? diff : 0;
        }
        return res;
    }
};
