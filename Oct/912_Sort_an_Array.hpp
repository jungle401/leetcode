class Solution {
public:
    void ms(vector<int>& ns, int l, int r) {
        // if size is small, use insertion sort
        if (r - l < 30) {
            for (int i = l; i < r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    if (ns[i] > ns[j]) {
                        swap(ns[i], ns[j]);
                    }
                }
            }
            return;
        }
        if (l == r) {
            return;
        }
        auto m = (l + r) / 2;
        ms(ns, l, m);
        ms(ns, m + 1, r);
        vector<int> merged;
        auto p1 = l;
        auto p2 = m + 1;
        while (p1 <= m && p2 <= r) {
            if (ns[p1] <= ns[p2]) {
                merged.push_back(ns[p1]);
                p1++;
            } else {
                merged.push_back(ns[p2]);
                p2++;
            }
        }
        if (p1 == m + 1) {
            for (; p2 <= r; p2++) {
                merged.push_back(ns[p2]);
            }
        } else if (p2 == r + 1) {
            for (; p1 <= m; p1++) {
                merged.push_back(ns[p1]);
            }
        }
        for (int i = 0; i < merged.size(); i++) {
            ns[l + i] = merged[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        ms(nums, 0, nums.size() - 1);
        return nums;
    }
};
