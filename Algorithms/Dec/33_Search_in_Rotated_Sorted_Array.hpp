class Solution {
public:
    int bs(vector<int>& ns, int t, int l, int r) {
        while (l <= r) {
            auto m = (l + r) / 2;
            if (ns[m] == t) {
                return m;
            } else if (ns[m] < t) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& ns, int t) {
        int l = 0;
        int n = ns.size();
        int r = n - 1;
        if (ns[l] <= ns[r]) {
            return bs(ns, t, 0, r);
        }
        while (l <= r) {
            auto m = (l + r) / 2;
            if (ns[m] > ns[m + 1]) {
                if (t >= ns[0]) {
                    return bs(ns, t, 0, m);
                } else {
                    return bs(ns, t, m + 1, n - 1);
                }
            } else if (ns[l] <= ns[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};
