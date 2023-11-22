class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        auto stk = stack<int>();
        auto res = 0;
        auto dp = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
                continue;
            }
            // s[i] == ')'
            if (stk.empty()) {
                continue;
            }
            auto open = stk.top();
            dp[i] = open;
            auto len = i - stk.top() + 1;
            stk.pop();
            // see if can merge
            while (open != 0 && dp[open - 1] != -1) {
                open = dp[open - 1];
            }
            dp[i] = open;
            // update result
            auto max_cnt = i - open + 1;
            if (max_cnt > res) {
                res = max_cnt;
            }
        }
        return res;
    }
};
