class Solution {
public:
    int minSteps(string s, string t) {
        if (s == t) return 0;
        auto m = unordered_map<char, int>();
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]--;
        }
        auto res = 0;
        for (auto& [a, b] : m) {
            if (b > 0) {
                res += b;
            }
        }
        return res;
    }
};
