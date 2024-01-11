class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> r(n), c(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!matrix[i][j]) {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (r[i]) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (c[j]) {
                for (int i = 0; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
