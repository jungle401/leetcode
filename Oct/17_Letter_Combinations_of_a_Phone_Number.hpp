class Solution {
public:
    vector<string> res;
    void rec(int index, string& digits, map<char, string>& m, string& comb) {
        if (comb.size() == digits.size()) {
            res.push_back(comb);
            return;
        }
        for (auto& j : m[digits[index]]) {
            comb.push_back(j);
            rec(index + 1, digits, m, comb);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        auto m = map<char, string>();
        auto letters = string();
        for (char i = 'a'; i <= 'z'; i++) {
            letters += i;
        }
        auto offset = 0;
        for (char i = '2'; i <= '9'; i++) {
            if (i == '7' || i == '9') {
                m[i] = letters.substr(offset, 4);
                offset += 4;
            } else {
                m[i] = letters.substr(offset, 3);
                offset += 3;
            }
        }
        auto comb = string();
        rec(0, digits, m, comb);
        return res;
    }
};
