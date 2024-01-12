class Solution {
public:
    bool halvesAreAlike(string s) {
        auto d = 0;
        auto v = unordered_set<char>({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        for (int i = 0; i < s.size(); i++) {
            if (v.contains(s[i])) {
                if (i < s.size() / 2) d++;
                else d--;
            }
        }
        return d == 0;
    }
};
