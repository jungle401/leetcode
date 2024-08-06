class Point{
public:
  int x, y;
  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }
};

namespace std {
  template<>
  struct hash<Point> {
    size_t operator()(const Point& p) const {
      return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
    }
  };
}

class Solution {
public:
  int m, n;
  vector<vector<int>> g;
  unordered_set<Point> freshes;
  queue<Point> rotten;

  int orangesRotting(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          rotten.push(Point(i, j));
        } else if (grid[i][j] == 1) {
          freshes.insert(Point(i, j));
        }
      }
    }
    auto res = 0;
    while (rotten.size()) {
      bool new_rotten = false;
      int sz = rotten.size();
      for (int i = 0; i < sz; i++) {
        auto v = rotten.front();
        rotten.pop();
        for (auto [dx, dy] : vector<pair<int, int>>{
          {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        }) {
          auto w = Point(v.x + dx, v.y + dy);
          if (freshes.contains(w)) {
            rotten.push(w);
            freshes.erase(w);
            new_rotten = true;
          }
        }
      }
      res += new_rotten ? 1 : 0;
    }
    return freshes.size() ? -1 : res;
  }
};
