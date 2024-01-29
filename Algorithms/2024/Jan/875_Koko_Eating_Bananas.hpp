class Solution {
public:
    bool f(vector<int>& p, int h, int x) {
        if (x == 0) return false;
        long long hours = 0;
        for (auto i : p) {
            hours += (i - 1) / x + 1;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int l = 0;
       int r = *max_element(piles.begin(), piles.end());
       while (l + 1 < r) {
           auto m = (l + r) / 2;
           if (f(piles, h, m)) r = m;
           else l = m;
       }
       return r;
    }
};
