class Solution {
public:
    int maxScore(string s) {
        int cur = (s[0] == '0');
        int c1 = 0;
        for (int i = 1; i < s.size(); i++) {
            c1 += (s[i] == '1');
        }
        cur += c1;
        auto res = cur;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                cur--;
            } else {
                cur++;
            }
            res = max(res, cur);
        }
        return res;
    }
};
