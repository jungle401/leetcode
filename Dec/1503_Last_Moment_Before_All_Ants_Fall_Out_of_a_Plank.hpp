class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        if (!l.size()) return n - *min_element(r.begin(), r.end());
        if (!r.size()) return *max_element(l.begin(), l.end());
        auto lmax = *max_element(l.begin(), l.end());
        auto rmin = *min_element(r.begin(), r.end());
        return max(lmax, n - rmin);
    }
};
