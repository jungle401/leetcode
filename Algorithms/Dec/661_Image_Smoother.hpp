class Solution {
public:
    vector<vector<int>> img;
    int cal(int i, int j) {
        auto cnt = 0;
        auto sum = 0;
        for (int dx = -1; dx <= 1; dx++) {
            auto x = i + dx;
            if (x < 0 || x >= img.size()) continue;
            for (int dy = -1; dy <= 1; dy++) {
                auto y = j + dy;
                if (y < 0 || y >= img[0].size()) continue;
                cnt++;
                sum += img[x][y];
            }
        }
        return sum / cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img_) {
        img = move(img_);
        int m = img.size();
        int n = img[0].size();
        auto res = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = cal(i, j);
            }
        }
        return res;
    }
};
