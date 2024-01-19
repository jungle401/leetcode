class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        auto m = mat.size(), n = mat[0].size();
        for (int r = m - 2; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
                auto tmp = mat[r + 1][c];
                if (c - 1 >= 0) tmp = min(tmp, mat[r + 1][c - 1]);
                if (c + 1 < n) tmp = min(tmp, mat[r + 1][c + 1]);
                mat[r][c] += tmp;
            }
        }
        auto res = INT_MAX;
        for (int c = 0; c < n; c++) {
            res = min(res, mat[0][c]);
        }
        return res;
    }
};
