class Solution {
public:
  int passThePillow(int n, int time) {
    auto q = time / (n - 1);
    auto r = time % (n - 1);
    if (q & 1) {
      return n - r;
    } else {
      return r + 1;
    }
  }
};
