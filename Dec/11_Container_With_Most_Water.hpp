class Solution {
public:
    int maxArea(vector<int>& h) {
        auto l = 0;
        auto r = h.size() - 1;
        auto res = 0ul;
        while (l < r) {
            auto tmp = min(h[l], h[r]) * (r - l);
            res = max(res, tmp);
            if (h[l] < h[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
