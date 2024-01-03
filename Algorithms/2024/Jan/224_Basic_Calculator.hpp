class Solution {
public:
    int op(char o, int a, int b) {
        if (o == '+') {
            return a + b;
        } else {
            return a - b;
        }
    }
    int cal(const string& s, int l, int r) {
        if (l >= r) return 0;
        int n = r - l;
        if (n == 0) return 0;
        int lst = r - 1;
        if (s[lst] == ')') {
            auto i = lst - 1;
            auto diff = 1;
            for (; diff != 0; i--) {
                if (s[i] == ')') {
                    diff++;
                } else if (s[i] == '(') {
                    diff--;
                }
            }
            // i at operator
            if (i == l - 1) {
                return cal(s, l + 1, r - 1);
            } else if (i == l) {
                return -cal(s, l + 2, r - 1);
            } else {
                // cout << s[i] << '\t';
                // cout << s.substr(l, i) << '\t';
                // cout << s.substr(i + 2, r - 3 - i - 2) << '\t';
                // cout << endl;
                auto op1 = cal(s, l, i);
                auto op2 = cal(s, i + 2, r - 1);
                return op(s[i], op1, op2);
            }
        } else {
            for (int i = lst; i >= l; i--) {
                if (s[i] == '+' || s[i] == '-') {
                    auto op1 = cal(s, l, i);
                    auto op2 = cal(s, i + 1, r);
                    return op(s[i], op1, op2);
                }
            }
            return stoi(s.substr(l, r - l));
        }
        return 0;
    }
    int calculate(string s) {
        auto c = string();
        for (auto& i : s) {
            if (i != ' ') c.push_back(i);
        }
        return cal(c, 0, c.size());
    }
};
