class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        auto& ns = nums;
        sort(ns.begin(), ns.end());
        auto res = vector<int>();
        int n = ns.size();
        auto ps = ns;
        for (int i = 1; i < n; i++) {
            ps[i] += ps[i - 1];
        }
        for (int i = 0; i < n; i++) {
            auto tmp = 0;
            if (i > 0) {
                tmp += (ns[i] * i - ps[i - 1]);
            }
            tmp += (ps.back() - ps[i] - ns[i] * (n - i - 1));
            res.push_back(tmp);
        }
        return res;
    }
};
