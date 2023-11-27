class Solution {
public:
    int maxCoins(vector<int>& ps) {
        sort(ps.begin(), ps.end());
        int l = 0;
        int r = ps.size() - 1;
        auto res = 0;
        while (l < r) {
            res += ps[r - 1];
            l++;
            r -= 2;
        }
        return res;
    }
};
