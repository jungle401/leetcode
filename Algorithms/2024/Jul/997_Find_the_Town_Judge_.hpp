class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      auto ter = vector<int>(n + 1);
      auto ted = vector<int>(n + 1);
      for (auto& t : trust) {
        ter[t[0]]++;
        ted[t[1]]++;
      }
      auto res = -1;
      for (int i = 1; i <= n; i++) {
        if (ter[i] || ted[i] != (n - 1)) continue;
        if (res != -1) return -1;
        res = i;
      }
      return res;
    }
};
