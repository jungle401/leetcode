class Solution {
public:
    int scoreOfString(string s) {
      auto res = 0;
      for (int i = 0; i < s.size() - 1; i++) {
        res += abs(s[i + 1] - s[i]);
      }
      return res;
    }
};
