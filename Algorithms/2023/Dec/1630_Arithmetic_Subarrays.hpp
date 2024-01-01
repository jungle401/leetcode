class Solution {
public:
    vector<int> ns;
    bool check(int l, int r) {
        if (l == r) return false;
        auto mini = INT_MAX;
        auto maxi = INT_MIN;
        for (int i = l; i <= r; i++) {
            mini = min(mini, ns[i]);
            maxi = max(maxi, ns[i]);
        }
        if (maxi == mini) return true;
        auto diff = (maxi - mini) / (r - l);
        if (diff < 1) return false;
        auto occ = vector<int>(r - l + 1);
        for (int i = l; i <= r; i++) {
            auto offset = ns[i] - mini;
            if (offset % diff != 0) return false;
            int index = offset / diff;
            if (index < 0 || occ.size() <= index) return false;
            if (occ[index]) return false;
            occ[index] = true;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        ns = move(nums);
        vector<bool> res;
        for (int i = 0; i < l.size(); i++) {
            if (check(l[i], r[i])) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
        }
        return res;
    }
};
