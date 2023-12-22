class Solution {
public:
    int reverse(int x) {
        auto s = to_string(x);
        auto mx = "2147483647";
        auto mn = "_8463847412";
        if (s[0] == '-') {
            if (s.size() == 11) {
                for (int i = s.size() - 1; i > 0; i--) {
                    if (s[i] > mn[i]) return 0;
                    if (s[i] < mn[i]) break;
                }
            }
            ::reverse(s.begin() + 1, s.end());
            auto n = stoi(s);
            return n;
        } else {
            ::reverse(s.begin(), s.end());
            if (s.size() > 10) return 0;
            if (s.size() == 10) {
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] > mx[i]) return 0;
                }
            }
            auto n = stoi(s);
            return n;
        }
    }
};
