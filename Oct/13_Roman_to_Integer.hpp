class Solution {
public:
    bool sub(char c1, char c2) {
        return (c1 == 'I' && c2 == 'V')
        || (c1 == 'I' && c2 == 'X')
        || (c1 == 'X' && c2 == 'L')
        || (c1 == 'X' && c2 == 'C')
        || (c1 == 'C' && c2 == 'D')
        || (c1 == 'C' && c2 == 'M');
    }
    int romanToInt(string s) {
        auto res = 0;
        auto m = map<char, int>();
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && sub(s[i], s[i + 1])) {
                res += m[s[i + 1]];
                res -= m[s[i]];
                i++;
            } else {
                res += m[s[i]];
            }
        }
        return res;
    }
};
