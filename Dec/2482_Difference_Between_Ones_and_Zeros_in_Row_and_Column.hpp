class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();
        auto onesRow = vector<int>(m);
        auto onesCol = vector<int>(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = onesRow[i] + onesCol[j] - (m - onesRow[i]) - (n - onesCol[j]);
            }
        }
        return grid;
    }
};
