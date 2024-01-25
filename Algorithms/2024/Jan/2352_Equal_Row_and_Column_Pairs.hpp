class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto tmp = 1;
                for (int k = 0; k < n; k++) {
                    if (grid[i][k] != grid[k][j]) {
                        tmp = 0;
                        break;
                    }
                }
                res += tmp;
            }
        }
        return res;
    }
};
