class Solution {
public:
  int numberOfMatches(int n) {
    // return n - 1;
    // The following is a brutal way to solve. As some other solutions state,
    // each team should lose 1 game to complete the whole tournament,
    // so the correct answer shall be n - 1;
    auto res = 0;
    while (n != 1) {
        if (n & 1) {
          res++;
        }
        res += n / 2;
        n /= 2;
    }
    return res;
  }
};
