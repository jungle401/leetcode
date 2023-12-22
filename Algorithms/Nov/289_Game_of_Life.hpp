class Solution {
public:
    vector<pair<int, int>> dxy;
    int count(int i, int j, auto& b) {
        auto res = 0;
        for (auto& d : dxy) {
            auto [x, y] = make_pair(i + d.first, j + d.second);
            if (
                x >= 0 &&
                x < b.size() &&
                y >= 0 &&
                y < b[i].size()
            ) {
                if (b[x][y] == 1 || b[x][y] == -1)
                res++;
            }
        }
        return res;
    }
    void gameOfLife(vector<vector<int>>& b) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                dxy.push_back({i, j});
            }
        }
        auto [m, n] = make_pair(b.size(), b[0].size());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto c = count(i, j, b);
                if (b[i][j] && (c < 2 || c > 3)) {
                    // currently live but would die
                    b[i][j] = -1;
                }
                if (b[i][j] == 0 && c == 3) {
                    // currently die but would live
                    b[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 2) {
                    b[i][j] = 1;
                } else if (b[i][j] == -1) {
                    b[i][j] = 0;
                }
            }
        }
    }
};
