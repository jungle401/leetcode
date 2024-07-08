class Solution {
public:
    int findTheWinner(int n, int k) {
      auto v = vector<int>(n);
      for (int i = 0; i < v.size(); i++) {
        v[i] = i + 1;
      }
      auto p = 0;
      while (v.size() != 1) {
        p = p + k - 1;
        p = p % v.size();
        v.erase(v.begin() + p);
      }
      return v.front();
    }
};
