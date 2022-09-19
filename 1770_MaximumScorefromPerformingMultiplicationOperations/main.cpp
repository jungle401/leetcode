class Solution {
public: 
    int ans(int l, int r, vector<int>& n, vector<int>& m, int mi,
           vector<vector<int>>& dp, vector<vector<bool>>& valid) { 
        int ro = r;
        r = r - (n.size() - m.size());
        if (mi >= m.size() || l > ro) {
            return 0;
        }
        // return max(n[l] * m[mi] + ans(l + 1, r, n, m, mi + 1, dp, valid),
        //            n[r] * m[mi] + ans(l, r - 1, n, m, mi + 1, dp, valid));
        if (valid[l][r]) {
            return dp[l][r];
        }
        int ldp = n[l] * m[mi] + ans(l + 1, ro, n, m, mi + 1, dp, valid);
        int rdp = n[ro] * m[mi] + ans(l, ro - 1, n, m, mi + 1, dp, valid);
        dp[l][r] = max(ldp, rdp);
        valid[l][r] = true;
        return dp[l][r];
    }
    int maximumScore(vector<int>& n, vector<int>& m) {
        int ns = n.size();
        int ms = m.size();
        vector<vector<int>> dp (ms, vector<int>(ms));
        vector<vector<bool>> valid (ms, vector<bool>(ms));
        return ans(0, ns - 1, n, m, 0, dp, valid);
        // [      ], ans[l, r] = max {}
        // st [   ]          st * m[mi] + ans[l+1, r]
        // [   ] ed          ed + m[mi] + ans[l, r-1]
    }
};
