class Solution {
public:
    void ms(vector<int>& ns, int l, int r) {
        if (l >= r) {
            return;
        }
        auto m = (l + r) / 2;
        ms(ns, l, m);
        ms(ns, m + 1, r);
        // merge
        int i = l;
        int j = m + 1;
        auto nn = vector<int>();
        while (i <= m || j <= r) {
            if (j > r || i <= m && ns[i] < ns[j]) {
                nn.push_back(ns[i]);
                i++;
            } else {
                nn.push_back(ns[j]);
                j++;
            }
        }
        // cout << l << "," << r << endl;
        for (int i = 0; i < nn.size(); i++) {
            // cout << nn[i] << ' ';
            ns[l + i] = nn[i];
        }
        // cout << endl;
    }
    vector<int> sortArray(vector<int>& nums) {
        ms(nums, 0, nums.size() - 1);
        return nums;
    }
};
