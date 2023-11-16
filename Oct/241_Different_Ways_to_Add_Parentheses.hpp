template<typename T>
ostream& operator<<(ostream& os, const vector<T>& objs) {
    for (auto& i : objs) {
        os << i << ' ';
    }
    return os;
}
class Solution {
public:
    int cal(int d1, int d2, char op) {
        if (op == '+') {
            return d1 + d2;
        } else if (op == '-') {
            return d1 - d2;
        } else if (op == '*') {
            return d1 * d2;
        }
        return 0;
    }
    auto is_digit(char c) {
        return '0' <= c && c <= '9';
    }
    pair<vector<int>, vector<char>> parse(string& exp) {
        auto dgts = vector<int>();
        auto ops = vector<char>();
        auto n = int(exp.size());
        for (int i = 0; i < n; i++) {
            if (is_digit(exp[i])) {
                auto digit = 0;
                if (i + 1 < n && is_digit(exp[i + 1])) {
                    digit = (exp[i] - '0') * 10 + (exp[i + 1] - '0');
                    i += 1;
                } else {
                    digit = exp[i] - '0';
                }
                dgts.push_back(digit);
            } else {
                ops.push_back(exp[i]);
            }
        }
        return make_pair(dgts, ops);
    }
    vector<int> comb(int l, int r, vector<int>& dgts, vector<char>& ops) {
        if (l == r) {
            return {dgts[l]};
        }
        auto res = vector<int>();
        for (int i = l; i < r; i++) {
            auto left = comb(l, i, dgts, ops);
            auto right = comb(i + 1, r, dgts, ops);
            for (auto& l : left) {
                for (auto& r : right) {
                    res.push_back(cal(l, r, ops[i]));
                }
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        auto [dgts, ops] = parse(expression);
        return comb(0, dgts.size() - 1, dgts, ops);
    }
};
