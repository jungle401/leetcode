class Solution {
public:
  vector<int> findBall(vector<vector<int>>& grid) {
    auto res = vector<int>(grid[0].size(), -1);
    int R = grid.size();
    if (R == 0) {
      cout << "???" << endl;
    }
    int C = grid[0].size();
    for (int ball = 0; ball < C; ball++) {
      int pos = ball; 
      for (int row = 0; row < R; row++) {
        // pos on edge
        if (pos == 0) {
          if (grid[row][pos] == -1) {
            // stuck
            break;
          }
        } 
        if (pos == C - 1) { 
          if (grid[row][pos] == 1) {
            // stuck
            break;
          }
        }
        // pos not on edge
        // judge if 'v'. If not fall to next row
        if (grid[row][pos] == 1) {
          if (grid[row][pos + 1] == 1) {
            // fall leftward
            if (row == R - 1) {
              // on last row currently
              res[ball] = pos + 1;
              break;
            }
            pos = pos + 1;
          } else {
            // stuck leftward
            break;
          }
        } else if (grid[row][pos] == -1) {
          if (grid[row][pos - 1] == -1) {
            // fall rightward
            if (row == R - 1) {
              // on last row currently
              res[ball] = pos - 1;
              break;
            }
            pos = pos - 1;
          } else {
            // stuck rightward
            break;
          }
        }
      }
    }
    return res;
  }
};
