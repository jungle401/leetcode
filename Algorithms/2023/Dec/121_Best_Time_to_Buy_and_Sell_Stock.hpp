class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto low = prices[0];
        auto res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (res < prices[i] - low) {
                res = prices[i] - low;
            } else if (low > prices[i]) {
                low = prices[i];
            }
        }
        return res;
    }
};
