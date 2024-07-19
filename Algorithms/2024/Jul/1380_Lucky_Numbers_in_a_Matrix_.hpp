struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        // Combine hashes of first and second elements
        return std::hash<int>{}(p.first) ^ std::hash<int>{}(p.second);
    }
};
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
      auto s = unordered_set<pair<int, int>, PairHash>();
      auto m = mat.size(), n = mat[0].size();
      auto res = vector<int>();
      // search min for rows
      for (int i = 0; i < m; i++) {
        auto mn = INT_MAX, mni = 0;
        for (int j = 0; j < n; j++) {
          if (mn > mat[i][j]) {
            mn = mat[i][j];
            mni = j;
          }
        }
        s.insert(make_pair(i, mni));
      }
      // search max for cols
      for (int j = 0; j < n; j++) {
        auto mx = INT_MIN, mxi = 0;
        for (int i = 0; i < m; i++) {
          if (mx < mat[i][j]) {
            mx = mat[i][j];
            mxi = i;
          }
        }
        if (s.contains(make_pair(mxi, j))) {
          res.push_back(mat[mxi][j]);
        }
      }
      return res;
    }
};
