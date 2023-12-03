class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        auto h = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    if (i == 0) h[i][j] = 1;
                    else h[i][j] = h[i - 1][j] + 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            sort(h[i].begin(), h[i].end());
        }
        auto res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto tmp = (n - j) * h[i][j];
                if (res < tmp) {
                    res = tmp;
                }
            }
        }
        return res;
    }
};
