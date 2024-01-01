class Solution {
public:
    int countSegments(string s) {
        auto res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            while (i < s.size() && s[i] != ' ') {
                i++;
            }
            res++;
        }
        return res;
    }
};
