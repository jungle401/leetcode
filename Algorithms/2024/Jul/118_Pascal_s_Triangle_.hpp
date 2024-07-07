class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      if (numRows == 1) return {{1}};
      auto res = vector<vector<int>>({{1}, {1,1}});
      for (int i = 3; i <= numRows; i++) {
        res.push_back({1});
        auto& cur = res.back();
        auto& prev = res[res.size() - 2];
        auto j = 0;
        while (cur.size() < (i + 1) / 2) {
          cur.push_back(prev[j] + prev[j + 1]);
          j++;
        }
        if (i & 1) j--;
        for (; j >= 0; j--) {
          cur.push_back(cur[j]);
        }
      }
      return res;
    }
};
