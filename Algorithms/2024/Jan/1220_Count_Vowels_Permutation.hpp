class Solution {
public:
    vector<vector<int>> dp;
    int rec(int lc, int n) {
        if (dp[lc][n]) return dp[lc][n];
        if (n == 0) return 1;
        long long res = 0;
        if (lc == 0) {
            res = rec(1, n - 1);
        } else if (lc == 1) {
            res = rec(0, n - 1) + rec(2, n - 1);
        } else if (lc == 2) {
            res += rec(0, n - 1);
            res += rec(1, n - 1);
            res += rec(3, n - 1);
            res += rec(4, n - 1);
        } else if (lc == 3) {
            res =
                rec(2, n - 1) +
                rec(4, n - 1) ;
        } else {
            res = rec(0, n - 1);
        }
        return dp[lc][n] = res % static_cast<long long>(1e9 + 7);
    }
    
    int countVowelPermutation(int n) {
        dp = vector<vector<int>>(5, vector<int>(n));
        long long res = 0;
        for (int i = 0; i < 5; i++){
            res += rec(i, n - 1);
        }
        return res % static_cast<long long>(1e9 + 7);
    }
};
