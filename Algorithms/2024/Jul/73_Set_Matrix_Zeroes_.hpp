class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
      auto v = vector<int>(m.size());
      auto h = vector<int>(m[0].size());
      for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
          if (m[i][j] == 0) {
            v[i] = h[j] = 1;
          }
        }
      }
      for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
          if (v[i] || h[j]) m[i][j] = 0;
        }
      }
    }
};
