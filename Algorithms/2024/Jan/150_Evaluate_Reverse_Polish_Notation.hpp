class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        auto sk = stack<int>();
        auto operators = unordered_set<string>({"+", "-", "*", "/"});
        for (auto& t : tokens) {
            if (operators.contains(t)) {
                auto op1 = sk.top(); sk.pop();
                auto op2 = sk.top(); sk.pop();
                if (t == "+")
                    sk.push(op2 + op1);
                else if (t == "-")
                    sk.push(op2 - op1);
                else if (t == "*")
                    sk.push(op2 * op1);
                else
                    sk.push(op2 / op1);
            } else {
                sk.push(stoi(t));
            }
        }
        return sk.top();
    }
};
