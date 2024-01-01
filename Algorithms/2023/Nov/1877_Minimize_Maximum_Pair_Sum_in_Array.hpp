class Solution {
public:
    int minPairSum(vector<int>& ns) {
        sort(ns.begin(), ns.end());
        auto res = INT_MIN;
        for (int i = 0; i <= ns.size() / 2; i++) {
            auto sum = ns[i] + ns[ns.size() - i - 1];
            if (res < sum) {
                res = sum;
            }
        }
        return res;
    }
};
